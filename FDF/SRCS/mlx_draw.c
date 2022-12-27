/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.45.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:06:37 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/15 10:06:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	exec_keys2(t_key *keys, t_fdf *fdf)
{
	if (keys->horizontal)
		fdf->mlx->offset_x += 100 * keys->horizontal;
	if (keys->vertical)
		fdf->mlx->offset_y += 100 * keys->vertical;
	if (keys->zoom)
	{
		fdf->mlx->size += (double)WIN_WIDTH / (double)(8 * fdf->map->width)
			* keys->zoom;
		if (fdf->mlx->size < 0)
			fdf->mlx->size = 0;
	}
}

static void	exec_keys(t_key *keys, t_fdf *fdf)
{
	if (keys->rot_x)
	{
		fdf->angles->alpha += 5 * (M_PI / 180) * keys->rot_x;
		fdf->angles->sa = sin(fdf->angles->alpha);
		fdf->angles->ca = cos(fdf->angles->alpha);
	}
	if (keys->rot_y)
	{
		fdf->angles->beta += 5 * (M_PI / 180) * keys->rot_y;
		fdf->angles->sb = sin(fdf->angles->beta);
		fdf->angles->cb = cos(fdf->angles->beta);
	}
	if (keys->rot_z)
	{
		fdf->angles->gamma += 5 * (M_PI / 180) * keys->rot_z;
		fdf->angles->sg = sin(fdf->angles->gamma);
		fdf->angles->cg = cos(fdf->angles->gamma);
	}
	if (keys->ratio)
	{
		fdf->map->ratio += 0.5 * keys->ratio;
		if (fdf->map->ratio > -0.5 && fdf->map->ratio < 0.5)
			fdf->map->ratio = 0;
	}
	exec_keys2(keys, fdf);
}

static void	mlx_clear_img(t_mlx *mlx, int color)
{
	t_vertice	pt;

	pt.x = 0;
	pt.z = 0;
	while (pt.x < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y < WIN_HEIGHT)
		{
			mlx_pxl_put(mlx, pt, 0, color);
			++pt.y;
		}
		++pt.x;
	}
}

unsigned int	ft_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;
	int		limit_x;
	int		limit_y;

	limit_x = img->width;
	limit_y = img->height;
	if (y < 0 || y >= limit_y || x < 0 || x >= limit_x)
		return (0);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	mlx_draw(t_fdf *fdf)
{
	t_key	*key;

	key = fdf->mlx->key;
	if (!key->rot_x && !key->rot_y && !key->rot_z && !key->horizontal
		&& !key->vertical && !key->zoom && key->color != 1 && !key->ratio
		&& key->sphere != 1 && !key->reset_ratio && key->fill != 1
		&& key->iso != 1 && key->overlay != 1 && !fdf->mlx->hexon)
		return (1);
	exec_keys(key, fdf);
	mlx_clear_img(fdf->mlx, -(fdf->mlx->color_mode < 2));
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
		fdf->mlx->img->img_ptr, 0, 0);
	if (fdf->mlx->hexon && fdf->mlx->color_mode < 2)
	{
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
			fdf->mlx->overlay->img_ptr, fdf->mlx->overlay->x,
			fdf->mlx->overlay->y);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
			fdf->mlx->hex->img_ptr, fdf->mlx->hex->x, fdf->mlx->hex->y);
	}
	return (0);
}
