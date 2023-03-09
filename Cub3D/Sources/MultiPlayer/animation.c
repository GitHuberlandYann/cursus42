/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:03:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 15:17:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	shootframe(t_player *player, t_player *other)
{
	t_obj	*obj;

	obj = player->rays[WIN_WIDTH_2].objs;
	while (obj)
	{
		if (obj->type == HUMAN)
		{
			--other->hp;
			if (!other->hp)
			{
				other->state = DEAD;
				other->obj->frame_shoot = 0;
			}
		}
		obj = obj->next;
	}
}

static void	update_dying_frames(t_player *player)
{
	if (player->obj->frame_shoot == 4)
		return ;
	++player->obj->frame_shoot;
}

static void	update_shooting_player(t_mlx *mlx, t_player *player)
{
	if (mlx->frame_count)
		return ;
	if (player->state == DEAD)
		return (update_dying_frames(player));
	if (player->state == SHOOTING)
	{
		++player->obj->frame_shoot;
		if (player->obj->frame_shoot > 3)
		{
			player->state = IDLE;
			player->obj->frame_shoot = 0;
		}
		else if (player->obj->frame_shoot == 2 && player->other->state != DEAD)
			shootframe(player, player->other);
	}
}

void	update_shooting_frames(t_mlx *mlx, t_player *player,
	t_player *playerbis)
{
	update_shooting_player(mlx, player);
	update_shooting_player(mlx, playerbis);
}
