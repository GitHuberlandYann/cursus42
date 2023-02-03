/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_follow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:58:15 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/03 19:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// printf("[%lf;%lf] -> [%lf;%lf]\n", start.x, start.y, finish.x, finish.y);
static void	draw_walls(t_img *img, t_wall *wall, t_map *map)
{
	int			index;
	t_vertice	start;
	t_vertice	finish;

	index = 0;
	while (index < 4)
	{
		if (wall->edges[index].side != CUT)
		{
			set_point_follow(&start, &wall->edges[index].pt1, map, 1);
			set_point_follow(&finish, &wall->edges[index].pt2, map, 1);
			mlx_draw_line(img, start, finish, WHITE);
		}
		++index;
	}
}

static void	draw_door(t_img *img, t_door *door, t_map *map)
{
	int			index;
	t_vertice	start;
	t_vertice	finish;

	index = 0;
	while (index < 3)
	{
		if (door->edges[index].side != CUT)
		{
			set_point_follow(&start, &door->edges[index].pt1, map, 1);
			set_point_follow(&finish, &door->edges[index].pt2, map, 1);
			mlx_draw_line(img, start, finish, WHITE);
		}
		++index;
	}
}

static void	draw_player(t_img *img, t_player *player, t_map *map)
{
	t_vertice	pt;
	t_vertice	pt2;
	t_vertice	pos_translate;

	player->size = 0.1;
	set_point(&pos_translate, map->map_width / 2,
		map->map_height - map->map_height / 10 + player->size, 0);
	pt2.x = pos_translate.x - player->size;
	while (pt2.x < pos_translate.x + player->size)
	{
		pt2.y = pos_translate.y - player->size;
		while (pt2.y < pos_translate.y + player->size)
		{
			if (get_dist(pos_translate, pt2) <= player->size)
			{
				pt.x = pt2.x * map->wall_width;
				pt.y = pt2.y * map->wall_width;
				mlx_pxl_put(img, pt, RED);
			}
			pt2.y += 0.01;
		}
		pt2.x += 0.01;
	}
	// pt.x = player->pos.x * map->wall_width;
	// pt.y = player->pos.y * map->wall_width;
	// pt2.x = (player->pos.x - cos(player->direction)) * map->wall_width;
	// pt2.y = (player->pos.y + sin(player->direction)) * map->wall_width;
	// mlx_draw_line(img, pt, pt2);
}

static void	draw_rays(t_img *img, t_player *player, t_map *map, t_settings *settings)
{
	t_vertice	intersection;
	t_vertice	start;
	t_vertice	finish;

	settings->ray_angle = player->direction - settings->fov_width / 2;
	while (settings->ray_angle < player->direction + settings->fov_width / 2)
	{
		intersection = ray_walling(player, map->walls, settings);
		intersection = ray_dooring(player, map->doors, intersection, settings);
		set_point_follow(&start, &map->player->pos, map, 1);
		set_point_follow(&finish, &intersection, map, 1);
		mlx_draw_line(img, start, finish, LIGHT_WHITE);
		settings->ray_angle += 0.001;
	}
}

void	fill_minimap_follow(t_cub *cub)
{
	t_wall	*wall;
	t_door	*door;

	wall = cub->map->walls;
	while (wall)
	{
		draw_walls(cub->mlx->minimap, wall, cub->map);
		wall = wall->next;
	}
	door = cub->map->doors;
	while (door)
	{
		draw_door(cub->mlx->minimap, door, cub->map);
		door = door->next;
	}
	draw_player(cub->mlx->minimap, cub->map->player, cub->map);
	draw_rays(cub->mlx->minimap, cub->map->player, cub->map, cub->settings);
}
