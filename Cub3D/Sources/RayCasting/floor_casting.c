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

void	render_ground(t_img *img, t_cub *cub, t_vert *pxl, double alpha, t_player *player)
{
	double		row;
	double		straight_dist;
	double		dist;
	t_vert		floor_pt;
	t_vert		cosin;
	unsigned	color;
	t_img		*(fc_textures[2]);

	cosin.x = cos(alpha);
	cosin.y = sin(alpha);
	cosin.z = cos(alpha - player->direction);
	row = pxl->y - img->height / 2;
	fc_textures[FLOOR] = cub->mlx->fc_textures[FLOOR];
	fc_textures[CEILLING] = cub->mlx->fc_textures[CEILLING];
	while (pxl->y < img->height)
	{
		straight_dist = img->height / 2 * fc_textures[FLOOR]->width * (2 - cub->settings->dist_feel) / row;
		dist = straight_dist / cosin.z;
		floor_pt.x = fabs(ft_fmod(fc_textures[FLOOR]->atplayer.x + cosin.x * dist, fc_textures[FLOOR]->width));
		floor_pt.y = fabs(ft_fmod(fc_textures[FLOOR]->atplayer.y - cosin.y * dist, fc_textures[FLOOR]->height));
		color = mlx_pxl_get(fc_textures[FLOOR], floor_pt.x, floor_pt.y);
		mlx_pxl_put(img, pxl->x, pxl->y, color);
		if (fc_textures[CEILLING])
		{
			color = mlx_pxl_get(fc_textures[CEILLING], floor_pt.x, floor_pt.y);
			mlx_pxl_put(img, pxl->x, img->height - pxl->y, color);
		}
		++pxl->y;
		++row;
	}
}
