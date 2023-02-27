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

void	update_anim_frames(t_map *map, t_key *keys, int fps)
{
	if (!map->anims || map->anims->next == map->anims)
		return ;
	map->anims->frame_count += 60.0 / fps;
	if (map->anims->frame_count > ANIM_FPS)
	{
		map->anims = map->anims->next;
		map->anims->frame_count = 0;
	}
	keys->mousedate = 1;
}
