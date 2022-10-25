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

int	key_pressed(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	//printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC || keycode == KEY_Q)
		mlx_exit(fdf->mlx);
	else if (keycode == KEY_Z || keycode == KEY_N)
	{
		mlx_clear_img(fdf->mlx, 0x0);
		fdf->angles->gamma += (M_PI / 180) * (1 - 2 * (keycode == KEY_N));
		fdf->angles->sg = sin(fdf->angles->gamma);
		fdf->angles->cg = cos(fdf->angles->gamma);
		mlx_map_img(fdf);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	}
	else if (keycode == KEY_Y || keycode == KEY_T)
	{
		mlx_clear_img(fdf->mlx, 0x0);
		fdf->angles->beta += (M_PI / 180) * (1 - 2 * (keycode == KEY_T));
		fdf->angles->sb = sin(fdf->angles->beta);
		fdf->angles->cb = cos(fdf->angles->beta);
		mlx_map_img(fdf);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	}
	else if (keycode == KEY_X || keycode == KEY_O)
	{
		mlx_clear_img(fdf->mlx, 0x0);
		fdf->angles->alpha += (M_PI / 180) * (1 - 2 * (keycode == KEY_O));
		fdf->angles->sa = sin(fdf->angles->alpha);
		fdf->angles->ca = cos(fdf->angles->alpha);
		mlx_map_img(fdf);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	}
	else if (keycode == KEY_R || keycode == KEY_E)
	{
		mlx_clear_img(fdf->mlx, 0x0);
		fdf->map->ratio += 0.5 * (1 - 2 * (keycode == KEY_E));
		if (fdf->map->ratio > -0.5 && fdf->map->ratio < 0.5)
			fdf->map->ratio = 0;
		mlx_map_img(fdf);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		mlx_clear_img(fdf->mlx, 0x0);
		fdf->mlx->offset_x += 100 * (1 - 2 * (keycode == KEY_A));
		mlx_map_img(fdf);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	}
	else if (keycode == KEY_W || keycode == KEY_S)
	{
		mlx_clear_img(fdf->mlx, 0x0);
		fdf->mlx->offset_y += 100 * (1 - 2 * (keycode == KEY_W));
		mlx_map_img(fdf);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	}
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
	{
		mlx_clear_img(fdf->mlx, 0x0);
		fdf->mlx->size_x += 100 * (1 - 2 * (keycode == KEY_MINUS));
		fdf->mlx->size_y += 100 * (1 - 2 * (keycode == KEY_MINUS));
		fdf->mlx->offset_x += 50 * (1 - 2 * (keycode == KEY_PLUS));
		fdf->mlx->offset_y += 50 * (1 - 2 * (keycode == KEY_PLUS));
		mlx_map_img(fdf);
		mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img->img_ptr, 0, 0);
	}
	return (0);
}
