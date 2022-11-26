/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:24:28 by marvin            #+#    #+#             */
/*   Updated: 2022/11/19 13:24:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_hexa(t_mlx *mlx)
{
	mlx->hex = malloc(sizeof(*mlx->hex));
	if (!mlx->hex)
		exit(1); //modif this perror
	mlx->hex->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "maps/img_colormap.xpm", &mlx->hex->width, &mlx->hex->height);
	mlx->hex->addr = mlx_get_data_addr(mlx->hex->img_ptr, &mlx->hex->bits_per_pixel, &mlx->hex->line_length,
								&mlx->hex->endian);
	mlx->hex->x = mlx->overlay->x + (OVERLAY_SIZE_X - mlx->hex->width) / 2;
	mlx->hex->y = mlx->overlay->y + (OVERLAY_SIZE_Y - mlx->hex->height) / 2;
	mlx->hex->type = 0;
}

unsigned int	ft_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;
	int		limit_x;
	int		limit_y;

	if (img->type)
	{
		limit_x = WIN_SIZE_X;
		limit_y = WIN_SIZE_Y;
	}
	else
	{
		limit_x = OVERLAY_SIZE_X;
		limit_y = OVERLAY_SIZE_Y;
	}
	if (y < 0 || y >= limit_y || x < 0 || x >= limit_x)
		return (0);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

//#include <stdio.h>
int	ft_get_color(float value, int colors, float ratio, t_col *col)
{
	int	res;

	if ((!colors || !value || !ratio) && colors != 2)
		return (col->zero);
	else if (colors == 1)
	{
		res = col->zero; //starting color
		if (value * ratio >= 0)
			res += (col->top - col->zero) * (fabsf(value)); //endcolor
		else
			res += (col->bottom - col->zero) * (fabsf(value));
	}
	else
	{
		if (value <= col->level0)
			res = 0xff;
		else if (value <= col->level1)
			res = 0xff00;
		else if (value <= col->level2)
			res = 0x800000;
		else
			res = col->zero;
	}
	return (res);
}
