/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_renders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:24:38 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 14:25:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_render(t_img *canva, unsigned int cols[2], t_cub *cub)
{
	t_vert	pt;
	double	limiter;

	pt.z = 0;
	pt.y = 0;
	limiter = canva->height;
	if (cub->mlx->fc_textures[CEILLING])
		pt.y = canva->height / 2;
	if (cub->mlx->fc_textures[FLOOR])
		limiter = canva->height / 2;
	while (pt.y < limiter)
	{
		pt.x = -1;
		while (++pt.x < canva->width)
			mlx_pxl_put(canva, pt.x, pt.y, cols[pt.y < canva->height / 2]);
		++pt.y;
	}
}

void	setup_rendermap(t_img *canva, t_set *settings)
{
	t_vert	pt;

	pt.y = settings->offset.y;
	while (pt.y < settings->offset.y + MAP_DIAMETER)
	{
		pt.x = settings->offset.x;
		while (pt.x < settings->offset.x + MAP_DIAMETER)
		{
			pt.z = sqrt(pow(pt.x - (MAP_RADIUS + settings->offset.x), 2)
					+ pow(pt.y - (MAP_RADIUS + settings->offset.y), 2));
			if (pt.z <= MAP_RADIUS)
			{
				if (pt.z <= MAP_RADIUS - 5)
					mlx_pxl_put(canva, pt.x, pt.y, BLACK);
				else
					mlx_pxl_put(canva, pt.x, pt.y, WHITE);
			}
			++pt.x;
		}
		++pt.y;
	}
}
