/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:16:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 20:04:53 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// printf("[%lf;%lf] -> [%lf;%lf]\n", start.x, start.y, finish.x, finish.y);
static void	draw_wall(t_img *img, t_wall *wall, t_map *map)
{
	t_vertice	start;
	t_vertice	finish;

	start.x = wall->north.pt1.x * map->wall_width;
	start.y = wall->north.pt1.y * map->wall_height;
	finish.x = wall->north.pt2.x * map->wall_width;
	finish.y = wall->north.pt2.y * map->wall_height;
	mlx_draw_line(img, start, finish);
	start.x = wall->south.pt1.x * map->wall_width;
	start.y = wall->south.pt1.y * map->wall_height;
	finish.x = wall->south.pt2.x * map->wall_width;
	finish.y = wall->south.pt2.y * map->wall_height;
	mlx_draw_line(img, start, finish);
	start.x = wall->west.pt1.x * map->wall_width;
	start.y = wall->west.pt1.y * map->wall_height;
	finish.x = wall->west.pt2.x * map->wall_width;
	finish.y = wall->west.pt2.y * map->wall_height;
	mlx_draw_line(img, start, finish);
	start.x = wall->east.pt1.x * map->wall_width;
	start.y = wall->east.pt1.y * map->wall_height;
	finish.x = wall->east.pt2.x * map->wall_width;
	finish.y = wall->east.pt2.y * map->wall_height;
	mlx_draw_line(img, start, finish);
}

static void	draw_player(t_img *img, t_player *player, t_map *map)
{
	t_vertice	pt;
	t_vertice	pt2;

	pt2.x = player->pos.x - 0.25;
	while (pt2.x < player->pos.x + 0.25)
	{
		pt2.y = player->pos.y - 0.25;
		while (pt2.y < player->pos.y + 0.25)
		{
			if (get_dist(player->pos, pt2) < 0.25)
			{
				pt.x = pt2.x * map->wall_width;
				pt.y = pt2.y * map->wall_height;
				mlx_pxl_put(img, pt, 0xff0000);
			}
			pt2.y += 0.01;
		}
		pt2.x += 0.01;
	}
	// pt.x = player->pos.x * map->wall_width;
	// pt.y = player->pos.y * map->wall_height;
	// pt2.x = (player->pos.x - cos(player->direction)) * map->wall_width;
	// pt2.y = (player->pos.y + sin(player->direction)) * map->wall_height;
	// mlx_draw_line(img, pt, pt2);
}

static void	draw_rays(t_img *img, t_player *player, t_map *map, t_settings *settings)
{
	double		angle;
	t_vertice	intersection;
	t_vertice	play;

	angle = player->direction - settings->fov_width / 2;
	while (angle < player->direction + settings->fov_width / 2)
	{
		intersection = ray_walling(player, map->walls, angle);
		intersection.x *= map->wall_width;
		intersection.y *= map->wall_height;
		play.x = player->pos.x * map->wall_width;
		play.y = player->pos.y * map->wall_height;
		mlx_draw_line(img, play, intersection);
		angle += 0.005;
	}
}

void	fill_minimap(t_cub *cub)
{
	t_wall	*wall;

	wall = cub->map->walls;
	while (wall)
	{
		draw_wall(cub->mlx->minimap, wall, cub->map);
		wall = wall->next;
	}
	draw_player(cub->mlx->minimap, cub->map->player, cub->map);
	draw_rays(cub->mlx->minimap, cub->map->player, cub->map, cub->settings);
}
