/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:01:27 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/16 15:01:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_down_extendeded(int kcode, t_fdf *fdf)
{
	if (kcode == KEY_I && ++fdf->mlx->key->iso == 1)
	{
		set_angles(fdf->angles, 0, 0, 0);
		fdf->mlx->size = (double)WIN_WIDTH / (double)(2 * fdf->map->width);
		fdf->mlx->offset_x = WIN_WIDTH / 4;
		fdf->mlx->offset_y = WIN_HEIGHT / 4;
		fdf->mlx->col->zero = 0x949494;
		fdf->mlx->col->top = 0xff00ff;
		fdf->mlx->col->bottom = 0x80;
	}
	return (0);
}

static int	key_down_extended(int kcode, t_fdf *fdf)
{
	if (kcode == KEY_F && ++fdf->mlx->key->fill == 1)
		fdf->mlx->fill = !fdf->mlx->fill;
	else if (kcode == KEY_O && ++fdf->mlx->key->reset_ratio == 1)
	{
		if (fdf->map->ratio != fdf->map->max)
			fdf->map->ratio = fdf->map->max;
		else
			fdf->map->ratio = 0;
	}
	else if (kcode == KEY_P && ++ fdf->mlx->key->sphere == 1)
		fdf->mlx->sphere = !fdf->mlx->sphere;
	else if (kcode == KEY_V && ++fdf->mlx->key->color == 1)
		fdf->mlx->color_mode = fdf->mlx->color_mode - 1
			+ (4 * !fdf->mlx->color_mode);
	return (key_down_extendeded(kcode, fdf));
}

static int	key_released_extended(int kcode, t_fdf *fdf)
{
	if (kcode == KEY_O)
		fdf->mlx->key->reset_ratio = 0;
	else if (kcode == KEY_H)
		fdf->mlx->key->overlay = 0;
	else if (kcode == KEY_I)
		fdf->mlx->key->iso = 0;
	else if (kcode == KEY_V)
		fdf->mlx->key->color = 0;
	return (0);
}

int	key_down(int kcode, t_fdf *fdf)
{
	if (kcode == KEY_ESC)
		mlx_exit(fdf->mlx);
	else if (kcode == KEY_E || kcode == KEY_R)
		fdf->mlx->key->rot_z = (kcode == KEY_E) - (kcode == KEY_R);
	else if (kcode == KEY_W || kcode == KEY_S)
		fdf->mlx->key->rot_y = (kcode == KEY_W) - (kcode == KEY_S);
	else if (kcode == KEY_A || kcode == KEY_D)
		fdf->mlx->key->rot_x = (kcode == KEY_A) - (kcode == KEY_D);
	else if (kcode == KEY_L || kcode == KEY_K)
		fdf->mlx->key->ratio = (kcode == KEY_L) - (kcode == KEY_K);
	else if (kcode == KEY_LEFT || kcode == KEY_RIGHT)
		fdf->mlx->key->horizontal = (kcode == KEY_RIGHT) - (kcode == KEY_LEFT);
	else if (kcode == KEY_UP || kcode == KEY_DOWN)
		fdf->mlx->key->vertical = (kcode == KEY_DOWN) - (kcode == KEY_UP);
	else if (kcode == KEY_PLUS || kcode == KEY_MINUS)
		fdf->mlx->key->zoom = (kcode == KEY_PLUS) - (kcode == KEY_MINUS);
	else if (kcode == KEY_C && ++fdf->mlx->key->color == 1)
		fdf->mlx->color_mode = fdf->mlx->color_mode + 1
			- (4 * (fdf->mlx->color_mode == 3));
	else if (kcode == KEY_H && ++fdf->mlx->key->overlay == 1)
		fdf->mlx->hexon = !fdf->mlx->hexon;
	return (key_down_extended(kcode, fdf));
}

int	key_released(int kcode, t_fdf *fdf)
{
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
	else if (kcode == KEY_C)
		fdf->mlx->key->color = 0;
	else if (kcode == KEY_L || kcode == KEY_K)
		fdf->mlx->key->ratio = 0;
	else if (kcode == KEY_P)
		fdf->mlx->key->sphere = 0;
	else if (kcode == KEY_Q)
		fdf->mlx->key->reset_ratio = 0;
	else if (kcode == KEY_F)
		fdf->mlx->key->fill = 0;
	return (key_released_extended(kcode, fdf));
}
