/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:59:54 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/02 11:55:14 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exec_keys(t_key *keys, t_cub *cub)
{
	t_vertice	wall_sensor;

	if (keys->vertical)
	{
		wall_sensor = ray_walling(cub->map->player, cub->map->walls,
				cub->map->player->direction + M_PI * (keys->vertical == -1), cub->settings);
		if (get_dist(cub->map->player->pos, wall_sensor) > 0.2)
		{
			cub->map->player->pos.x += cos(cub->map->player->direction) * 0.2 * keys->vertical;
			cub->map->player->pos.y -= sin(cub->map->player->direction) * 0.2 * keys->vertical;
		}
	}
	if (keys->horizontal)
		;
	cub->map->player->direction += keys->steering * 0.1;
	if (keys->fov_width < 0 && cub->settings->fov_width > M_PI / 10)
		cub->settings->fov_width -= M_PI / 180;
	else if (keys->fov_width > 0 && cub->settings->fov_width < M_PI * 2)
		cub->settings->fov_width += M_PI / 180;
	if ((cub->settings->fov_dist > 0.5 && keys->fov_dist < 0) || keys->fov_dist > 0)
		cub->settings->fov_dist += keys->fov_dist * 0.1;
}

int	redraw_all(t_cub *cub)
{
	t_key	*key;

	key = cub->mlx->keys;
	if (!key->horizontal && !key->vertical && !key->steering && !key->fov_width
		&& key->fov_enable != 1 && !key->fov_dist && key->mini_follow != 1)
		return (1);
	exec_keys(key, cub);
	mlx_clear_img(cub->mlx->minimap);
	fill_minimap(cub);
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
		cub->mlx->minimap->img_ptr, (WIN_WIDTH - MINIMAP_WIDTH) / 4, (WIN_HEIGHT - MINIMAP_WIDTH) / 4);
	return (0);
}
