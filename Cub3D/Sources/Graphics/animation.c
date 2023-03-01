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
		keys->mousedate = 1;
	}
	update_player_frames(map, mlx, keys, fps);
}
