/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/23 16:05:18 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"

static void	mlx_fill_background(t_mlx *mlx, int color) //color = 0x00RRGGBB
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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

static void	mlx_draw_line(t_mlx *mlx, int ax, int ay, int bx, int by)
{
	float	pixelx;
	float	pixely;
	float	dx;
	float	dy;
	float	len;

	dx = bx - ax;
	dy = by - ay;
	len = sqrt(dx * dx + dy * dy);
	dx /= len;
	dy /= len;
	pixelx = ax;
	pixely = ay;
	while (len > 0)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, pixelx, pixely, 0xffffff);
		pixelx += dx;
		pixely += dy;
		--len;
	}
}

static void	mlx_link_node(t_mlx *mlx, t_map *map, int ***copy, int r, int c)
{
	if (c < map->rowlen - 1)
		mlx_draw_line(mlx, copy[r][c][0], copy[r][c][1], copy[r][c + 1][0], copy[r][c + 1][1]);
	if (r < map->maplen - 1)
		mlx_draw_line(mlx, copy[r][c][0], copy[r][c][1], copy[r + 1][c][0], copy[r + 1][c][1]);
}

static void	mlx_display_map(t_mlx *mlx, t_map *map, t_angles *angles)
{
	int	***copy;
	int	row;
	int	col;

	copy = ft_mapdup(mlx, map, angles);
	if (!copy)
		mlx_exit(mlx);
	row = 0;
	while (row < map->maplen)
	{
		col = 0;
		while (col < map->rowlen)
		{
			mlx_link_node(mlx, map, copy, row, col);
			++col;
		}
		++row;
	}
}

int	mlx_related_stuff(t_map *map, t_angles *angles)
{
	t_mlx	*mlx;

	(void)map;
	(void)angles;
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
			mlx_fill_background(mlx, 0x0);
			mlx_display_map(mlx, map, angles);
			mlx_mouse_hook(mlx->win_ptr, mouse_button_pressed, mlx);
			mlx_key_hook(mlx->win_ptr, key_pressed, mlx);
			mlx_hook(mlx->win_ptr, ON_DESTROY, 0, &mlx_exit, mlx); //x_mask not supported
			mlx_loop(mlx->mlx_ptr);
		}
		else
			ft_putstr("mlx_new_window failed.\n");
	}
	else
		ft_putstr("mlx_init failed.\n");
	return (0);
}
