/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:43:33 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/06 12:12:14 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	extend_key_down_2p(int kcode, t_cub *cub)
{
	if (kcode == KEY_SPACE && ++cub->mlx->keys->shootbis == 1
		&& cub->map->playerbis->state != DEAD)
		cub->map->playerbis->state = SHOOTING;
	else if (kcode == KEY_ENTER_PAD && ++cub->mlx->keys->shoot == 1
		&& cub->map->player->state != DEAD)
		cub->map->player->state = SHOOTING;
	else if (kcode == KEY_Q && ++cub->mlx->keys->weap_switchbis == 1)
		cub->map->playerbis->weapon = !cub->map->playerbis->weapon;
	else if (kcode == KEY_7 && ++cub->mlx->keys->weap_switch == 1)
		cub->map->player->weapon = !cub->map->player->weapon;
	return (0);
}

static int	extend_key_released_2p(int kcode, t_cub *cub)
{
	if (kcode == KEY_Q)
		cub->mlx->keys->weap_switchbis = 0;
	if (kcode == KEY_7)
		cub->mlx->keys->weap_switch = 0;
	return (0);
}

int	key_down_2p(int kcode, t_cub *cub)
{
	if (kcode == KEY_ESC)
		mlx_exit(0);
	else if (kcode == KEY_8 || kcode == KEY_5)
		cub->mlx->keys->vertical = (kcode == KEY_8) - (kcode == KEY_5);
	else if (kcode == KEY_W || kcode == KEY_S)
		cub->mlx->keys->verticalbis = (kcode == KEY_W) - (kcode == KEY_S);
	else if (kcode == KEY_4 || kcode == KEY_6)
		cub->mlx->keys->steering = (kcode == KEY_4) - (kcode == KEY_6);
	else if (kcode == KEY_A || kcode == KEY_D)
		cub->mlx->keys->steeringbis = (kcode == KEY_A) - (kcode == KEY_D);
	else if (kcode == KEY_SHIFT)
		cub->mlx->keys->sprintbis = 1;
	else if (kcode == KEY_RIGHT)
		cub->mlx->keys->sprint = 1;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = (kcode == KEY_PLUS) - (kcode == KEY_MINUS);
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->dist_feel = (kcode == KEY_PLUS_PAD)
			- (kcode == KEY_MINUS_PAD);
	else if (kcode == KEY_E && ++cub->mlx->keys->doorbis == 1)
		try_door(cub->map->playerbis, cub->map->doors);
	else if (kcode == KEY_9 && ++cub->mlx->keys->door == 1)
		try_door(cub->map->player, cub->map->doors);
	return (extend_key_down_2p(kcode, cub));
}

	// printf("key %10d\n", kcode);
int	key_released_2p(int kcode, t_cub *cub)
{
	if (kcode == KEY_8 || kcode == KEY_5)
		cub->mlx->keys->vertical = 0;
	else if (kcode == KEY_W || kcode == KEY_S)
		cub->mlx->keys->verticalbis = 0;
	else if (kcode == KEY_4 || kcode == KEY_6)
		cub->mlx->keys->steering = 0;
	else if (kcode == KEY_D || kcode == KEY_A)
		cub->mlx->keys->steeringbis = 0;
	else if (kcode == KEY_SHIFT)
		cub->mlx->keys->sprintbis = 0;
	else if (kcode == KEY_RIGHT)
		cub->mlx->keys->sprint = 0;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		cub->mlx->keys->fov_width = 0;
	else if (kcode == KEY_E)
		cub->mlx->keys->doorbis = 0;
	else if (kcode == KEY_9)
		cub->mlx->keys->door = 0;
	else if (kcode == KEY_PLUS_PAD || kcode == KEY_MINUS_PAD)
		cub->mlx->keys->dist_feel = 0;
	else if (kcode == KEY_ENTER_PAD)
		cub->mlx->keys->shoot = 0;
	else if (kcode == KEY_SPACE)
		cub->mlx->keys->shootbis = 0;
	return (extend_key_released_2p(kcode, cub));
}
