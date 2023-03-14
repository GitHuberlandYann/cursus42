/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:48:04 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/14 10:24:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reset_player(t_player *player)
{
	set_point(&player->pos, player->starting_pos.x, player->starting_pos.y, 0);
	player->direction = player->starting_pos.z;
	player->state = IDLE;
	player->hp = PLAYERS_HP;
	player->weapon = 0;
	player->obj->frame_shoot = 0;
}

void	reset_players(t_player *player, t_player *other)
{
	if (player->state != DEAD && other->state != DEAD)
		return ;
	reset_player(player);
	reset_player(other);
}
