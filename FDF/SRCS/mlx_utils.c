/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:15:53 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/16 15:57:50 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_backimg(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		ft_perror(__func__);
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"maps_xpm/wallpaperflare.com_wallpaper-2.xpm", &img->width,
			&img->height);
	if (!img->img_ptr)
		ft_perror("mlx_new_image");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx->back = img;
}

void	ft_create_overlay(t_mlx *mlx)
{
	t_img	*ovrlay;

	ovrlay = malloc(sizeof(*ovrlay));
	if (!ovrlay)
		mlx_exit(mlx);
	ovrlay->img_ptr = mlx_new_image(mlx->mlx_ptr, OL_WIDTH, OL_HEIGHT);
	ovrlay->addr = mlx_get_data_addr(ovrlay->img_ptr, &ovrlay->bits_per_pixel,
			&ovrlay->line_length, &ovrlay->endian);
	ovrlay->type = 0;
	ovrlay->x = WIN_WIDTH - OL_WIDTH - 50;
	ovrlay->y = 50;
	mlx->overlay = ovrlay;
}

void	mlx_set_keys(t_mlx *mlx)
{
	t_key	*keys;

	keys = malloc(sizeof(*keys));
	if (!keys)
		mlx_exit(mlx);
	keys->rot_x = 0;
	keys->rot_y = 0;
	keys->rot_z = 0;
	keys->vertical = 0;
	keys->horizontal = 0;
	keys->zoom = 0;
	keys->color = 0;
	keys->ratio = 0;
	keys->reset_ratio = 0;
	keys->iso = 0;
	keys->overlay = 0;
	keys->sphere = 0;
	keys->fill = 0;
	mlx->key = keys;
}
