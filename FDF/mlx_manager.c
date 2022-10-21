/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/21 15:35:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

void	do_stuff(void	*mlx_ptr, void *win_ptr, int sx, int sy)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = 0x000000FF; //0x00RRGGBB
	while (x < sx)
	{
		y = 0;
		while (y < sy)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			y ++;
		}
		x ++;
	}
}

int	mlx_related_stuff(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	char	*title;

	mlx_ptr = mlx_init();
	if (mlx_ptr)
	{
		size_x = 612;
		size_y = 306;
		title = "<insert title>";
		win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title);
		if (win_ptr)
		{
			mlx_clear_window(mlx_ptr, win_ptr);
			do_stuff(mlx_ptr, win_ptr, size_x, size_y);
			mlx_loop(mlx_ptr);
			mlx_destroy_window(mlx_ptr, win_ptr);
		}
		else
			return (printf("mlx_new_window failed.\n"));
	}
	else
		return (printf("mlx_init failed.\n"));
	return (0);
}
