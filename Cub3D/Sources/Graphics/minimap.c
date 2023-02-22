/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:52:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/22 14:16:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_walls(t_img *img, t_wall *wall, t_map *map, t_set *settings)
{
	t_vert	start;
	t_vert	finish;

	if (in_circle(&wall->wline.pt1, map->player->pos.x, map->player->pos.y, settings->radius_divww)
		&& in_circle(&wall->wline.pt2, map->player->pos.x, map->player->pos.y, settings->radius_divww))
	{
		set_point_follow(&start, &wall->wline.pt1, map, settings);
		set_point_follow(&finish, &wall->wline.pt2, map, settings);
		mlx_draw_line(img, start, finish, WHITE);
	}
}

static void	draw_door(t_img *img, t_door *door, t_map *map, t_set *settings)
{
	int			index;
	t_vert	start;
	t_vert	finish;

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

static void	draw_portals(t_img *img, t_map *map, t_set *settings)
{
	t_portal	*portal;
	t_vert	start;
	t_vert	finish;

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

static void	draw_disk(t_img *img, t_vert *center, int radius, unsigned color)
{
	t_vert	pt;
	t_vert	pt2;

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

static void	draw_circle(t_img *img, t_vert *center, double radius, unsigned color)
{
	t_vert	pt;
	t_vert	pt2;
	double	dist;

	pt2.x = center->x - radius;
	while (pt2.x < center->x + radius)
	{
		pt2.y = center->y - radius;
		while (pt2.y < center->y + radius)
		{
			dist = get_dist(*center, pt2);
			if (dist <= radius && dist >= radius - 1)
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

static void	draw_posts(t_img *img, t_map *map, t_set *settings)
{
	t_post	*post;
	t_vert	center;

	post = map->posts;
	while (post)
	{
		if (in_circle(&post->center, map->player->pos.x, map->player->pos.y, settings->radius_divww - post->radius))
		{
			set_point_follow(&center, &post->center, map, settings);
			draw_circle(img, &center, post->radius * settings->wall_width, WHITE);
		}
		post = post->next;
	}
}

static void	draw_player(t_img *img, t_set *settings)
{
	t_vert	pos_translate;

	set_point(&pos_translate, settings->offset.x + MAP_RADIUS,
		settings->offset.y + MAP_RADIUS, 0);
	draw_disk(img, &pos_translate, PSIZE, RED);
}

static void	add_north(t_img *canva, double angle, t_set *settings)
{
	t_vert	npos;

	if (!settings->mini_follow)
		set_point(&npos, settings->offset.x + MAP_RADIUS, settings->offset.y + 2.5, 0);
	else
		set_point(&npos, settings->offset.x + MAP_RADIUS + cos(angle) * (MAP_RADIUS - 2.5), settings->offset.y + MAP_RADIUS - sin(angle) * (MAP_RADIUS - 2.5), 0);
	draw_disk(canva, &npos, PSIZE * 2, RED);
}

void	setup_rendermap(t_img *canva, t_set *settings)
{
	t_vert	pt;

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
	draw_posts(cub->mlx->render3d, cub->map, cub->settings);
	// draw_stored_rays(cub->mlx->render3d, cub->rays, cub->settings); //todo
	draw_player(cub->mlx->render3d, cub->settings);
	add_north(cub->mlx->render3d, M_PI - cub->map->player->direction, cub->settings);
}
