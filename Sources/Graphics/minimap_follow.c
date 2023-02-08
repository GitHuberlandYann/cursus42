/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_follow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:58:15 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/07 19:08:21 by yhuberla         ###   ########.fr       */
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
			mlx_draw_line(img, start, finish, BROWNISH);
		}
		++index;
	}
}

static void	draw_portals(t_img *img, t_map *map)
{
	t_portal	*portal;
	t_vertice	start;
	t_vertice	finish;

	portal = map->portals;
	while (portal)
	{
		set_point_follow(&start, &portal->pline.pt1, map, 1);
		set_point_follow(&finish, &portal->pline.pt2, map, 1);
		mlx_draw_line(img, start, finish, BLUEISH);
		portal = portal->next;
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

static void	draw_rays(t_img *img, t_player *player, t_map *map, t_cub *cub)
{
	t_ray		ray;
	t_vertice	start;
	t_vertice	finish;

	set_point(&ray.ray.pt1, player->pos.x, player->pos.y, 0);
	ray.angle = player->direction - cub->settings->fov_width / 2;
	while (ray.angle < player->direction + cub->settings->fov_width / 2)
	{
		ray.dist = 10000;
		set_point(&ray.ray.pt2, player->pos.x + cos(ray.angle) * cub->settings->fov_dist, player->pos.y - sin(ray.angle) * cub->settings->fov_dist, 0);
		if (cub->settings->fov_enable)
			ray.dist = cub->settings->fov_dist;
		ray.hit = CUT;
		ray_walling(map->walls, &ray);
		ray_dooring(map->doors, &ray);
		ray_portaling(map->portals, &ray, cub);
		set_point_follow(&start, &map->player->pos, map, 1);
		set_point_follow(&finish, &ray.ray.pt2, map, 1);
		if (ray.hit == DOOR)
			mlx_draw_line(img, start, finish, BROWNISH);
		else if (ray.hit == CUT)
			mlx_draw_line(img, start, finish, GREENISH);
		else if (ray.hit == PORTAL)
		{
			mlx_draw_line(img, start, finish, BLUEISH);
			set_point_follow(&start, &ray.pray.pt1, map, 1);
			set_point_follow(&finish, &ray.pray.pt2, map, 1);
			mlx_draw_line(img, start, finish, BLUEISH);
		}
		else
			mlx_draw_line(img, start, finish, LIGHT_WHITE);
		ray.angle += 0.001;
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
	draw_portals(cub->mlx->minimap, cub->map);
	draw_player(cub->mlx->minimap, cub->map->player, cub->map);
	draw_rays(cub->mlx->minimap, cub->map->player, cub->map, cub);
}
