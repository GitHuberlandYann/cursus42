/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:04:12 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/10 15:41:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exec_movement(t_ray *ray, t_player *player, int sprint, int move)
{
	if (ray->fhit == PORTAL && ray->pdist < player->speed * (1 + sprint)
		&& ray->dist > player->speed * (1 + sprint))
	{
		player->pos.x = ray->pray.pt1.x
			+ cos(ray->out_angle) * (player->speed * (1 + sprint));
		player->pos.y = ray->pray.pt1.y
			- sin(ray->out_angle) * (player->speed * (1 + sprint));
		player->direction = ray->out_angle + M_PI * (move == -1);
	}
	else if (ray->mdist > 2 * player->speed * (1 + sprint))
	{
		player->pos.x += cos(player->direction) * player->speed
			* (1 + sprint) * move;
		player->pos.y -= sin(player->direction) * player->speed
			* (1 + sprint) * move;
	}
}

static void	move_players(t_cub *cub, t_player *player, int sprint, int move)
{
	t_ray	wall_sensor;

	if (player->state == SHOOTING || player->state == DEAD)
		return ;
	wall_sensor.dist = 10000;
	wall_sensor.pdist = 10000;
	wall_sensor.fhit = CUT;
	if (move)
	{
		set_point(&wall_sensor.ray.pt1, player->pos.x, player->pos.y, 0);
		wall_sensor.angle = player->direction + M_PI * (move == -1);
		wall_sensor.out_angle = wall_sensor.angle;
		wall_sensor.objs = 0;
		ray_walling(cub->map->walls, &wall_sensor);
		ray_dooring(cub->map->doors, &wall_sensor);
		ray_posting(cub->map->posts, &wall_sensor);
		ray_portaling(cub->map->portals, &wall_sensor, player->other, cub);
		ray_objing(cub->map->objs, player->other, &wall_sensor);
		exec_movement(&wall_sensor, player, sprint, move);
		player->state = RUNNING;
	}
	else
		player->state = IDLE;
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
		set_ray_angles(cub->settings->fov_width, cub->map->player,
			cub->map->playerbis);
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
	update_anim_frames(cub->map, cub->mlx, key, cub->mlx->fps);
	update_shooting_frames(cub->mlx, cub->map->player, cub->map->playerbis);
	exec_keys(key, cub);
	clear_render(cub->mlx->render3d, cub->map->fc_colors, cub);
	clear_render(cub->mlx->render3dbis, cub->map->fc_colors, cub);
	move_players(cub, cub->map->player, key->sprint, key->vertical);
	precompute_obj_lines(&cub->map->player->pos, cub->map->objs);
	precompute_other_player(cub->map->player, cub->map->playerbis);
	render_fdf(cub->map->objs, &cub->map->player->pos);
	render_map(cub->mlx->render3d, cub->map->player, cub->map, cub);
	move_players(cub, cub->map->playerbis, key->sprintbis, key->verticalbis);
	precompute_obj_lines(&cub->map->playerbis->pos, cub->map->objs);
	precompute_other_player(cub->map->playerbis, cub->map->player);
	render_fdf(cub->map->objs, &cub->map->playerbis->pos);
	render_map(cub->mlx->render3dbis, cub->map->playerbis, cub->map, cub);
	add_death_filters(cub->mlx, cub->map->player, cub->map->playerbis);
	display_weapon(cub->mlx, cub->map->player, 1);
	display_weapon(cub->mlx, cub->map->playerbis, 2);
	add_fps(cub->mlx, cub->settings, cub->map->player);
	return (0);
}
