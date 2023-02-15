/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:52:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/15 12:34:31 by yhuberla         ###   ########.fr       */
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
			if (in_circle(&wall->edges[index].pt1, map->player->pos.x, map->player->pos.y, settings->radius_divww)
				&& in_circle(&wall->edges[index].pt2, map->player->pos.x, map->player->pos.y, settings->radius_divww))
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
			if (in_circle(&door->edges[index].pt1, map->player->pos.x, map->player->pos.y, settings->radius_divww)
				&& in_circle(&door->edges[index].pt2, map->player->pos.x, map->player->pos.y, settings->radius_divww))
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
		if (in_circle(&portal->pline.pt1, map->player->pos.x, map->player->pos.y, settings->radius_divww)
			&& in_circle(&portal->pline.pt2, map->player->pos.x, map->player->pos.y, settings->radius_divww))
		{
			set_point_follow(&start, &portal->pline.pt1, map, settings);
			set_point_follow(&finish, &portal->pline.pt2, map, settings);
			mlx_draw_line(img, start, finish, BLUEISH);
		}
		portal = portal->next;
	}
}

static void	draw_circle(t_img *img, t_vertice *center, int radius, unsigned color)
{
	t_vertice	pt;
	t_vertice	pt2;

	pt2.x = center->x - radius;
	while (pt2.x < center->x + radius)
	{
		pt2.y = center->y - radius;
		while (pt2.y < center->y + radius)
		{
			if (get_dist(*center, pt2) <= radius)
			{
				pt.x = pt2.x;
				pt.y = pt2.y;
				mlx_pxl_put(img, pt.x, pt.y, color);
			}
			++pt2.y;
		}
		++pt2.x;
	}
}

static void	draw_player(t_img *img, t_settings *settings)
{
	t_vertice	pos_translate;

	set_point(&pos_translate, settings->offset.x + MAP_RADIUS,
		settings->offset.y + MAP_RADIUS, 0);
	draw_circle(img, &pos_translate, PSIZE, RED);
}

static void	add_north(t_img *canva, double angle, t_settings *settings)
{
	t_vertice	npos;

	if (!settings->mini_follow)
		set_point(&npos, settings->offset.x + MAP_RADIUS, settings->offset.y + 2.5, 0);
	else
		set_point(&npos, settings->offset.x + MAP_RADIUS + cos(angle) * (MAP_RADIUS - 2.5), settings->offset.y + MAP_RADIUS - sin(angle) * (MAP_RADIUS - 2.5), 0);
	draw_circle(canva, &npos, PSIZE * 2, RED);
}

void	setup_rendermap(t_img *canva, t_settings *settings)
{
	t_vertice	pt;

	pt.y = settings->offset.y;
	while (pt.y < settings->offset.y + MAP_DIAMETER)
	{
		pt.x = settings->offset.x;
		while (pt.x < settings->offset.x + MAP_DIAMETER)
		{
			pt.z = sqrt(pow(pt.x - (MAP_RADIUS + settings->offset.x), 2) + pow(pt.y - (MAP_RADIUS + settings->offset.y), 2));
			if (pt.z <= MAP_RADIUS)
			{
				if (pt.z <= MAP_RADIUS - 5)
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
	add_north(cub->mlx->render3d, M_PI - cub->map->player->direction, cub->settings);
}
