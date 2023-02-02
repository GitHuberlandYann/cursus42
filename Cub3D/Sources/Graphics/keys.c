/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:51:21 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/02 10:17:48 by yhuberla         ###   ########.fr       */
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
	else if (kcode == KEY_UP || kcode == KEY_DOWN)
		cub->mlx->keys->vertical = (kcode == KEY_UP) - (kcode == KEY_DOWN);
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		cub->mlx->keys->steering = (kcode == KEY_LEFT) - (kcode == KEY_RIGHT);
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = (kcode == KEY_PLUS) - (kcode == KEY_MINUS);
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->fov_dist = (kcode == KEY_PLUS_PAD) - (kcode == KEY_MINUS_PAD);
	else if (kcode == KEY_ASTERISK && ++cub->mlx->keys->fov_enable == 1)
		cub->settings->fov_enable = !cub->settings->fov_enable;
	return (0);
}

int	key_released(int kcode, t_cub *cub)
{
	if (kcode == KEY_UP || kcode == KEY_DOWN)
		cub->mlx->keys->vertical = 0;
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		cub->mlx->keys->steering = 0;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = 0;
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->fov_dist = 0;
	else if (kcode == KEY_ASTERISK)
		cub->mlx->keys->fov_enable = 0;
	return (0);
}
