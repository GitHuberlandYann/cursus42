/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:15:53 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/26 18:57:45 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (y >= 0 && y < WIN_SIZE_Y && x >= 0 && x < WIN_SIZE_X)
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
	mlx->img = img;
}

// void	ft_create_overlay(t_mlx *mlx)
// {
// 	t_img	*overlay;

// 	overlay = 0;

// }
