/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:52:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 14:25:12 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_walls(t_img *img, t_wall *wall, t_map *map, t_set *settings)
{
	t_vert	start;
	t_vert	finish;

	if (in_circle(&wall->wline.pt1, map->player->pos.x, map->player->pos.y,
			settings->radius_divww)
		&& in_circle(&wall->wline.pt2, map->player->pos.x, map->player->pos.y,
			settings->radius_divww))
	{
		set_point_follow(&start, &wall->wline.pt1, map, settings);
		set_point_follow(&finish, &wall->wline.pt2, map, settings);
		mlx_draw_line(img, start, finish, WHITE);
	}
}

static void	draw_door(t_img *img, t_door *door, t_map *map, t_set *sett)
{
	int		index;
	t_vert	start;
	t_vert	finish;

	index = 0;
	while (index < 3)
	{
		if (door->edges[index].side != CUT)
		{
			if (in_circle(&door->edges[index].pt1, map->player->pos.x,
					map->player->pos.y, sett->radius_divww)
				&& in_circle(&door->edges[index].pt2, map->player->pos.x,
					map->player->pos.y, sett->radius_divww))
			{
				set_point_follow(&start, &door->edges[index].pt1, map, sett);
				set_point_follow(&finish, &door->edges[index].pt2, map, sett);
				mlx_draw_line(img, start, finish, BROWNISH);
			}
		}
		++index;
	}
}

static void	draw_portals(t_img *img, t_map *map, t_set *settings)
{
	t_portal	*portal;
	t_vert		start;
	t_vert		finish;

	portal = map->portals;
	while (portal)
	{
		if (in_circle(&portal->pline.pt1, map->player->pos.x,
				map->player->pos.y, settings->radius_divww)
			&& in_circle(&portal->pline.pt2, map->player->pos.x,
				map->player->pos.y, settings->radius_divww))
		{
			set_point_follow(&start, &portal->pline.pt1, map, settings);
			set_point_follow(&finish, &portal->pline.pt2, map, settings);
			mlx_draw_line(img, start, finish, BLUEISH);
		}
		portal = portal->next;
	}
}

static void	draw_stored_rays(t_img *img, t_ray	rays[WIN_WIDTH], t_map *map,
	t_set *settings)
{
	int		index;
	t_vert	start;
	t_vert	finish;

	index = -1;
	while (++index < WIN_WIDTH)
	{
		if (in_circle(&rays[index].ray.pt2, map->player->pos.x,
				map->player->pos.y, settings->radius_divww))
		{
			set_point_follow(&start, &rays[index].ray.pt1, map, settings);
			set_point_follow(&finish, &rays[index].ray.pt2, map, settings);
			mlx_draw_line(img, start, finish, WHITE);
		}
	}
}

void	fill_minimap(t_cub *cub)
{
	t_wall	*wall;
	t_door	*door;

	draw_stored_rays(cub->mlx->render3d, cub->map->player->rays, cub->map,
		cub->settings);
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
	draw_posts(cub->mlx->render3d, cub->map, cub->settings);
	draw_player(cub->mlx->render3d, cub->settings);
	add_north(cub->mlx->render3d, M_PI - cub->map->player->direction,
		cub->settings);
}
