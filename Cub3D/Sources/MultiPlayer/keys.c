/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:43:33 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/02 16:10:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_down_2p(int kcode, t_cub *cub)
{
	if (kcode == KEY_ESC)
		mlx_exit(0);
	else if (kcode == KEY_UP || kcode == KEY_DOWN)
		cub->mlx->keys->vertical = (kcode == KEY_UP) - (kcode == KEY_DOWN);
	else if (kcode == KEY_W || kcode == KEY_S)
		cub->mlx->keys->verticalbis = (kcode == KEY_W) - (kcode == KEY_S);
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		cub->mlx->keys->steering = (kcode == KEY_LEFT) - (kcode == KEY_RIGHT);
	else if (kcode == KEY_A || kcode == KEY_D)
		cub->mlx->keys->steeringbis = (kcode == KEY_A) - (kcode == KEY_D);
	else if (kcode == KEY_SHIFT)
		cub->mlx->keys->sprintbis = 1;
	else if (kcode == KEY_0)
		cub->mlx->keys->sprint = 1;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = (kcode == KEY_PLUS) - (kcode == KEY_MINUS);
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->dist_feel = (kcode == KEY_PLUS_PAD)
			- (kcode == KEY_MINUS_PAD);
	else if (kcode == KEY_SPACE && ++cub->mlx->keys->doorbis == 1)
		try_door(cub->map->playerbis, cub->map->doors);
	else if (kcode == KEY_1 && ++cub->mlx->keys->door == 1)
		try_door(cub->map->player, cub->map->doors);
	return (0);
}

	// printf("key %10d\n", kcode);
int	key_released_2p(int kcode, t_cub *cub)
{
	if (kcode == KEY_UP || kcode == KEY_DOWN)
		cub->mlx->keys->vertical = 0;
	else if (kcode == KEY_W || kcode == KEY_S)
		cub->mlx->keys->verticalbis = 0;
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		cub->mlx->keys->steering = 0;
	else if (kcode == KEY_D || kcode == KEY_A)
		cub->mlx->keys->steeringbis = 0;
	else if (kcode == KEY_SHIFT)
		cub->mlx->keys->sprintbis = 0;
	else if (kcode == KEY_0)
		cub->mlx->keys->sprint = 0;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = 0;
	else if (kcode == KEY_SPACE)
		cub->mlx->keys->doorbis = 0;
	else if (kcode == KEY_1)
		cub->mlx->keys->door = 0;
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->dist_feel = 0;
	return (0);
}
