/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:26:07 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 17:26:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	check_pressed(t_key *key)
{
	return (!key->rot_x && !key->rot_y && !key->rot_z && !key->horizontal
			&& !key->vertical && !key->zoom);
}

static void	exec_keys(t_key *keys, t_mlx *mlx)
{
	if (keys->rot_x)
	{
		fdf->angles->alpha += (M_PI / 180) * keys->rot_x;
		fdf->angles->sa = sin(fdf->angles->alpha);
		fdf->angles->ca = cos(fdf->angles->alpha);
	}
	if (keys->rot_y)
	{
		fdf->angles->beta += (M_PI / 180) * keys->rot_y;
		fdf->angles->sb = sin(fdf->angles->beta);
		fdf->angles->cb = cos(fdf->angles->beta);
	}
	if (keys->rot_z)
	{
		fdf->angles->gamma += (M_PI / 180) * keys->rot_z;
		fdf->angles->sg = sin(fdf->angles->gamma);
		fdf->angles->cg = cos(fdf->angles->gamma);
	}
	mlx->offset_x += 100 * keys->horizontal;
	mlx->offset_y += 100 * keys->vertical;
	mlx->size += 5 * keys->zoom;
}

static void	mlx_clear_img(t_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_SIZE_X)
	{
		y = 0;
		while (y < WIN_SIZE_Y)
		{
			ft_mlx_pixel_put(img, x, y, color);
			y ++;
		}
		x ++;
	}
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= WIN_SIZE_Y || x < 0 || x >= WIN_SIZE_X)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mlx_draw(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (check_pressed(fdf->mlx->key))
		return (1);
	exec_keys(fdf->mlx->key, fdf->mlx);
	mlx_clear_img(fdf->mlx->img, 0x0);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
							fdf->mlx->img->img_ptr, 0, 0);
	return (0);
}
