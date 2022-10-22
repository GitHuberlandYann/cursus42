/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 16:57:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fdf.h"

void	do_stuff(t_mlx *mlx)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = 0x000000FF; //0x00RRGGBB
	while (x < mlx->size_x)
	{
		y = 0;
		while (y < mlx->size_y)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
			y ++;
		}
		x ++;
	}
}

int	mlx_related_stuff(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(*mlx));
	if (!mlx)
		return (-1);
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr)
	{
		mlx->size_x = 612;
		mlx->size_y = 306;
		mlx->title = "<insert title>";
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->size_x, mlx->size_y, mlx->title);
		if (mlx->win_ptr)
		{
			mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
			do_stuff(mlx);
			mlx_loop(mlx->mlx_ptr);
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		}
		else
			ft_putstr("mlx_new_window failed.\n");
	}
	else
		ft_putstr("mlx_init failed.\n");
	return (0);
}
