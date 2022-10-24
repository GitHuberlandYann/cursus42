/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/24 18:13:58 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"

void	mlx_fill_background(t_mlx *mlx, int color) //color = 0x00RRGGBB
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < mlx->size_x)
	{
		y = 0;
		while (y < mlx->size_y)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
			y ++;
		}
		x ++;
	}
}
//#include <stdio.h>
static void	mlx_draw_line(t_fdf *fdf, int ax, int ay, int bx, int by, int ar, int ac, int br, int bc)
{
	float	pixelx;
	float	pixely;
	float	dx;
	float	dy;
	float	len;
	float	heighta;
	float	deltaheightb;

	dx = bx - ax;
	dy = by - ay;
	len = sqrt(dx * dx + dy * dy);
	dx /= len;
	dy /= len;
	pixelx = ax;
	pixely = ay;
	heighta = fdf->map->map[ar][ac] / fdf->map->max_value;
	deltaheightb = fdf->map->map[br][bc] / fdf->map->max_value - heighta;
	//printf("map ; %d, max : %d, heighta : %f, deltab : %f\n", fdf->map->map[ar][ac], fdf->map->max_value, heighta, deltaheightb);
	deltaheightb /= len;
	//printf("deltab : %f\n", deltaheightb);
	while (len > 0)
	{
		mlx_pixel_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, pixelx, pixely, ft_get_color(heighta, 0));
		pixelx += dx;
		pixely += dy;
		heighta += deltaheightb;
		--len;
	}
}

static void	mlx_link_node(t_fdf *fdf, int ***copy, int r, int c)
{
	if (c < fdf->map->rowlen - 1)
		mlx_draw_line(fdf, copy[r][c][0], copy[r][c][1], copy[r][c + 1][0], copy[r][c + 1][1], r, c, r, c + 1);
	if (r < fdf->map->maplen - 1)
		mlx_draw_line(fdf, copy[r][c][0], copy[r][c][1], copy[r + 1][c][0], copy[r + 1][c][1], r, c, r + 1, c);
}

void	mlx_display_map(t_fdf *fdf)
{
	int	***copy;
	int	row;
	int	col;

	copy = ft_mapdup(fdf->mlx, fdf->map, fdf->angles);
	if (!copy)
		mlx_exit(fdf->mlx);
	row = 0;
	while (row < fdf->map->maplen)
	{
		col = 0;
		while (col < fdf->map->rowlen)
		{
			mlx_link_node(fdf, copy, row, col);
			++col;
		}
		++row;
	}
}

int	mlx_related_stuff(t_fdf *fdf, char *title)
{
	fdf->mlx = malloc(sizeof(*fdf->mlx));
	if (!fdf->mlx)
		return (-1);
	fdf->mlx->mlx_ptr = mlx_init();
	if (fdf->mlx->mlx_ptr)
	{
		fdf->mlx->size_x = WIN_SIZE_X;
		fdf->mlx->size_y = WIN_SIZE_Y;
		fdf->mlx->title = title;
		fdf->mlx->win_ptr = mlx_new_window(fdf->mlx->mlx_ptr, fdf->mlx->size_x, fdf->mlx->size_y, fdf->mlx->title);
		if (fdf->mlx->win_ptr)
		{
			mlx_fill_background(fdf->mlx, 0x0);
			mlx_display_map(fdf);
			mlx_mouse_hook(fdf->mlx->win_ptr, mouse_button_pressed, fdf->mlx);
			mlx_key_hook(fdf->mlx->win_ptr, key_pressed, fdf);
			mlx_hook(fdf->mlx->win_ptr, ON_DESTROY, 0, &mlx_exit, fdf->mlx); //x_mask not supported
			mlx_loop(fdf->mlx->mlx_ptr);
		}
		else
			ft_putstr("mlx_new_window failed.\n");
	}
	else
		ft_putstr("mlx_init failed.\n");
	return (0);
}
