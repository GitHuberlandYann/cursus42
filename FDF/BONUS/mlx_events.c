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
	if (mlx->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_free_map(fdf->map);
	exit(EXIT_SUCCESS);
}

int	key_down(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	return (0);
}

int	key_released(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	return (0);
}
