/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:52:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/13 11:59:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_walls(t_img *img, t_wall *wall, t_map *map, t_settings *settings)
{
	int			index;
	t_vertice	start;
	t_vertice	finish;

	index = 0;
	while (index < 4)
	{
		if (wall->edges[index].side != CUT)
		{
			if (in_circle(&wall->edges[index].pt1, map->player->pos.x, map->player->pos.y, MAP_RADIUS / map->wall_width)
				&& in_circle(&wall->edges[index].pt2, map->player->pos.x, map->player->pos.y, MAP_RADIUS / map->wall_width))
			{
				set_point_follow(&start, &wall->edges[index].pt1, map, settings);
				set_point_follow(&finish, &wall->edges[index].pt2, map, settings);
				mlx_draw_line(img, start, finish, WHITE);
			}
		}
		++index;
	}
}

static void	draw_door(t_img *img, t_door *door, t_map *map, t_settings *settings)
{
	int			index;
	t_vertice	start;
	t_vertice	finish;

	index = 0;
	while (index < 3)
	{
		if (door->edges[index].side != CUT)
		{
			if (in_circle(&door->edges[index].pt1, map->player->pos.x, map->player->pos.y, MAP_RADIUS / map->wall_width)
				&& in_circle(&door->edges[index].pt2, map->player->pos.x, map->player->pos.y, MAP_RADIUS / map->wall_width))
			{
				set_point_follow(&start, &door->edges[index].pt1, map, settings);
				set_point_follow(&finish, &door->edges[index].pt2, map, settings);
				mlx_draw_line(img, start, finish, BROWNISH);
			}
		}
		++index;
	}
}

static void	draw_portals(t_img *img, t_map *map, t_settings *settings)
{
	t_portal	*portal;
	t_vertice	start;
	t_vertice	finish;

	portal = map->portals;
	while (portal)
	{
		if (in_circle(&portal->pline.pt1, map->player->pos.x, map->player->pos.y, MAP_RADIUS / map->wall_width)
			&& in_circle(&portal->pline.pt2, map->player->pos.x, map->player->pos.y, MAP_RADIUS / map->wall_width))
		{
			set_point_follow(&start, &portal->pline.pt1, map, settings);
			set_point_follow(&finish, &portal->pline.pt2, map, settings);
			mlx_draw_line(img, start, finish, BLUEISH);
		}
		portal = portal->next;
	}
}

static void	draw_player(t_img *img, t_settings *settings)
{
	t_vertice	pt;
	t_vertice	pt2;
	t_vertice	pos_translate;

	set_point(&pos_translate, settings->offset.x + MAP_RADIUS,
		settings->offset.y + MAP_RADIUS, 0);
	pt2.x = pos_translate.x - PSIZE;
	while (pt2.x < pos_translate.x + PSIZE)
	{
		pt2.y = pos_translate.y - PSIZE;
		while (pt2.y < pos_translate.y + PSIZE)
		{
			if (get_dist(pos_translate, pt2) <= PSIZE)
			{
				pt.x = pt2.x;
				pt.y = pt2.y;
				mlx_pxl_put(img, pt.x, pt.y, RED);
			}
			++pt2.y;
		}
		++pt2.x;
	}
}

void	setup_rendermap(t_img *canva, t_settings *settings)
{
	t_vertice	pt;

	pt.z = 0;
	pt.y = settings->offset.y;
	while (pt.y < settings->offset.y + MAP_RADIUS * 2)
	{
		pt.x = settings->offset.x;
		while (pt.x < settings->offset.x + MAP_RADIUS * 2)
		{
			if (in_circle(&pt, MAP_RADIUS + settings->offset.x,
				MAP_RADIUS + settings->offset.y, MAP_RADIUS - 5))
			{
				if (in_circle(&pt, MAP_RADIUS + settings->offset.x,
					MAP_RADIUS + settings->offset.y, MAP_RADIUS - 10))
					mlx_pxl_put(canva, pt.x, pt.y, BLACK);
				else
					mlx_pxl_put(canva, pt.x, pt.y, WHITE);
			}
			++pt.x;
		}
		++pt.y;
	}
}

void	fill_minimap(t_cub *cub)
{
	t_wall	*wall;
	t_door	*door;

	wall = cub->map->walls;
	while (wall)
	{
		draw_walls(cub->mlx->render3d, wall, cub->map, cub->settings);
		wall = wall->next;
	}
	door = cub->map->doors;
	while (door)
	{
		draw_door(cub->mlx->render3d, door, cub->map, cub->settings);
		door = door->next;
	}
	draw_portals(cub->mlx->render3d, cub->map, cub->settings);
	// draw_stored_rays(cub->mlx->render3d, cub->mlx->tmp_rays, cub->settings);
	draw_player(cub->mlx->render3d, cub->settings);
}
