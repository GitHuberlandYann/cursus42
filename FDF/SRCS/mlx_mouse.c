/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:02:05 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/16 15:59:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_button_pressed(int button, int x, int y, t_fdf *fdf)
{
	t_mlx			*mlx;
	unsigned int	col;

	mlx = fdf->mlx;
	if (mlx->hexon && fdf->mlx->color_mode < 2)
	{
		if (x >= mlx->hex->x && x < mlx->hex->x + mlx->hex->width
			&& y >= mlx->hex->y && y < mlx->hex->y + mlx->hex->height)
		{
			col = ft_mlx_pixel_get(mlx->hex, x - mlx->hex->x, y - mlx->hex->y)
				% 0xff000000;
			if (fdf->mlx->color_mode == 1)
			{
				if (button == MOUSE_LEFT)
					mlx->col->top = col;
				else if (button == MOUSE_RIGHT)
					mlx->col->bottom = col;
				else
					mlx->col->zero = col;
			}
			else if (fdf->mlx->color_mode == 0)
				mlx->col->zero = col;
		}
	}
	return (0);
}
