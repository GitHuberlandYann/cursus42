/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:59:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/17 14:59:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_cub *cub)
{
	if (!cub->mlx->mouse_pos.z)
	{
		cub->map->player->direction += (cub->mlx->mouse_pos.x - x) / 300;
		cub->mlx->keys->mousedate = 1;
	}	
	set_point(&cub->mlx->mouse_pos, x, y, 0);
	return (0);
}
