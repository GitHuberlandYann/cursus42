/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:15:53 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/18 17:29:29 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_clear_img(t_img *img, int color) //color = 0x00RRGGBB
{
	int	x;
	int	y;
	int	limit_x;
	int	limit_y;

	x = !img->type;
	limit_x = WIN_SIZE_X * img->type + (OVERLAY_SIZE_X - 1) * !img->type;
	limit_y = WIN_SIZE_Y * img->type + (OVERLAY_SIZE_Y - 1) * !img->type;
	while (x < limit_x)
	{
		y = !img->type;
		while (y < limit_y)
		{
			my_mlx_pixel_put(img, x, y, color);
			y ++;
		}
		x ++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		limit_x;
	int		limit_y;

	if (img->type)
	{
		limit_x = WIN_SIZE_X;
		limit_y = WIN_SIZE_Y;
	}
	else
	{
		limit_x = OVERLAY_SIZE_X;
		limit_y = OVERLAY_SIZE_Y;
	}
	if (y >= 0 && y < limit_y && x >= 0 && x < limit_x)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	ft_create_img(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		mlx_exit(mlx);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	img->type = 1;
	mlx->img = img;
}

void	ft_create_overlay(t_mlx *mlx)
{
	t_img	*overlay;

	overlay = malloc(sizeof(*overlay));
	if (!overlay)
		mlx_exit(mlx);
	overlay->img_ptr = mlx_new_image(mlx->mlx_ptr, OVERLAY_SIZE_X, OVERLAY_SIZE_Y);
	overlay->addr = mlx_get_data_addr(overlay->img_ptr, &overlay->bits_per_pixel, &overlay->line_length,
								&overlay->endian);
	overlay->type = 0;
	overlay->x = WIN_SIZE_X - OVERLAY_SIZE_X - 50;
	overlay->y = 50;
	mlx->overlay = overlay;
}

void	mlx_set_keys(t_mlx *mlx)
{
	t_key *keys;

	keys = malloc(sizeof(*keys));
	if (!keys)
		mlx_exit(mlx);
	keys->rot_x = 0;
	keys->rot_y = 0;
	keys->rot_z = 0;
	keys->vertical = 0;
	keys->horizontal = 0;
	keys->zoom = 0;
	keys->ratio = 0;
	keys->reset_ratio = 0;
	keys->rot_special = 0;
	keys->color = 0;
	keys->overlay = 0;
	mlx->key = keys;
}
