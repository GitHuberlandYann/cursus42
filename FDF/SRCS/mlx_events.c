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

#include "fdf.h"

static int	key_down_extendeded(int kcode, t_fdf *fdf)
{
	if (kcode == KEY_I && ++fdf->mlx->key->iso == 1)
	{
		set_angles(fdf->angles, 0, 0, 0);
		fdf->mlx->size = (double)WIN_WIDTH / (double)(2 * fdf->map->width);
		fdf->mlx->offset_x = WIN_WIDTH / 4;
		fdf->mlx->offset_y = WIN_HEIGHT / 4;
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
	else if (kcode == KEY_8 && ++fdf->mlx->key->clevels[0] == 1)
		fdf->mlx->col->level0 -= 0.01;
	else if (kcode == KEY_9 && ++fdf->mlx->key->clevels[1] == 1)
		fdf->mlx->col->level0 += 0.01;
	else if (kcode == KEY_5 && ++fdf->mlx->key->clevels[2] == 1)
		fdf->mlx->col->level1 -= 0.01;
	else if (kcode == KEY_6 && ++fdf->mlx->key->clevels[3] == 1)
		fdf->mlx->col->level1 += 0.01;
	else if (kcode == KEY_2 && ++fdf->mlx->key->clevels[4] == 1)
		fdf->mlx->col->level2 -= 0.01;
	else if (kcode == KEY_3 && ++fdf->mlx->key->clevels[5] == 1)
		fdf->mlx->col->level2 += 0.01;
	else if (kcode == KEY_P && ++ fdf->mlx->key->sphere == 1)
		fdf->mlx->sphere = !fdf->mlx->sphere;
	return (key_down_extendeded(kcode, fdf));
}

static int	key_released_extended(int kcode, t_fdf *fdf)
{
	if (kcode == KEY_O)
		fdf->mlx->key->reset_ratio = 0;
	else if (kcode == KEY_H)
		fdf->mlx->key->overlay = 0;
	else if (kcode == KEY_8)
		fdf->mlx->key->clevels[0] = 0;
	else if (kcode == KEY_9)
		fdf->mlx->key->clevels[1] = 0;
	else if (kcode == KEY_5)
		fdf->mlx->key->clevels[2] = 0;
	else if (kcode == KEY_6)
		fdf->mlx->key->clevels[3] = 0;
	else if (kcode == KEY_2)
		fdf->mlx->key->clevels[4] = 0;
	else if (kcode == KEY_3)
		fdf->mlx->key->clevels[5] = 0;
	else if (kcode == KEY_I)
		fdf->mlx->key->iso = 0;
	return (0);
}

int	mouse_button_pressed(int button, int x, int y, t_fdf *fdf)
{
	t_mlx			*mlx;
	unsigned int	col;

	mlx = fdf->mlx;
	if (mlx->key->overlay)
	{
		if (x >= mlx->hex->x && x < mlx->hex->x + mlx->hex->width
			&& y >= mlx->hex->y && y < mlx->hex->y + mlx->hex->height)
		{
			col = ft_mlx_pixel_get(mlx->hex, x - mlx->hex->x, y - mlx->hex->y)
				% 0xff000000;
			if (fdf->mlx->color_mode == 1)
			{
				if (button == 1)
					mlx->col->top = col;
				else
					mlx->col->bottom = col;
			}
			else if (fdf->mlx->color_mode == 0)
				mlx->col->zero = col;
			else if (fdf->mlx->color_mode == 2)
				mlx->col->zero = col;
		}
	}
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
		fdf->mlx->color_mode = !fdf->mlx->color_mode
			+ (2 * (fdf->mlx->color_mode == 1));
	else if (kcode == KEY_H)
		fdf->mlx->key->overlay = 1;
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
