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
		player->pos.x += cos(player->direction) * player->speed
			* (1 + keys->sprint) * keys->vertical;
		player->pos.y -= sin(player->direction) * player->speed
			* (1 + keys->sprint) * keys->vertical;
	}
	if (keys->horizontal)
	{
		player->pos.x += cos(player->direction + M_PI / 2)
			* player->speed * (1 + keys->sprint) * keys->horizontal;
		player->pos.y -= sin(player->direction + M_PI / 2)
			* player->speed * (1 + keys->sprint) * keys->horizontal;
	}
}

static void	exec_keys(t_key *keys, t_cub *cub, t_set *sett)
{
	keys->mousedate = 0;
	if (keys->steering)
		cub->map->player->direction += keys->steering * 5 * M_PI / 180;
	if ((keys->fov_width < 0 && sett->fov_width > WIN_WIDTH / 10)
		|| (keys->fov_width > 0 && sett->fov_width < WIN_WIDTH * 2))
	{
		sett->fov_width += 10 * keys->fov_width;
		set_ray_angles(sett->fov_width, cub->map->player, cub->map->playerbis);
	}
	if (keys->fov_dist > 0 || (keys->fov_dist < 0 && sett->fov_dist > 0.5))
		sett->fov_dist += keys->fov_dist * 0.1;
	if (keys->dist_feel)
	{
		sett->dist_feel += keys->dist_feel * 0.01;
		if (sett->dist_feel < 0.5 || sett->dist_feel > 1.5)
			sett->dist_feel -= keys->dist_feel * 0.01;
	}
	if (keys->wall_width)
	{
		sett->wall_width += keys->wall_width;
		if (!sett->wall_width || sett->wall_width > 75)
			sett->wall_width -= keys->wall_width;
		else
			sett->radius_divww = MAP_RADIUS / sett->wall_width;
	}
}

int	redraw_all(t_cub *cub)
{
	t_key	*key;

	key = cub->mlx->keys;
	update_doors(cub->map->doors, key);
	update_anim_frames(cub->map, cub->mlx, key, cub->mlx->fps);
	if (!key->horizontal && !key->vertical && !key->steering && !key->fov_width
		&& key->fov_enable != 1 && !key->fov_dist && key->mini_follow != 1
		&& !key->mousedate && key->mini_enable != 1
		&& !key->dist_feel && !key->wall_width && key->godmode != 1)
		return (1);
	if (!cub->settings->godmode)
		move_player(key, cub, cub->map->player);
	else
		move_god(key, cub->map->player);
	exec_keys(key, cub, cub->settings);
	render_fdf(cub->map->objs, &cub->map->player->pos);
	precompute_obj_lines(&cub->map->player->pos, cub->map->objs);
	clear_render(cub->mlx->render3d, cub->map->fc_colors, cub);
	render_map(cub->mlx->render3d, cub->map->player, cub->map, cub);
	if (cub->settings->mini_enable)
		setup_minimap(cub->mlx->render3d, cub->settings, cub);
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
		cub->mlx->render3d->img_ptr, 0, 0);
	add_fps(cub->mlx, cub->settings, cub->map->player);
	return (0);
}
