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

static void	move_god(t_key *keys, t_player *player)
{
	if (keys->vertical)
	{
		player->pos.x += cos(player->direction) * player->speed * (1 + keys->sprint) * keys->vertical;
		player->pos.y -= sin(player->direction) * player->speed * (1 + keys->sprint) * keys->vertical;
	}
	if (keys->horizontal)
	{
		player->pos.x += cos(player->direction + M_PI / 2) * player->speed * (1 + keys->sprint) * keys->horizontal;
		player->pos.y -= sin(player->direction + M_PI / 2) * player->speed * (1 + keys->sprint) * keys->horizontal;
	}
}

static void	move_player(t_key *keys, t_cub *cub, t_player *player)
{
	t_ray	wall_sensor;

	wall_sensor.dist = 10000;
	wall_sensor.pdist = 10000;
	wall_sensor.fhit = CUT;
	if (keys->vertical)
	{
		set_point(&wall_sensor.ray.pt1, player->pos.x, player->pos.y, 0);
		wall_sensor.angle = player->direction + M_PI * (keys->vertical == -1);
		wall_sensor.out_angle = wall_sensor.angle;
		ray_walling(cub->map->walls, &wall_sensor);
		ray_dooring(cub->map->doors, &wall_sensor);
		ray_portaling(cub->map->portals, &wall_sensor, cub);
		if (wall_sensor.fhit == PORTAL && wall_sensor.pdist < player->speed * (1 + keys->sprint) && wall_sensor.dist > player->speed * (1 + keys->sprint))
		{
			player->pos.x = wall_sensor.pray.pt1.x + cos(wall_sensor.out_angle) * (player->speed * (1 + keys->sprint));
			player->pos.y = wall_sensor.pray.pt1.y - sin(wall_sensor.out_angle) * (player->speed * (1 + keys->sprint));
			player->direction = wall_sensor.out_angle + M_PI * (keys->vertical == -1);
		}
		else if (wall_sensor.dist > 2 * player->speed * (1 + keys->sprint))
		{
			player->pos.x += cos(player->direction) * player->speed * (1 + keys->sprint) * keys->vertical;
			player->pos.y -= sin(player->direction) * player->speed * (1 + keys->sprint) * keys->vertical;
		}
	}
	if (keys->horizontal)
	{
		set_point(&wall_sensor.ray.pt1, player->pos.x, player->pos.y, 0);
		wall_sensor.angle = player->direction + M_PI / 2 * keys->horizontal;
		wall_sensor.out_angle = wall_sensor.angle;
		ray_walling(cub->map->walls, &wall_sensor);
		ray_dooring(cub->map->doors, &wall_sensor);
		ray_portaling(cub->map->portals, &wall_sensor, cub);
		if (wall_sensor.fhit == PORTAL && wall_sensor.pdist < player->speed * (1 + keys->sprint) && wall_sensor.dist > player->speed * (1 + keys->sprint))
		{
			player->pos.x = wall_sensor.pray.pt1.x + cos(wall_sensor.out_angle) * (player->speed * (1 + keys->sprint));
			player->pos.y = wall_sensor.pray.pt1.y - sin(wall_sensor.out_angle) * (player->speed * (1 + keys->sprint));
			player->direction = wall_sensor.out_angle + M_PI / 2 + M_PI * (keys->horizontal == 1);
		}
		else if (wall_sensor.dist > 2 * player->speed * (1 + keys->sprint))
		{
			player->pos.x += cos(player->direction + M_PI / 2) * player->speed * (1 + keys->sprint) * keys->horizontal;
			player->pos.y -= sin(player->direction + M_PI / 2) * player->speed * (1 + keys->sprint) * keys->horizontal;
		}
	}
}

static void	exec_keys(t_key *keys, t_cub *cub)
{
	if (keys->steering)
		cub->map->player->direction += keys->steering * 5 * M_PI / 180;
	if ((keys->fov_width < 0 && cub->settings->fov_width > WIN_WIDTH / 10)
		|| (keys->fov_width > 0 && cub->settings->fov_width < WIN_WIDTH * 2))
	{
		cub->settings->fov_width += 10 * keys->fov_width;
		set_ray_angles(cub);
	}
	if (keys->fov_dist > 0 || (keys->fov_dist < 0 && cub->settings->fov_dist > 0.5))
		cub->settings->fov_dist += keys->fov_dist * 0.1;
	if (keys->dist_feel)
	{
		cub->settings->dist_feel += keys->dist_feel * 0.01;
		if (cub->settings->dist_feel < 0.5 || cub->settings->dist_feel > 1.5)
			cub->settings->dist_feel -= keys->dist_feel * 0.01;
	}
	if (keys->wall_width)
	{
		cub->settings->wall_width += keys->wall_width;
		if (!cub->settings->wall_width || cub->settings->wall_width > 75)
			cub->settings->wall_width -= keys->wall_width;
		else
			cub->settings->radius_divww = MAP_RADIUS / cub->settings->wall_width;
	}
}

int	redraw_all(t_cub *cub)
{
	t_key	*key;

	key = cub->mlx->keys;
	uptdate_doors(cub->map->doors, key);
	if (!key->horizontal && !key->vertical && !key->steering && !key->fov_width
		&& key->fov_enable != 1 && !key->fov_dist && key->mini_follow != 1
		&& !key->mousedate && key->door != 1 && key->mini_enable != 1
		&& !key->dist_feel && !key->wall_width && key->godmode != 1)
		return (1);
	key->mousedate = 0;
	if (!cub->settings->godmode)
		move_player(key, cub, cub->map->player);
	else
		move_god(key, cub->map->player);
	exec_keys(key, cub);
	clear_render(cub->mlx->render3d, cub->map->fc_colors, cub);
	render_map(cub->mlx->render3d, cub->map->player, cub->map, cub);
	if (cub->settings->mini_enable)
	{
		setup_rendermap(cub->mlx->render3d, cub->settings);
		fill_minimap(cub);
	}
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
		cub->mlx->render3d->img_ptr, 0, 0);
	add_fps(cub->mlx, cub->settings);
	return (0);
}
