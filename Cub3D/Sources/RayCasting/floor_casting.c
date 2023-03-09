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

static void	getset_pixel(t_img *img, t_img *(text[2]), t_vert *src, t_vert *dst)
{
	unsigned int	color;

	color = mlx_pxl_get(text[FLOOR], src->x, src->y);
	mlx_pxl_put(img, dst->x, dst->y, color);
	if (text[CEILLING])
	{
		color = mlx_pxl_get(text[CEILLING], src->x, src->y);
		mlx_pxl_put(img, dst->x, img->height - dst->y, color);
	}
}

/*	rsd.x = row				*
 *	rsd.y = straight_dist	*
 *	rsd.z = dist			*/
void	render_ground(t_img *img, t_cub *cub, t_vert *pxl, t_ray *ray)
{
	t_vert	rsd;
	t_vert	floor_pt;
	t_vert	cosin;
	t_img	*(fc_textures[2]);

	cosin.x = cos(ray->angle);
	cosin.y = sin(ray->angle);
	cosin.z = cos(ray->preangle);
	rsd.x = pxl->y - img->height / 2;
	fc_textures[FLOOR] = cub->mlx->fc_textures[FLOOR];
	fc_textures[CEILLING] = cub->mlx->fc_textures[CEILLING];
	while (pxl->y < img->height)
	{
		rsd.y = img->height / 2 * fc_textures[FLOOR]->width
			* (2 - cub->settings->dist_feel) / rsd.x;
		rsd.z = rsd.y / cosin.z;
		floor_pt.x = fabs(ft_fmod(fc_textures[FLOOR]->atplayer.x
					+ cosin.x * rsd.z, fc_textures[FLOOR]->width));
		floor_pt.y = fabs(ft_fmod(fc_textures[FLOOR]->atplayer.y
					- cosin.y * rsd.z, fc_textures[FLOOR]->height));
		getset_pixel(img, fc_textures, &floor_pt, pxl);
		++pxl->y;
		++rsd.x;
	}
}
