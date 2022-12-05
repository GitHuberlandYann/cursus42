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

#include "fdf_edit.h"

static void	exec_keys(t_key *keys, t_fdf *fdf)
{
	if (keys->rot_x)
	{
		fdf->angles->alpha += 2 * (M_PI / 180) * keys->rot_x;
		fdf->angles->sa = sin(fdf->angles->alpha);
		fdf->angles->ca = cos(fdf->angles->alpha);
	}
	if (keys->rot_y)
	{
		fdf->angles->beta += 2 * (M_PI / 180) * keys->rot_y;
		fdf->angles->sb = sin(fdf->angles->beta);
		fdf->angles->cb = cos(fdf->angles->beta);
	}
	if (keys->rot_z)
	{
		fdf->angles->gamma += 2 * (M_PI / 180) * keys->rot_z;
		fdf->angles->sg = sin(fdf->angles->gamma);
		fdf->angles->cg = cos(fdf->angles->gamma);
	}
	fdf->mlx->offset_x += 100 * keys->horizontal;
	fdf->mlx->offset_y += 100 * keys->vertical;
	fdf->mlx->size += keys->zoom;
	ft_edit_edit(keys->edit, fdf);
}

static void	mlx_clear_img(t_mlx *mlx, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_SIZE_X)
	{
		y = 0;
		while (y < WIN_SIZE_Y)
		{
			ft_mlx_pixel_put(mlx, x, y, color);
			y ++;
		}
		x ++;
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

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color_mode)
{
	char	*dst;
	int		color;
	t_img	*img;

	if (y < 0 || y >= WIN_SIZE_Y || x < 0 || x >= WIN_SIZE_X)
		return ;
	if (!color_mode)
		color = 0x949494;
	else if (color_mode == -1)
		color = 0x0;
	else
		color = ft_mlx_pixel_get(mlx->back, x, y);
	img = mlx->img;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	mlx_draw(void *param)
{
	t_fdf	*fdf;
	t_key	*key;

	fdf = param;
	key = fdf->mlx->key;
	if (!key->rot_x && !key->rot_y && !key->rot_z && !key->horizontal
		&& !key->vertical && !key->zoom && key->color != 1 && !key->edit)
		return (1);
	exec_keys(fdf->mlx->key, fdf);
	mlx_clear_img(fdf->mlx, -!fdf->mlx->color_mode);
	mlx_map_img(fdf);
	mlx_map_edit(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
		fdf->mlx->img->img_ptr, 0, 0);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
		fdf->mlx->edit->img_ptr, WIN_SIZE_X - EDIT_WIDTH - 20, 20);
	return (0);
}
