/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:03:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/06 12:26:10 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_shooting_frames(t_mlx *mlx, t_player *player,
	t_player *playerbis)
{
	if (!mlx->frame_count)
	{
		if (player->state == SHOOTING)
		{
			++player->obj->frame_shoot;
			if (player->obj->frame_shoot > 3)
			{
				player->state = IDLE;
				player->obj->frame_shoot = 0;
			}
		}
		if (playerbis->state == SHOOTING)
		{
			++playerbis->obj->frame_shoot;
			if (playerbis->obj->frame_shoot > 3)
			{
				playerbis->state = IDLE;
				playerbis->obj->frame_shoot = 0;
			}
		}
	}
}
