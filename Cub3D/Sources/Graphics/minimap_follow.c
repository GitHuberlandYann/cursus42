/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_follow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:58:15 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/02 16:19:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// printf("[%lf;%lf] -> [%lf;%lf]\n", start.x, start.y, finish.x, finish.y);
static void	draw_walls(t_img *img, t_wall *wall, t_map *map)
{
	t_vertice	start;
	t_vertice	finish;

	if (wall->edges[NO].side != CUT)
	{
		set_point_follow(&start, &wall->edges[NO].pt1, map, 1);
		set_point_follow(&finish, &wall->edges[NO].pt2, map, 1);
		mlx_draw_line(img, start, finish, WHITE);
	}
	if (wall->edges[SO].side != CUT)
	{
		set_point_follow(&start, &wall->edges[SO].pt1, map, 1);
		set_point_follow(&finish, &wall->edges[SO].pt2, map, 1);
		mlx_draw_line(img, start, finish, WHITE);
	}
	if (wall->edges[WE].side != CUT)
	{
		set_point_follow(&start, &wall->edges[WE].pt1, map, 1);
		set_point_follow(&finish, &wall->edges[WE].pt2, map, 1);
		mlx_draw_line(img, start, finish, WHITE);
	}
	if (wall->edges[EA].side != CUT)
	{
		set_point_follow(&start, &wall->edges[EA].pt1, map, 1);
		set_point_follow(&finish, &wall->edges[EA].pt2, map, 1);
		mlx_draw_line(img, start, finish, WHITE);
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
	double		angle;
	t_vertice	intersection;
	t_vertice	start;
	t_vertice	finish;

	angle = player->direction - settings->fov_width / 2;
	while (angle < player->direction + settings->fov_width / 2)
	{
		intersection = ray_walling(player, map->walls, angle, settings);
		set_point_follow(&start, &map->player->pos, map, 1);
		set_point_follow(&finish, &intersection, map, 1);
		mlx_draw_line(img, start, finish, LIGHT_WHITE);
		angle += 0.001;
	}
}

void	fill_minimap_follow(t_cub *cub)
{
	t_wall	*wall;

	wall = cub->map->walls;
	while (wall)
	{
		draw_walls(cub->mlx->minimap, wall, cub->map);
		wall = wall->next;
	}
	draw_player(cub->mlx->minimap, cub->map->player, cub->map);
	draw_rays(cub->mlx->minimap, cub->map->player, cub->map, cub->settings);
}
