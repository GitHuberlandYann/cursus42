/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:14:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/27 12:16:31 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	gradient_col(unsigned cola, unsigned colb, double percent)
{
	t_vertice		a;
	t_vertice		b;
	t_vertice		col;

	a.x = (cola / 0x10000);
	a.y = (cola / 0x100 - a.x * 0x100);
	a.z = (cola - a.y * 0x100 - a.x * 0x10000);
	b.x = (colb / 0x10000);
	b.y = (colb / 0x100 - b.x * 0x100);
	b.z = (colb - b.y * 0x100 - b.x * 0x10000);
	col.x = a.x + percent * (b.x - a.x);
	col.y = a.y + percent * (b.y - a.y);
	col.z = a.z + percent * (b.z - a.z);
	return ((int)col.z + (int)col.y * 0x100 + (int)col.x * 0x10000);
}

static double	percent_col(double start, double end, double percent)
{
	return ((percent - start) / (end - start));
}

unsigned int	get_color(double z, int max, int boo, t_col *c)
{
	double			prc;
	unsigned int	res;

	prc = -z / (double)max;
	if (!boo)
	{
		if (prc <= 0.0)
			res = gradient_col(0xC1FF, 0x50, percent_col(0, -1.0, prc));
		else if (prc <= 0.32)
			res = gradient_col(0x26E07, 0xACFDB0, percent_col(0, 0.32, prc));
		else if (prc <= 0.60)
			res = gradient_col(0x785801, 0xdbba5e,
					percent_col(0.32, 0.60, prc));
		else
			res = 0xffffff;
	}
	else
	{
		if (prc <= 0.0)
			res = gradient_col(c->zero, c->bottom, percent_col(0, -1.0, prc));
		else
			res = gradient_col(c->zero, c->top, percent_col(0, 1.0, prc));
	}
	return (res);
}

void	ft_create_hexa(t_mlx *mlx)
{
	mlx->hex = malloc(sizeof(*mlx->hex));
	if (!mlx->hex)
		ft_perror(__func__);
	mlx->hex->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"maps_xpm/img_colormap.xpm", &mlx->hex->width, &mlx->hex->height);
	mlx->hex->addr = mlx_get_data_addr(mlx->hex->img_ptr,
			&mlx->hex->bits_per_pixel, &mlx->hex->line_length,
			&mlx->hex->endian);
	mlx->hex->x = mlx->overlay->x + (OL_WIDTH - mlx->hex->width) / 2;
	mlx->hex->y = mlx->overlay->y + (OL_HEIGHT - mlx->hex->height) / 2;
	mlx->hex->type = 0;
}

void	mlx_pxl_put(t_mlx *mlx, t_vertice pt, int max, int color_mode)
{
	char	*dst;
	int		color;
	t_img	*img;
	int		x;
	int		y;

	if (pt.y < 0 || pt.y >= WIN_HEIGHT || pt.x < 0 || pt.x >= WIN_WIDTH)
		return ;
	if (!color_mode)
		color = mlx->col->zero;
	else if (color_mode == -1)
		color = 0x0;
	else if (color_mode == 2)
		color = ft_mlx_pixel_get(mlx->back, pt.x, pt.y);
	else
		color = get_color(pt.z, max, color_mode == 1, mlx->col);
	img = mlx->img;
	x = pt.x;
	y = pt.y;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
