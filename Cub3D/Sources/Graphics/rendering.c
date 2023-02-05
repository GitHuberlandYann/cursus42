/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:47:24 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/05 18:27:43 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_hit(t_img *img, t_ray *ray, t_cub *cub)
{
	t_vertice	start;
	t_vertice	finish;

	set_point(&start, ((cub->map->player->direction + cub->settings->fov_width / 2) - ray->angle) / cub->settings->fov_width * WIN_WIDTH, ray->dist * 20, 0);
	set_point(&finish, ((cub->map->player->direction + cub->settings->fov_width / 2) - ray->angle) / cub->settings->fov_width * WIN_WIDTH, WIN_HEIGHT - ray->dist * 20, 0);
		if (ray->hit == DOOR)
			mlx_draw_line(img, start, finish, BROWNISH);
		else if (ray->hit == CUT)
			mlx_draw_line(img, start, finish, GREENISH);
		else
			mlx_draw_line(img, start, finish, LIGHT_WHITE);

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
		ray.angle += 0.001;
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
