/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:16:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/07 19:08:11 by yhuberla         ###   ########.fr       */
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
			set_point(&start, wall->edges[index].pt1.x * map->wall_width, wall->edges[index].pt1.y * map->wall_width, 0);
			set_point(&finish, wall->edges[index].pt2.x * map->wall_width, wall->edges[index].pt2.y * map->wall_width, 0);
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
			set_point(&start, door->edges[index].pt1.x * map->wall_width, door->edges[index].pt1.y * map->wall_width, 0);
			set_point(&finish, door->edges[index].pt2.x * map->wall_width, door->edges[index].pt2.y * map->wall_width, 0);
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
		set_point(&start, portal->pline.pt1.x * map->wall_width, portal->pline.pt1.y * map->wall_width, 0);
		set_point(&finish, portal->pline.pt2.x * map->wall_width, portal->pline.pt2.y * map->wall_width, 0);
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
	pos_translate.x = player->pos.x - player->size * cos(player->direction);
	pos_translate.y = player->pos.y + player->size * sin(player->direction);
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
}

static void	draw_rays(t_img *img, t_player *player, t_map *map, t_cub *cub)
{
	t_ray		ray;
	t_vertice	start;
	int			index;

	index = -1;
	set_point(&ray.ray.pt1, player->pos.x, player->pos.y, 0);
	while (++index < WIN_WIDTH)
	{
		ray.angle = player->direction + atan((index - WIN_WIDTH / 2) / cub->settings->fov_width);
		ray.dist = 10000;
		set_point(&ray.ray.pt2, player->pos.x + cos(ray.angle) * cub->settings->fov_dist, player->pos.y - sin(ray.angle) * cub->settings->fov_dist, 0);
		if (cub->settings->fov_enable)
			ray.dist = cub->settings->fov_dist;
		ray.hit = CUT;
		ray.fhit = CUT;
		ray.recurse_level = 0;
		ray_walling(map->walls, &ray);
		ray_dooring(map->doors, &ray);
		ray_portaling(map->portals, &ray, cub);
		set_point(&start, ray.ray.pt1.x * map->wall_width, ray.ray.pt1.y * map->wall_width, 0);
		set_point(&ray.ray.pt2, ray.ray.pt2.x * map->wall_width, ray.ray.pt2.y * map->wall_width, 0);
		// printf("[%lf,%lf]-[%lf,%lf]\n", ray.ray.pt1.x, ray.ray.pt1.y, ray.ray.pt2.x, ray.ray.pt2.y);
		if (ray.fhit == PORTAL)
		{
			mlx_draw_line(img, start, ray.ray.pt2, BLUEISH);
			set_point(&ray.pray.pt1, ray.pray.pt1.x * map->wall_width, ray.pray.pt1.y * map->wall_width, 0);
			set_point(&ray.pray.pt2, ray.pray.pt2.x * map->wall_width, ray.pray.pt2.y * map->wall_width, 0);
			mlx_draw_line(img, ray.pray.pt1, ray.pray.pt2, BLUEISH);
		}
		else if (ray.hit == DOOR)
			mlx_draw_line(img, start, ray.ray.pt2, BROWNISH);
		else if (ray.hit == CUT)
			mlx_draw_line(img, start, ray.ray.pt2, GREENISH);
		else
			mlx_draw_line(img, start, ray.ray.pt2, LIGHT_WHITE);
	}
}

void	fill_old_minimap(t_cub *cub)
{
	t_wall	*wall;
	t_door	*door;

	if (cub->settings->mini_follow)
		return (fill_old_minimap_follow(cub));
	wall = cub->map->walls;
	while (wall)
	{
		draw_walls(cub->mlx->old_minimap, wall, cub->map);
		wall = wall->next;
	}
	door = cub->map->doors;
	while (door)
	{
		draw_door(cub->mlx->old_minimap, door, cub->map);
		door = door->next;
	}
	draw_portals(cub->mlx->old_minimap, cub->map);
	draw_player(cub->mlx->old_minimap, cub->map->player, cub->map);
	draw_rays(cub->mlx->old_minimap, cub->map->player, cub->map, cub);
}
