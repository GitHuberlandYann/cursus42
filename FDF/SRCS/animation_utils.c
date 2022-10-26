/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:40:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/26 14:46:47 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_fdf * fdf, int	rotation)
{
	mlx_clear_img(fdf->mlx, 0x0);
	fdf->angles->alpha += (M_PI / 180) * (1 - 2 * rotation);
	fdf->angles->sa = sin(fdf->angles->alpha);
	fdf->angles->ca = cos(fdf->angles->alpha);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
}

void	rotation_y(t_fdf *fdf, int rotation)
{
	mlx_clear_img(fdf->mlx, 0x0);
	fdf->angles->beta += (M_PI / 180) * (1 - 2 * rotation);
	fdf->angles->sb = sin(fdf->angles->beta);
	fdf->angles->cb = cos(fdf->angles->beta);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
}

void	rotation_z(t_fdf *fdf, int rotation)
{
	mlx_clear_img(fdf->mlx, 0x0);
	fdf->angles->gamma += (M_PI / 180) * (1 - 2 * rotation);
	fdf->angles->sg = sin(fdf->angles->gamma);
	fdf->angles->cg = cos(fdf->angles->gamma);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
}