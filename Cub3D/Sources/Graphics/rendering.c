/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:47:24 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/07 19:36:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall_vert(t_img *img, t_vert *pt, t_img *texture, double u)
{
	t_vert		pt2;
	t_vert		delta;
	t_vert		pt_text;
	unsigned int	color;

	if (texture->img_ptr)
	{
		// printf("u : %lf\n", u);
		pt_text.x = u * texture->width;
		pt_text.y = 0;
		delta.z = pt->z - pt->y;
		// printf("z : %lf\n", delta.z);
		delta.y = texture->height / delta.z;
		if (pt->y < 0)
		{
			pt_text.y += delta.y * (-pt->y);
			delta.z += pt->y;
			pt->y = 0;
		}
		while (delta.z > 0 && pt->y < img->height)
		{
			color = mlx_pxl_get(texture, pt_text.x, pt_text.y);
			if (color != TRANSPARENT)
				mlx_pxl_put(img, pt->x, pt->y, color);
			pt_text.y += delta.y;
			++pt->y;
			--delta.z;
		}
	}
	else
	{
		set_point(&pt2, pt->x, pt->z, 0);
		mlx_draw_line(img, *pt, pt2, 0x60);
	}
}

static void	draw_hit(t_img *img, t_ray *ray, t_cub *cub, int pixel_x, t_player *player)
{
	t_vert	start;
	t_vert	finish;
	double		wall_height;

	ray->dist *= cos(ray->preangle);
	ray->dist *= cub->settings->dist_feel;
	wall_height = 1 / ray->dist;
	set_point(&start, pixel_x, (1 - wall_height) * img->height / 2,  (1 + wall_height) * img->height / 2);
	set_point(&finish, pixel_x, (1 + wall_height) * img->height / 2, 0);
	if (ray->hit == DOOR)
		draw_wall_vert(img, &start, cub->mlx->ds_textures[0], ray->u);
	else if (ray->hit == DOORSIDE)
		draw_wall_vert(img, &start, cub->mlx->ds_textures[1], ray->u);
	else if (ray->hit == CUT)
		mlx_draw_line(img, start, finish, GREENISH);
	else if (ray->hit == NO)
		draw_wall_vert(img, &start, cub->mlx->textures[NO], ray->u);
	else if (ray->hit == SO)
		draw_wall_vert(img, &start, cub->mlx->textures[SO], ray->u);
	else if (ray->hit == WE)
		draw_wall_vert(img, &start, cub->mlx->textures[WE], ray->u);
	else if (ray->hit == EA)
		draw_wall_vert(img, &start, cub->mlx->textures[EA], ray->u);
	else if (ray->hit == ANIMATED)
		draw_wall_vert(img, &start, cub->map->anims->frame, ray->u);
	else if (ray->hit == CIRCLE)
		draw_wall_vert(img, &start, cub->mlx->obj_textures[POST], ray->u);
	else if (ray->hit == CUSTOM)
		draw_wall_vert(img, &start, cub->mlx->obj_textures[CUST], ray->u);
	else
		mlx_draw_line(img, start, finish, BLUEISH);
	if (cub->mlx->fc_textures[FLOOR] && cub->mlx->fc_textures[CEILLING])
		render_ground(img, cub, &finish, ray->angle, player);
}

static void	draw_hit_obj(t_img *img, t_ray *ray, t_cub *cub, int pixel_x)
{
	t_vert	start;
	double		wall_height;
	t_obj		*obj;

	obj = ray->objs;
	while (obj)
	{
		obj->dist *= cos(ray->preangle);
		obj->dist *= cub->settings->dist_feel;
		wall_height = 1 / obj->dist;
		set_point(&start, pixel_x, (1 - wall_height) * img->height / 2,  (1 + wall_height) * img->height / 2);
		if (obj->type == BARREL)
			draw_wall_vert(img, &start, cub->mlx->obj_textures[BARREL], obj->u);
		else if (obj->type == PILLAR)
			draw_wall_vert(img, &start, cub->mlx->obj_textures[PILLAR], obj->u);
		else if (obj->type == WIN)
			draw_wall_vert(img, &start, cub->mlx->obj_textures[WIN], obj->u);
		else if (obj->type == FDF)
			draw_wall_vert(img, &start, obj->fdf->canva, obj->u);
		else if (obj->type == HUMAN)
			draw_wall_vert(img, &start, cub->mlx->textures[NO], obj->u);
		obj = obj->next_ray;
	}
}

void	render_map(t_img *img, t_player *player, t_map *map, t_cub *cub)
{
	int			index;

	index = -1;
	while (++index < WIN_WIDTH)
	{
		set_point(&player->rays[index].ray.pt1, player->pos.x, player->pos.y, 0);
		player->rays[index].angle = player->direction + player->rays[index].preangle;
		player->rays[index].dist = 10000;
		if (cub->settings->fov_enable)
			player->rays[index].dist = cub->settings->fov_dist;
		set_point(&player->rays[index].ray.pt2, player->pos.x + cos(player->rays[index].angle) * player->rays[index].dist,
											player->pos.y - sin(player->rays[index].angle) * player->rays[index].dist, 0);
		player->rays[index].hit = CUT;
		player->rays[index].recurse_level = 0;
		player->rays[index].objs = 0;
		ray_walling(map->walls, &player->rays[index]);
		ray_dooring(map->doors, &player->rays[index]);
		ray_posting(map->posts, &player->rays[index]);
		ray_portaling(map->portals, &player->rays[index], cub);
		ray_objing(map->objs, player->other, &player->rays[index]);
		// printf("[%lf,%lf]-[%lf,%lf]\n", ray.ray.pt1.x, ray.ray.pt1.y, ray.ray.pt2.x, ray.ray.pt2.y);
		draw_hit(img, &player->rays[index], cub, index, player);
		draw_hit_obj(img, &player->rays[index], cub, index);
	}
}

void	clear_render(t_img *canva, unsigned int cols[2], t_cub *cub)
{
	t_vert	pt;
	double		limiter;

	pt.z = 0;
	pt.y = 0;
	limiter = canva->height;
	if (cub->mlx->fc_textures[CEILLING])
		pt.y = canva->height / 2;
	if (cub->mlx->fc_textures[FLOOR])
		limiter = canva->height / 2;
	while (pt.y < limiter)
	{
		pt.x = -1;
		while (++pt.x < canva->width)
			mlx_pxl_put(canva, pt.x, pt.y, cols[pt.y < canva->height / 2]);
		++pt.y;
	}
}
