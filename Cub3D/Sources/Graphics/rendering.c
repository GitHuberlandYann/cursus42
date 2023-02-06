/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:47:24 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/06 15:24:52 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_hit(t_img *img, t_ray *ray, t_cub *cub)
{
	t_vertice	start;
	t_vertice	finish;
	double		wall_height;

	ray->dist *= cos(cub->map->player->direction - ray->angle);
	wall_height = 1 / ray->dist;
	set_point(&start, ((cub->map->player->direction + cub->settings->fov_width / 2) - ray->angle) / cub->settings->fov_width * (double)WIN_WIDTH, WIN_HEIGHT / 2 - wall_height * WIN_HEIGHT / 2, 0);
	set_point(&finish, ((cub->map->player->direction + cub->settings->fov_width / 2) - ray->angle) / cub->settings->fov_width * (double)WIN_WIDTH, WIN_HEIGHT / 2 + wall_height * WIN_HEIGHT / 2, 0);
	if (ray->hit == DOOR)
		mlx_draw_line(img, start, finish, BROWNISH);
	else if (ray->hit == CUT)
		mlx_draw_line(img, start, finish, GREENISH);
	else if (ray->hit == NO)
		mlx_draw_line(img, start, finish, 0x60);
	else if (ray->hit == SO)
		mlx_draw_line(img, start, finish, 0xa0);
	else if (ray->hit == WE)
		mlx_draw_line(img, start, finish, 0x6000);
	else if (ray->hit == EA)
		mlx_draw_line(img, start, finish, 0xa000);
	else
		mlx_draw_line(img, start, finish, BLUEISH);
}

void	render_map(t_img *img, t_player *player, t_map *map, t_cub *cub)
{
	t_ray		ray;

	set_point(&ray.ray.pt1, player->pos.x, player->pos.y, 0);
	ray.angle = player->direction - cub->settings->fov_width / 2;
	while (ray.angle < player->direction + cub->settings->fov_width / 2)
	{
		ray.dist = 10000;
		if (cub->settings->fov_enable)
			ray.dist = cub->settings->fov_dist;
		ray.hit = CUT;
		ray_walling(player, map->walls, &ray);
		ray_dooring(player, map->doors, &ray);
		ray_portaling(player, map->portals, &ray, cub);
		// printf("[%lf,%lf]-[%lf,%lf]\n", ray.ray.pt1.x, ray.ray.pt1.y, ray.ray.pt2.x, ray.ray.pt2.y);
		draw_hit(img, &ray, cub);
		ray.angle += cub->settings->fov_width / WIN_WIDTH;
	}
}

void	clear_render(t_img *canva, unsigned int cols[2])
{
	t_vertice	pt;

	pt.z = 0;
	pt.y = 0;
	while (pt.y < canva->height)
	{
		pt.x = 0;
		while (pt.x < canva->width)
		{
			mlx_pxl_put(canva, pt, cols[pt.y < canva->height / 2]);
			++pt.x;
		}
		++pt.y;
	}
}
