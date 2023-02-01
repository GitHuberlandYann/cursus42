/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:16:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 17:46:23 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall(t_img *img, t_wall *wall, t_map *map)
{
	t_vertice	start;
	t_vertice	finish;

	// printf("\n\nnewwall :\n");
	start.x = ((double)wall->x - 0.5) * map->wall_width;
	start.y = ((double)wall->y - 0.5) * map->wall_height;
	finish.x = ((double)wall->x + 0.5) * map->wall_width;
	finish.y = ((double)wall->y - 0.5) * map->wall_height;
	// printf("[%lf;%lf] -> [%lf;%lf]\n", start.x, start.y, finish.x, finish.y);
	mlx_draw_line(img, start, finish);
	start.x = ((double)wall->x + 0.5) * map->wall_width;
	start.y = ((double)wall->y - 0.5) * map->wall_height;
	finish.x = ((double)wall->x + 0.5) * map->wall_width;
	finish.y = ((double)wall->y + 0.5) * map->wall_height;
	// printf("[%lf;%lf] -> [%lf;%lf]\n", start.x, start.y, finish.x, finish.y);
	mlx_draw_line(img, start, finish);
	start.x = ((double)wall->x + 0.5) * map->wall_width;
	start.y = ((double)wall->y + 0.5) * map->wall_height;
	finish.x = ((double)wall->x - 0.5) * map->wall_width;
	finish.y = ((double)wall->y + 0.5) * map->wall_height;
	// printf("[%lf;%lf] -> [%lf;%lf]\n", start.x, start.y, finish.x, finish.y);
	mlx_draw_line(img, start, finish);
	start.x = ((double)wall->x - 0.5) * map->wall_width;
	start.y = ((double)wall->y + 0.5) * map->wall_height;
	finish.x = ((double)wall->x - 0.5) * map->wall_width;
	finish.y = ((double)wall->y - 0.5) * map->wall_height;
	// printf("[%lf;%lf] -> [%lf;%lf]\n", start.x, start.y, finish.x, finish.y);
	mlx_draw_line(img, start, finish);
}

static void	draw_player(t_img *img, t_player *player, t_map *map)
{
	t_vertice	pt;
	double		x;
	double		y;

	x = player->x - 0.25;
	while (x < player->x + 0.25)
	{
		y = player->y - 0.25;
		while (y < player->y + 0.25)
		{
			if (sqrt(pow(player->x - x, 2) + pow(player->y - y, 2)) < 0.25)
			{
				pt.x = x * map->wall_width;
				pt.y = y * map->wall_height;
				mlx_pxl_put(img, pt);
			}
			y += 0.1;
		}
		x += 0.1;
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
}
