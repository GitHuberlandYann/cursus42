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

static void	draw_hit_human(t_img *img, t_vert *start, t_obj *obj, t_mlx *mlx)
{
	if (obj->state == SHOOTING && !obj->angle_index)
		draw_wall_vert(img, start, mlx->player_shoot[obj->frame_shoot], obj->u);
	else if (obj->state == RUNNING)
		draw_wall_vert(img, start,
			mlx->player_run[obj->angle_index][mlx->curr_frame], obj->u);
	else if (obj->state == DEAD)
		draw_wall_vert(img, start, mlx->player_death[obj->frame_shoot], obj->u);
	else
		draw_wall_vert(img, start,
			mlx->player_idle[obj->angle_index], obj->u);
}

static void	draw_hit_obj(t_img *img, t_ray *ray, t_cub *cub, int pixel_x)
{
	t_vert	start;
	double	wall_height;
	t_obj	*obj;

	obj = ray->objs;
	while (obj)
	{
		obj->dist *= cos(ray->preangle);
		obj->dist *= cub->settings->dist_feel;
		wall_height = 1 / obj->dist;
		set_point(&start, pixel_x, (1 - wall_height) * img->height / 2,
			(1 + wall_height) * img->height / 2);
		if (obj->type == BARREL)
			draw_wall_vert(img, &start, cub->mlx->obj_textures[BARREL], obj->u);
		else if (obj->type == PILLAR)
			draw_wall_vert(img, &start, cub->mlx->obj_textures[PILLAR], obj->u);
		else if (obj->type == WIN)
			draw_wall_vert(img, &start, cub->mlx->obj_textures[WIN], obj->u);
		else if (obj->type == FDF)
			draw_wall_vert(img, &start, obj->fdf->canva, obj->u);
		else if (obj->type == HUMAN)
			draw_hit_human(img, &start, obj, cub->mlx);
		obj = obj->next_ray;
	}
}

void	draw_wall_vert(t_img *img, t_vert *pt, t_img *texture, double u)
{
	t_vert			delta;
	t_vert			pt_text;
	unsigned int	color;

	if (!texture->img_ptr)
		return ;
	set_point(&pt_text, u * texture->width, 0, 0);
	delta.z = pt->z - pt->y;
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

void	render_map(t_img *img, t_player *p, t_map *map, t_cub *cub)
{
	int	index;

	precompute_floor_ceilling(p, cub->mlx->fc_textures);
	index = -1;
	while (++index < WIN_WIDTH)
	{
		set_point(&p->rays[index].ray.pt1, p->pos.x, p->pos.y, 0);
		p->rays[index].angle = p->direction + p->rays[index].preangle;
		p->rays[index].dist = 10000;
		if (cub->settings->fov_enable)
			p->rays[index].dist = cub->settings->fov_dist;
		set_point(&p->rays[index].ray.pt2,
			p->pos.x + cos(p->rays[index].angle) * p->rays[index].dist,
			p->pos.y - sin(p->rays[index].angle) * p->rays[index].dist, 0);
		p->rays[index].hit = CUT;
		p->rays[index].objs = 0;
		ray_walling(map->walls, &p->rays[index]);
		ray_dooring(map->doors, &p->rays[index]);
		ray_posting(map->posts, &p->rays[index]);
		ray_portaling(map->portals, &p->rays[index], p->other, cub);
		ray_objing(map->objs, p->other, &p->rays[index]);
		draw_hit(img, &p->rays[index], cub, p);
		draw_hit_obj(img, &p->rays[index], cub, index);
	}
}
