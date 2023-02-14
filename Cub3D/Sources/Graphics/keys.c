/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:51:21 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/14 14:45:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_exit(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int	key_down(int kcode, t_cub *cub)
{
	if (kcode == KEY_ESC)
		mlx_exit(0);
	else if (kcode == KEY_UP || kcode == KEY_DOWN || kcode == KEY_W || kcode == KEY_S)
		cub->mlx->keys->vertical = (kcode == KEY_UP) + (kcode == KEY_W) - (kcode == KEY_DOWN) - (kcode == KEY_S);
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		cub->mlx->keys->steering = (kcode == KEY_LEFT) - (kcode == KEY_RIGHT);
	else if (kcode == KEY_A || kcode == KEY_D)
		cub->mlx->keys->horizontal = (kcode == KEY_A) - (kcode == KEY_D);
	else if (kcode == KEY_SHIFT)
		cub->mlx->keys->sprint = 1;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = (kcode == KEY_PLUS) - (kcode == KEY_MINUS);
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->fov_dist = (kcode == KEY_PLUS_PAD) - (kcode == KEY_MINUS_PAD);
	else if (kcode == KEY_ASTERISK && ++cub->mlx->keys->fov_enable == 1)
		cub->settings->fov_enable = !cub->settings->fov_enable;
	else if (kcode == KEY_M && ++cub->mlx->keys->mini_follow == 1)
		cub->settings->mini_follow = !cub->settings->mini_follow;
	else if (kcode == KEY_SPACE && ++cub->mlx->keys->door == 1)
		try_door(cub->map->player, cub->map->doors);
	else if (kcode == KEY_0 && ++cub->mlx->keys->mini_enable == 1)
		cub->settings->mini_enable = !cub->settings->mini_enable;
	else if (kcode == KEY_1 || kcode == KEY_2)
		cub->mlx->keys->dist_feel = (kcode == KEY_1) - (kcode == KEY_2);
	else if (kcode == KEY_4 || kcode == KEY_5)
		cub->mlx->keys->wall_width = (kcode == KEY_4) - (kcode == KEY_5);
	return (0);
}

int	key_released(int kcode, t_cub *cub)
{
	// printf("key %10d\n", kcode);
	if (kcode == KEY_UP || kcode == KEY_DOWN || kcode == KEY_W || kcode == KEY_S)
		cub->mlx->keys->vertical = 0;
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		cub->mlx->keys->steering = 0;
	else if (kcode == KEY_D || kcode == KEY_A)
		cub->mlx->keys->horizontal = 0;
	else if (kcode == KEY_SHIFT)
		cub->mlx->keys->sprint = 0;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = 0;
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->fov_dist = 0;
	else if (kcode == KEY_ASTERISK)
		cub->mlx->keys->fov_enable = 0;
	else if (kcode == KEY_M)
		cub->mlx->keys->mini_follow = 0;
	else if (kcode == KEY_SPACE)
		cub->mlx->keys->door = 0;
	else if (kcode == KEY_0)
		cub->mlx->keys->mini_enable = 0;
	else if (kcode == KEY_1 || kcode == KEY_2)
		cub->mlx->keys->dist_feel = 0;
	else if (kcode == KEY_4 || kcode == KEY_5)
		cub->mlx->keys->wall_width = 0;
	return (0);
}
