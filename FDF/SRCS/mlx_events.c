/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:41:00 by marvin            #+#    #+#             */
/*   Updated: 2022/10/22 20:41:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"

int	mlx_exit(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->overlay);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS); //+ some of those frees ?
}

int	mouse_button_pressed(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	ft_printf("mouse button %d pressed at location (%d, %d) on window %s\n", button, x, y, mlx->title);
	return (0);
}
//#include <stdio.h>
int	key_pressed(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	//printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC || keycode == KEY_Q)
		mlx_exit(fdf->mlx);
	else if (keycode == KEY_Z || keycode == KEY_N)
		rotation_z(fdf, keycode == KEY_N);
	else if (keycode == KEY_Y || keycode == KEY_T)
		rotation_y(fdf, keycode == KEY_T);
	else if (keycode == KEY_X || keycode == KEY_O)
		rotation_x(fdf, keycode == KEY_O);
	else if (keycode == KEY_R || keycode == KEY_E)
	{
		fdf->map->ratio += 0.5 * (1 - 2 * (keycode == KEY_E));
		if (fdf->map->ratio > -0.5 && fdf->map->ratio < 0.5)
			fdf->map->ratio = 0;
	}
	else if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		fdf->mlx->offset_x += 100 * (1 - 2 * (keycode == KEY_A || keycode == KEY_LEFT));
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_UP || keycode == KEY_DOWN)
		fdf->mlx->offset_y += 100 * (1 - 2 * (keycode == KEY_W || keycode == KEY_UP));
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_PLUS_PAD || keycode == KEY_MINUS_PAD)
	{
		fdf->mlx->size_x += 100 * (1 - 2 * (keycode == KEY_MINUS || keycode == KEY_MINUS_PAD));
		fdf->mlx->size_y += 100 * (1 - 2 * (keycode == KEY_MINUS || keycode == KEY_MINUS_PAD));
		fdf->mlx->offset_x += 50 * (1 - 2 * (keycode == KEY_PLUS || keycode == KEY_PLUS_PAD));
		fdf->mlx->offset_y += 50 * (1 - 2 * (keycode == KEY_PLUS || keycode == KEY_PLUS_PAD));
	}
	else if (keycode == KEY_P)
	{
		if (fdf->map->ratio != fdf->map->max_value)
			fdf->map->ratio = fdf->map->max_value;
		else
			fdf->map->ratio = (float)fdf->map->maplen / 5.0 + (fdf->map->maplen < 10);
	}
	else if (keycode == KEY_C)
		fdf->map->colors_enable = !fdf->map->colors_enable;
	mlx_clear_img(fdf->mlx->img, 0x0);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	// mlx_clear_img(fdf->mlx->overlay, 0x0);
	// mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->overlay->img_ptr, 20, 20);
	return (0);
}
