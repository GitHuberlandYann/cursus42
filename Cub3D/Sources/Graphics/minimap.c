/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:52:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/12 14:55:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_rendermap(t_img *canva, t_settings *settings)
{
	t_vertice	pt;

	pt.z = 0;
	pt.y = settings->offset_y;
	while (pt.y < settings->offset_y + MAP_RADIUS * 2)
	{
		pt.x = settings->offset_x;
		while (pt.x < settings->offset_x + MAP_RADIUS * 2)
		{
			if (in_circle(&pt, MAP_RADIUS + settings->offset_x,
				MAP_RADIUS + settings->offset_y, MAP_RADIUS - 5))
			{
				if (in_circle(&pt, MAP_RADIUS + settings->offset_x,
					MAP_RADIUS + settings->offset_y, MAP_RADIUS - 10))
					mlx_pxl_put(canva, pt.x, pt.y, BLACK);
				else
					mlx_pxl_put(canva, pt.x, pt.y, WHITE);
			}
			++pt.x;
		}
		++pt.y;
	}
}

void	fill_minimap(t_cub *cub)
{
	(void)cub;
}
