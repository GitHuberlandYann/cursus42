/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/26 20:21:25 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//#include <stdio.h>
static void	mlx_draw_line(t_fdf *fdf, int ax, int ay, int bx, int by, int ar, int ac, int br, int bc)
{
	float	pixelx;
	float	pixely;
	float	dx;
	float	dy;
	float	m;
	float	len;
	float	heighta;
	float	deltaheightb;

	dx = bx - ax;
	dy = by - ay;
	m = dy / dx;
	len = sqrt(dx * dx + dy * dy);
	dx /= len;
	dy /= len;
	pixelx = ax;
	pixely = ay;
	heighta = (float)fdf->map->map[ar][ac] / (float)fdf->map->max_value;
	deltaheightb = (float)fdf->map->map[br][bc] / (float)fdf->map->max_value - heighta;
	if (!fdf->map->max_value)
	{
		heighta = 0;
		deltaheightb = 0;
	}
	deltaheightb /= len;
	while (len > 0)
	{
		my_mlx_pixel_put(fdf->mlx->img, pixelx, pixely, ft_get_color(heighta, fdf->map->colors_enable, fdf->map->ratio));
		pixelx += dx;
		if (dx)
			pixely = m * (pixelx - ax) + ay;
		else
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

void	mlx_map_img(t_fdf *fdf)
{
	int	***copy;
	int	row;
	int	col;

	copy = ft_mapdup(fdf);
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

// static void	mlx_border_overlay(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < OVERLAY_SIZE_X - 1)
// 		my_mlx_pixel_put(fdf->mlx->overlay, x++, y, 0xffffff);
// 	while (y < OVERLAY_SIZE_Y - 1)
// 		my_mlx_pixel_put(fdf->mlx->overlay, x, y++, 0xffffff);
// 	while (x > 0)
// 		my_mlx_pixel_put(fdf->mlx->overlay, x--, y, 0xffffff);
// 	while (y > 0)
// 		my_mlx_pixel_put(fdf->mlx->overlay, x, y--, 0xffffff);
// }

int	mlx_related_stuff(t_fdf *fdf, char *title)
{
	fdf->mlx = malloc(sizeof(*fdf->mlx));
	if (!fdf->mlx)
		return (-1);
	fdf->mlx->mlx_ptr = mlx_init();
	if (fdf->mlx->mlx_ptr)
	{
		fdf->mlx->size_x = WIN_SIZE_X / 2;
		fdf->mlx->size_y = WIN_SIZE_Y / 2;
		fdf->mlx->offset_x = WIN_SIZE_X / 4;
		fdf->mlx->offset_y = WIN_SIZE_Y / 4;
		fdf->mlx->title = title;
		fdf->mlx->win_ptr = mlx_new_window(fdf->mlx->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, fdf->mlx->title);
		if (fdf->mlx->win_ptr)
		{
			ft_create_img(fdf->mlx);
			ft_create_overlay(fdf->mlx);
			mlx_map_img(fdf);
			mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
			// mlx_border_overlay(fdf);
			// mlx_map_overlay(fdf);
			// mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->overlay->img_ptr, 20, 20);
			mlx_mouse_hook(fdf->mlx->win_ptr, mouse_button_pressed, fdf->mlx);
			mlx_hook(fdf->mlx->win_ptr, ON_KEYDOWN, 0, key_pressed, fdf);
			mlx_hook(fdf->mlx->win_ptr, ON_DESTROY, 0, mlx_exit, fdf->mlx); //x_mask not supported
			mlx_loop(fdf->mlx->mlx_ptr);
		}
		else
			ft_putstr("mlx_new_window failed.\n");
	}
	else
		ft_putstr("mlx_init failed.\n");
	return (0);
}
