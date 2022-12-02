/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:07:18 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 17:07:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	mlx_exit(void *param)
{
	t_fdf	*fdf;
	t_mlx	*mlx;

	fdf = param;
	mlx = fdf->mlx;
	// if (mlx->img && mlx->mlx_ptr)
	// 	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	// if (mlx->win_ptr)
	// 	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_free_map(fdf->map);
	exit(EXIT_SUCCESS);
}

int	key_down(int kcode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (kcode == KEY_ESC || kcode == KEY_Q)
		mlx_exit(fdf->mlx);
	else if (kcode == KEY_E || kcode == KEY_R)
		fdf->mlx->key->rot_z = (kcode == KEY_E) - (kcode == KEY_R);
	else if (kcode == KEY_W || kcode == KEY_S)
		fdf->mlx->key->rot_y = (kcode == KEY_W) - (kcode == KEY_S);
	else if (kcode == KEY_A || kcode == KEY_D)
		fdf->mlx->key->rot_x = (kcode == KEY_A) - (kcode == KEY_D);
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		fdf->mlx->key->horizontal = (kcode == KEY_RIGHT) - (kcode == KEY_LEFT);
	else if (kcode == KEY_UP || kcode == KEY_DOWN)
		fdf->mlx->key->vertical = (kcode == KEY_DOWN) - (kcode == KEY_UP);
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		fdf->mlx->key->zoom = (kcode == KEY_PLUS) - (kcode == KEY_MINUS);
	return (0);
}

int	key_released(int kcode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (kcode == KEY_E || kcode == KEY_R)
		fdf->mlx->key->rot_z = 0;
	else if (kcode == KEY_W || kcode == KEY_S)
		fdf->mlx->key->rot_y = 0;
	else if (kcode == KEY_A || kcode == KEY_D)
		fdf->mlx->key->rot_x = 0;
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		fdf->mlx->key->horizontal = 0;
	else if (kcode == KEY_UP || kcode == KEY_DOWN)
		fdf->mlx->key->vertical = 0;
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		fdf->mlx->key->zoom = 0;
	return (0);
}
