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
#include <stdio.h>
int	key_pressed(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	//ft_printf("key <%d> pressed on window %s\n", keycode, fdf->mlx->title);
	if (keycode == KEY_ESC)
		mlx_exit(fdf->mlx);
	else if (keycode == KEY_Z || keycode == KEY_N)
	{
		mlx_fill_background(fdf->mlx, 0x0);
		fdf->angles->gamma += (M_PI / 180) * (1 - 2 * (keycode == KEY_N));
		fdf->angles->sg = sin(fdf->angles->gamma);
		fdf->angles->cg = cos(fdf->angles->gamma);
		mlx_display_map(fdf);
	}
	else if (keycode == KEY_Y || keycode == KEY_T)
	{
		mlx_fill_background(fdf->mlx, 0x0);
		fdf->angles->beta += (M_PI / 180) * (1 - 2 * (keycode == KEY_T));
		fdf->angles->sb = sin(fdf->angles->beta);
		fdf->angles->cb = cos(fdf->angles->beta);
		mlx_display_map(fdf);
	}
	else if (keycode == KEY_X || keycode == KEY_O)
	{
		mlx_fill_background(fdf->mlx, 0x0);
		fdf->angles->alpha += (M_PI / 180) * (1 - 2 * (keycode == KEY_O));
		fdf->angles->sa = sin(fdf->angles->alpha);
		fdf->angles->ca = cos(fdf->angles->alpha);
		mlx_display_map(fdf);
	}
	return (0);
}
