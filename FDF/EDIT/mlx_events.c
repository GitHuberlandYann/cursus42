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

#include "fdf_edit.h"

static void	ft_reset_map(t_vertice *vert)
{
	t_vertice	*tmp;

	tmp = vert;
	while (tmp)
	{
		tmp->z = 0;
		tmp = tmp->next;
	}
}

int	mlx_exit(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int	mlx_update_mouse(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	mlx->mx = x;
	mlx->my = y;
	return (0);
}

int	key_down(int kcode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (kcode == KEY_ESC)
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
	else if (kcode == KEY_C && ++fdf->mlx->key->color == 1)
		fdf->mlx->color_mode = !fdf->mlx->color_mode;
	else if (kcode == KEY_L || kcode == KEY_K)
		fdf->mlx->key->edit = (kcode == KEY_K) - (kcode == KEY_L);
	else if (kcode == KEY_P && ++fdf->mlx->key->sphere == 1)
		fdf->mlx->sphere = !fdf->mlx->sphere;
	else if (kcode == KEY_Q && ++fdf->mlx->key->reset == 1)
		ft_reset_map(fdf->map->vert);
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
	else if (kcode == KEY_C)
		fdf->mlx->key->color = 0;
	else if (kcode == KEY_L || kcode == KEY_K)
		fdf->mlx->key->edit = 0;
	else if (kcode == KEY_P)
		fdf->mlx->key->sphere = 0;
	else if (kcode == KEY_Q)
		fdf->mlx->key->reset = 0;
	return (0);
}
