/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:16:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/02 09:48:18 by yhuberla         ###   ########.fr       */
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
		set_point(&start, wall->edges[NO].pt1.x * map->wall_width, wall->edges[NO].pt1.y * map->wall_height, 0);
		set_point(&finish, wall->edges[NO].pt2.x * map->wall_width, wall->edges[NO].pt2.y * map->wall_height, 0);
		mlx_draw_line(img, start, finish);
	}
	if (wall->edges[SO].side != CUT)
	{
		set_point(&start, wall->edges[SO].pt1.x * map->wall_width, wall->edges[SO].pt1.y * map->wall_height, 0);
		set_point(&finish, wall->edges[SO].pt2.x * map->wall_width, wall->edges[SO].pt2.y * map->wall_height, 0);
		mlx_draw_line(img, start, finish);
	}
	if (wall->edges[WE].side != CUT)
	{
		set_point(&start, wall->edges[WE].pt1.x * map->wall_width, wall->edges[WE].pt1.y * map->wall_height, 0);
		set_point(&finish, wall->edges[WE].pt2.x * map->wall_width, wall->edges[WE].pt2.y * map->wall_height, 0);
		mlx_draw_line(img, start, finish);
	}
	if (wall->edges[EA].side != CUT)
	{
		set_point(&start, wall->edges[EA].pt1.x * map->wall_width, wall->edges[EA].pt1.y * map->wall_height, 0);
		set_point(&finish, wall->edges[EA].pt2.x * map->wall_width, wall->edges[EA].pt2.y * map->wall_height, 0);
		mlx_draw_line(img, start, finish);
	}
}

static void	draw_player(t_img *img, t_player *player, t_map *map)
{
	t_vertice	pt;
	t_vertice	pt2;
	t_vertice	pos_translate;
	float		size;

	size = 0.1;
	pos_translate.x = player->pos.x - size * cos(player->direction);
	pos_translate.y = player->pos.y + size * sin(player->direction);
	pt2.x = pos_translate.x - size;
	while (pt2.x < pos_translate.x + size)
	{
		pt2.y = pos_translate.y - size;
		while (pt2.y < pos_translate.y + size)
		{
			if (get_dist(pos_translate, pt2) < size)
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
		angle += 0.001;
	}
}

void	fill_minimap(t_cub *cub)
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
