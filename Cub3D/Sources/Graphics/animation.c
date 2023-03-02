/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:04:59 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/27 13:04:59 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_player_frames(t_map *map, t_mlx *mlx, t_key *keys, int fps)
{
	if (!map->playerbis)
		return ;
	mlx->frame_count += 60.0 / fps;
	if (mlx->frame_count > ANIM_FPS)
	{
		mlx->frame_count = 0;
		++mlx->curr_frame;
		if (mlx->curr_frame > 3)
			mlx->curr_frame = 0;
		keys->mousedate = 1;
	}
}

void	update_anim_frames(t_map *map, t_mlx *mlx, t_key *keys, int fps)
{
	if (!map->anims || map->anims->next == map->anims)
		return (update_player_frames(map, mlx, keys, fps));
	map->anims->frame_count += 60.0 / fps;
	if (map->anims->frame_count > ANIM_FPS)
	{
		map->anims = map->anims->next;
		map->anims->frame_count = 0;
	}
	keys->mousedate = 1;
	update_player_frames(map, mlx, keys, fps);
}

void	update_doors(t_door *doors, t_key *key)
{
	while (doors)
	{
		if (doors->state == OPENING)
		{
			key->mousedate = 1;
			if (doors->side == WE || doors->side == EA)
			{
				doors->edges[1].pt1.y += 0.01;
				doors->edges[1].pt2.y += 0.01;
			}
			else if (doors->side == NO || doors->side == SO)
			{
				doors->edges[1].pt1.x += 0.01;
				doors->edges[1].pt2.x += 0.01;
			}
			if (doors->edges[1].pt1.x > doors->x + 0.5 || doors->edges[1].pt1.y > doors->y + 0.5)
			{
				doors->state = OPEN;
				doors->timer = get_time();
				doors->edges[1].side = CUT;
			}
		}
		else if (doors->state == CLOSING)
		{
			key->mousedate = 1;
			doors->edges[1].side = DOOR;
			if (doors->side == WE || doors->side == EA)
			{
				doors->edges[1].pt1.y -= 0.01;
				doors->edges[1].pt2.y -= 0.01;
			}
			else if (doors->side == NO || doors->side == SO)
			{
				doors->edges[1].pt1.x -= 0.01;
				doors->edges[1].pt2.x -= 0.01;
			}
			if (doors->edges[1].pt1.y < doors->y - 0.5 || doors->edges[1].pt1.x < doors->x - 0.5)
				doors->state = CLOSED;
		}
		if (doors->state == OPEN && get_time() - doors->timer > DOOR_TIMER)
			doors->state = CLOSING;
		doors = doors->next;
	}
}
