/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:35:38 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/13 10:35:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_ground(t_img *img, t_cub *cub, t_vertice *pxl, double alpha)
{
	double		beta;
	double		row;
	double		straight_dist;
	double		dist;
	t_vertice	floor_pt;
	unsigned	color;

	beta = alpha - cub->map->player->direction;
	while (pxl->y < WIN_HEIGHT)
	{
		row = pxl->y - WIN_HEIGHT / 2;
		straight_dist = WIN_HEIGHT / 2 * cub->mlx->fc_textures[FLOOR]->width * (2 - cub->settings->dist_feel) / row;
		dist = straight_dist / cos(beta);
		floor_pt.x = cub->map->player->pos.x * cub->mlx->fc_textures[FLOOR]->width + cos(alpha) * dist + cub->mlx->fc_textures[FLOOR]->width / 2;
		floor_pt.y = cub->map->player->pos.y * cub->mlx->fc_textures[FLOOR]->height - sin(alpha) * dist + cub->mlx->fc_textures[FLOOR]->height / 2;
		color = mlx_pxl_get(cub->mlx->fc_textures[FLOOR], fmod(floor_pt.x, cub->mlx->fc_textures[FLOOR]->width), fmod(floor_pt.y, cub->mlx->fc_textures[FLOOR]->height));
		mlx_pxl_put(img, pxl->x, pxl->y, color);
		if (cub->mlx->fc_textures[CEILLING])
		{
			color = mlx_pxl_get(cub->mlx->fc_textures[CEILLING], fmod(floor_pt.x, cub->mlx->fc_textures[CEILLING]->width), fmod(floor_pt.y, cub->mlx->fc_textures[CEILLING]->height));
			mlx_pxl_put(img, pxl->x, WIN_HEIGHT - pxl->y, color);
		}
		++pxl->y;
	}
}
