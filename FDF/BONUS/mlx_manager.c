/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:42:01 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 16:42:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_mlx_set_keys(t_mlx *mlx)
{
	t_key *keys;

	keys = malloc(sizeof(*keys));
	if (!keys)
		ft_perror(__func__);
	keys->rot_x = 0;
	keys->rot_y = 0;
	keys->rot_z = 0;
	keys->vertical = 0;
	keys->horizontal = 0;
	keys->zoom = 0;
	// keys->rot_special = 0;
	keys->color = 0;
	// keys->overlay = 0;
	mlx->key = keys;
}

static void	ft_create_img(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		ft_perror(__func__);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
	if (!img->img_ptr)
		ft_perror("mlx_new_image");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
								&img->line_length, &img->endian);
	mlx->img = img;
}

static void	ft_create_backimg(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		ft_perror(__func__);
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
						"maps_xpm/wallpaperflare.com_wallpaper.xpm",
						&img->width, &img->height);
	if (!img->img_ptr)
		ft_perror("mlx_new_image");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
								&img->line_length, &img->endian);
	mlx->back = img;
}

static void	ft_mlx_init(t_fdf *fdf, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(*mlx));
	if (!mlx)
		ft_perror(__func__);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_perror("mlx_init");
	mlx->size = 5;
	mlx->offset_x = WIN_SIZE_X / 2;
	mlx->offset_y = WIN_SIZE_Y / 2;
	mlx->color_mode = 1;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, title);
	if (!mlx->win_ptr)
		ft_perror("mlx_new_window");
	ft_create_img(mlx);
	ft_create_backimg(mlx);
	ft_mlx_set_keys(mlx);
	fdf->mlx = mlx;
}

void	mlx_related_stuff(t_map *map, t_angles *a, char *title)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(*fdf));
	if (!fdf)
		ft_perror(__func__);
	fdf->map = map;
	fdf->angles = a;
	ft_mlx_init(fdf, title);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
							fdf->mlx->img->img_ptr, 0, 0);
	mlx_hook(fdf->mlx->win_ptr, ON_KEYDOWN, 0, key_down, fdf);
	mlx_hook(fdf->mlx->win_ptr, ON_KEYUP, 0, key_released, fdf);
	mlx_hook(fdf->mlx->win_ptr, ON_DESTROY, 0, mlx_exit, fdf->mlx);
	mlx_loop_hook(fdf->mlx->mlx_ptr, mlx_draw, fdf);
	// mlx_mouse_hook(fdf->mlx->win_ptr, mouse_button_pressed, fdf);
	mlx_loop(fdf->mlx->mlx_ptr);
}
