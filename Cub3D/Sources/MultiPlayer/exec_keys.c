/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:04:12 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/27 16:31:43 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		wall_sensor.objs = 0;
		ray_walling(cub->map->walls, &wall_sensor);
		ray_dooring(cub->map->doors, &wall_sensor);
		ray_posting(cub->map->posts, &wall_sensor);
		ray_portaling(cub->map->portals, &wall_sensor, cub);
		ray_objing(cub->map->objs, player->other, &wall_sensor);
		if (wall_sensor.fhit == PORTAL && wall_sensor.pdist < player->speed * (1 + keys->sprint) && wall_sensor.dist > player->speed * (1 + keys->sprint))
		{
			player->pos.x = wall_sensor.pray.pt1.x + cos(wall_sensor.out_angle) * (player->speed * (1 + keys->sprint));
			player->pos.y = wall_sensor.pray.pt1.y - sin(wall_sensor.out_angle) * (player->speed * (1 + keys->sprint));
			player->direction = wall_sensor.out_angle + M_PI * (keys->vertical == -1);
		}
		else if (wall_sensor.mdist > 2 * player->speed * (1 + keys->sprint))
		{
			player->pos.x += cos(player->direction) * player->speed * (1 + keys->sprint) * keys->vertical;
			player->pos.y -= sin(player->direction) * player->speed * (1 + keys->sprint) * keys->vertical;
		}
	}
}

static void	move_playerbis(t_key *keys, t_cub *cub, t_player *player)
{
	t_ray	wall_sensor;

	wall_sensor.dist = 10000;
	wall_sensor.pdist = 10000;
	wall_sensor.fhit = CUT;
	if (keys->verticalbis)
	{
		set_point(&wall_sensor.ray.pt1, player->pos.x, player->pos.y, 0);
		wall_sensor.angle = player->direction + M_PI * (keys->verticalbis == -1);
		wall_sensor.out_angle = wall_sensor.angle;
		wall_sensor.objs = 0;
		ray_walling(cub->map->walls, &wall_sensor);
		ray_dooring(cub->map->doors, &wall_sensor);
		ray_posting(cub->map->posts, &wall_sensor);
		ray_portaling(cub->map->portals, &wall_sensor, cub);
		ray_objing(cub->map->objs, player->other, &wall_sensor);
		if (wall_sensor.fhit == PORTAL && wall_sensor.pdist < player->speed * (1 + keys->sprintbis) && wall_sensor.dist > player->speed * (1 + keys->sprintbis))
		{
			player->pos.x = wall_sensor.pray.pt1.x + cos(wall_sensor.out_angle) * (player->speed * (1 + keys->sprintbis));
			player->pos.y = wall_sensor.pray.pt1.y - sin(wall_sensor.out_angle) * (player->speed * (1 + keys->sprintbis));
			player->direction = wall_sensor.out_angle + M_PI * (keys->verticalbis == -1);
		}
		else if (wall_sensor.mdist > 2 * player->speed * (1 + keys->sprintbis))
		{
			player->pos.x += cos(player->direction) * player->speed * (1 + keys->sprintbis) * keys->verticalbis;
			player->pos.y -= sin(player->direction) * player->speed * (1 + keys->sprintbis) * keys->verticalbis;
		}
	}
}

static void	exec_keys(t_key *keys, t_cub *cub)
{
	if (keys->steering)
		cub->map->player->direction += keys->steering * 5 * M_PI / 180;
	if (keys->steeringbis)
		cub->map->playerbis->direction += keys->steeringbis * 5 * M_PI / 180;
	if ((keys->fov_width < 0 && cub->settings->fov_width > WIN_WIDTH / 10)
		|| (keys->fov_width > 0 && cub->settings->fov_width < WIN_WIDTH * 2))
	{
		cub->settings->fov_width += 10 * keys->fov_width;
		set_ray_angles(cub->settings->fov_width, cub->map->player, cub->map->playerbis);
	}
	if (keys->dist_feel)
	{
		cub->settings->dist_feel += keys->dist_feel * 0.01;
		if (cub->settings->dist_feel < 0.5 || cub->settings->dist_feel > 1.5)
			cub->settings->dist_feel -= keys->dist_feel * 0.01;
	}
}

int	redraw_all_2p(t_cub *cub)
{
	t_key	*key;

	key = cub->mlx->keys;
	update_doors(cub->map->doors, key);
	update_anim_frames(cub->map, key, cub->mlx->fps);
	if (!key->vertical && !key->verticalbis && !key->steering && !key->fov_width
		&& !key->steeringbis && !key->mousedate && !key->dist_feel)
		return (1);
	key->mousedate = 0;
	move_player(key, cub, cub->map->player);
	move_playerbis(key, cub, cub->map->playerbis);
	exec_keys(key, cub);
	clear_render(cub->mlx->render3d, cub->map->fc_colors, cub);
	clear_render(cub->mlx->render3dbis, cub->map->fc_colors, cub);
	render_fdf(cub->map->objs, &cub->map->player->pos);
	render_map(cub->mlx->render3d, cub->map->player, cub->map, cub);
	render_fdf(cub->map->objs, &cub->map->playerbis->pos);
	render_map(cub->mlx->render3dbis, cub->map->playerbis, cub->map, cub);
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
		cub->mlx->render3d->img_ptr, 0, 0);
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
		cub->mlx->render3dbis->img_ptr, 0, WIN_HEIGHT_2);
	add_fps(cub->mlx, cub->settings, cub->map->player);
	return (0);
}
