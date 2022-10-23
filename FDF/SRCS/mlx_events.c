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
	t_mlx	*mlx;

	mlx = param;
	ft_printf("key <%d> pressed on window %s\n", keycode, mlx->title);
	if (keycode == KEY_ESC)
		mlx_exit(mlx);
	return (0);
}
