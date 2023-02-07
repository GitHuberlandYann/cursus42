/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:59:54 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/07 19:40:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exec_keys(t_key *keys, t_cub *cub)
{
	t_ray	wall_sensor;

	wall_sensor.dist = 10000;
	wall_sensor.pdist = 10000;
	if (keys->vertical)
	{
		set_point(&wall_sensor.ray.pt1, cub->map->player->pos.x, cub->map->player->pos.y, 0);
		wall_sensor.angle = cub->map->player->direction + M_PI * (keys->vertical == -1);
		wall_sensor.out_angle = wall_sensor.angle;
		ray_walling(cub->map->walls, &wall_sensor);
		ray_dooring(cub->map->doors, &wall_sensor);
		ray_portaling(cub->map->portals, &wall_sensor, cub);
		if (wall_sensor.hit == PORTAL && wall_sensor.pdist < cub->map->player->speed * (1 + keys->sprint) && wall_sensor.dist > cub->map->player->speed * (1 + keys->sprint))
		{
			cub->map->player->pos.x = wall_sensor.pray.pt1.x + cos(wall_sensor.out_angle) * (cub->map->player->speed * (1 + keys->sprint));// - wall_sensor.dist);
			cub->map->player->pos.y = wall_sensor.pray.pt1.y - sin(wall_sensor.out_angle) * (cub->map->player->speed * (1 + keys->sprint));// - wall_sensor.dist);
			cub->map->player->direction = wall_sensor.out_angle + M_PI * (keys->vertical == -1);
		}
		else if (wall_sensor.dist > cub->map->player->speed * (1 + keys->sprint))
		{
			cub->map->player->pos.x += cos(cub->map->player->direction) * cub->map->player->speed * (1 + keys->sprint) * keys->vertical;
			cub->map->player->pos.y -= sin(cub->map->player->direction) * cub->map->player->speed * (1 + keys->sprint) * keys->vertical;
		}
	}
	if (keys->horizontal)
	{
		set_point(&wall_sensor.ray.pt1, cub->map->player->pos.x, cub->map->player->pos.y, 0);
		wall_sensor.angle = cub->map->player->direction + M_PI / 2 * keys->horizontal;
		wall_sensor.out_angle = wall_sensor.angle;
		ray_walling(cub->map->walls, &wall_sensor);
		ray_dooring(cub->map->doors, &wall_sensor);
		ray_portaling(cub->map->portals, &wall_sensor, cub);
		if (wall_sensor.hit == PORTAL && wall_sensor.pdist < cub->map->player->speed * (1 + keys->sprint) && wall_sensor.dist > cub->map->player->speed * (1 + keys->sprint))
		{
			cub->map->player->pos.x = wall_sensor.pray.pt1.x + cos(wall_sensor.out_angle) * (cub->map->player->speed * (1 + keys->sprint));// - wall_sensor.dist);
			cub->map->player->pos.y = wall_sensor.pray.pt1.y - sin(wall_sensor.out_angle) * (cub->map->player->speed * (1 + keys->sprint));// - wall_sensor.dist);
			cub->map->player->direction = wall_sensor.out_angle + M_PI / 2 + M_PI * (keys->horizontal == 1);
		}
		if (wall_sensor.dist > cub->map->player->speed * (1 + keys->sprint))
		{
			cub->map->player->pos.x += cos(cub->map->player->direction + M_PI / 2) * cub->map->player->speed * (1 + keys->sprint) * keys->horizontal;
			cub->map->player->pos.y -= sin(cub->map->player->direction + M_PI / 2) * cub->map->player->speed * (1 + keys->sprint) * keys->horizontal;
		}
	}
	cub->map->player->direction += keys->steering * 5 * M_PI / 180;
	if (keys->fov_width < 0 && cub->settings->fov_width > M_PI / 10)
		cub->settings->fov_width -= M_PI / 180;
	else if (keys->fov_width > 0 && cub->settings->fov_width < M_PI * 2)
		cub->settings->fov_width += M_PI / 180;
	if ((cub->settings->fov_dist > 0.5 && keys->fov_dist < 0) || keys->fov_dist > 0)
		cub->settings->fov_dist += keys->fov_dist * 0.1;
	cub->settings->dist_feel += keys->dist_feel * 0.01;
}

int	redraw_all(t_cub *cub)
{
	t_key	*key;

	key = cub->mlx->keys;
	if (!key->horizontal && !key->vertical && !key->steering && !key->fov_width
		&& key->fov_enable != 1 && !key->fov_dist && key->mini_follow != 1
		&& !key->mousedate && key->door != 1 && key->mini_enable != 1
		&& !key->dist_feel)
		return (1);
	key->mousedate = 0;
	exec_keys(key, cub);
	clear_render(cub->mlx->render3d, cub->map->fc_colors);
	render_map(cub->mlx->render3d, cub->map->player, cub->map, cub);
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
		cub->mlx->render3d->img_ptr, 0, 0);
	if (cub->settings->mini_enable)
	{
		mlx_clear_img(cub->mlx->minimap);
		fill_minimap(cub);
		mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
			cub->mlx->minimap->img_ptr, (WIN_WIDTH - MINIMAP_WIDTH) / 4, (WIN_HEIGHT - MINIMAP_WIDTH) / 4);
	}
	return (0);
}
