/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:18:02 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/18 16:18:02 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"

int	mlx_exit(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS); //+ some of those frees ?
}

int	key_pressed(int key_code, void *param)
{
	(void)param;
	ft_printf("key %d pressed.\n", key_code);
	return (0);
}

int	mouse_button_pressed(int button, int x, int y, void *param)
{
	t_fdf			*fdf;
	t_mlx			*mlx;
	unsigned int	col;

	fdf = param;
	mlx = fdf->mlx;
	//ft_printf("mouse button %d pressed at location (%d, %d) on window %s\n", button, x, y, mlx->title);
	if (mlx->key->overlay)
	{
		if (x >= mlx->hex->x && x < mlx->hex->x + mlx->hex->width
				&& y >= mlx->hex->y && y < mlx->hex->y + mlx->hex->height)
		{
			col = ft_mlx_pixel_get(mlx->hex, x - mlx->hex->x, y - mlx->hex->y) % 0xff000000;
			//ft_printf("pixel at %d, %d : %x\n", x - mlx->hex->x, y - mlx->hex->y, col);
			if (fdf->map->colors_enable == 1)
			{
				if (button == 1)
					mlx->col_top = col;
				else
					mlx->col_bottom = col;
			}
			else if (fdf->map->colors_enable == 0)
				mlx->col_zero = col;
			else if (fdf->map->colors_enable == 2)
				mlx->col_zero = col;
		}
	}
	return (0);
}
//#include <stdio.h>
int	key_down(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	//printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC || keycode == KEY_Q)
		mlx_exit(fdf->mlx);
	else if (keycode == KEY_Z || keycode == KEY_N)
		fdf->mlx->key->rot_z = 2 * (keycode == KEY_Z) - 2 * (keycode == KEY_N);
	else if (keycode == KEY_Y || keycode == KEY_T)
		fdf->mlx->key->rot_y = 2 * (keycode == KEY_Y) - 2 * (keycode == KEY_T);
	else if (keycode == KEY_X || keycode == KEY_O)
		fdf->mlx->key->rot_x = 2 * (keycode == KEY_X) - 2 * (keycode == KEY_O);
	else if (keycode == KEY_R || keycode == KEY_E)
		fdf->mlx->key->ratio = 2 * (keycode == KEY_R) - 2 * (keycode == KEY_E);
	else if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		fdf->mlx->key->horizontal = ((keycode == KEY_D) + (keycode == KEY_RIGHT) - ((keycode == KEY_A) + (keycode == KEY_LEFT)));
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_UP || keycode == KEY_DOWN)
		fdf->mlx->key->vertical = ((keycode == KEY_S) + (keycode == KEY_DOWN) - ((keycode == KEY_W) + (keycode == KEY_UP)));
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_PLUS_PAD || keycode == KEY_MINUS_PAD)
		fdf->mlx->key->zoom = ((keycode == KEY_PLUS) + (keycode == KEY_PLUS_PAD) - ((keycode == KEY_MINUS) + (keycode == KEY_MINUS_PAD)));
	else if (keycode == KEY_P)
		fdf->mlx->key->reset_ratio = 1;
	else if (keycode == KEY_C && ++fdf->mlx->key->color == 1)
		fdf->map->colors_enable = !fdf->map->colors_enable + (2 * (fdf->map->colors_enable == 1));
	else if (keycode == KEY_1 || keycode == KEY_2)
		fdf->mlx->key->rot_special = 3 * (2 * (keycode == KEY_1) - 2 * (keycode == KEY_2));
	else if (keycode == KEY_H)
		fdf->mlx->key->overlay = 1;
	return (0);
}

int	key_released(int keycode, void *param)
{
	t_fdf *fdf;

	fdf = param;
	ft_printf("key released : %d\n", keycode);
	if (keycode == KEY_Z || keycode == KEY_N)
		fdf->mlx->key->rot_z = 0;
	else if (keycode == KEY_Y || keycode == KEY_T)
		fdf->mlx->key->rot_y = 0;
	else if (keycode == KEY_X || keycode == KEY_O)
		fdf->mlx->key->rot_x = 0;
	else if (keycode == KEY_R || keycode == KEY_E)
		fdf->mlx->key->ratio = 0;
	else if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		fdf->mlx->key->horizontal = 0;
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_UP || keycode == KEY_DOWN)
		fdf->mlx->key->vertical = 0;
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_PLUS_PAD || keycode == KEY_MINUS_PAD)
		fdf->mlx->key->zoom = 0;
	else if (keycode == KEY_P)
		fdf->mlx->key->reset_ratio = 0;
	else if (keycode == KEY_C)
		fdf->mlx->key->color = 0;
	else if (keycode == KEY_1 || keycode == KEY_2)
		fdf->mlx->key->rot_special = 0;
	else if (keycode == KEY_H)
		fdf->mlx->key->overlay = 0;
	return (0);
}

int	mlx_draw(void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (fdf->mlx->key->rot_x)
		rotation_x(fdf, fdf->mlx->key->rot_x);
	if (fdf->mlx->key->rot_y)
		rotation_y(fdf, fdf->mlx->key->rot_y);
	if (fdf->mlx->key->rot_z)
		rotation_z(fdf, fdf->mlx->key->rot_z);
	if (fdf->mlx->key->ratio)
	{
		fdf->map->ratio += 0.5 * fdf->mlx->key->ratio;
		if (fdf->map->ratio > -0.5 && fdf->map->ratio < 0.5)
			fdf->map->ratio = 0;
	}
	if (fdf->mlx->key->horizontal)
		fdf->mlx->offset_x += 100 * fdf->mlx->key->horizontal;
	if (fdf->mlx->key->vertical)
		fdf->mlx->offset_y += 100 * fdf->mlx->key->vertical;
	if (fdf->mlx->key->zoom)
	{
		fdf->mlx->size_x += 100 * fdf->mlx->key->zoom;
		fdf->mlx->size_y += 100 * fdf->mlx->key->zoom;
		fdf->mlx->offset_x -= 50 * fdf->mlx->key->zoom;
		fdf->mlx->offset_y -= 50 * fdf->mlx->key->zoom;
	}
	if (fdf->mlx->key->reset_ratio)
	{
		if (fdf->map->ratio != fdf->map->max_value)
			fdf->map->ratio = fdf->map->max_value;
		else
			fdf->map->ratio = (float)fdf->map->maplen / 5.0 + (fdf->map->maplen < 10);
	}
	if (fdf->mlx->key->rot_special)
	{
		rotation_x(fdf, fdf->mlx->key->rot_special);
		rotation_y(fdf, fdf->mlx->key->rot_special);
		rotation_z(fdf, fdf->mlx->key->rot_special);
	}
	mlx_clear_img(fdf->mlx->img, 0x0);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	if (fdf->mlx->key->overlay)
	{
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->overlay->img_ptr, fdf->mlx->overlay->x, fdf->mlx->overlay->y);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->hex->img_ptr, fdf->mlx->hex->x, fdf->mlx->hex->y);
	}
	return (0);
}
