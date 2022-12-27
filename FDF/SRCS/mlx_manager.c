/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/27 12:15:19 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_create_img(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		mlx_exit(mlx);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img_ptr)
		ft_perror("mlx_new_image");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->type = 1;
	mlx->img = img;
}

static t_col	*ft_col_init(void)
{
	t_col	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_perror(__func__);
	res->zero = 0x949494;
	res->top = 0xff00ff;
	res->bottom = 0x80;
	return (res);
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
	mlx->size = (double)WIN_WIDTH / (double)(2 * fdf->map->width);
	mlx->offset_x = WIN_WIDTH / 4;
	mlx->offset_y = WIN_HEIGHT / 2;
	mlx->color_mode = 0;
	mlx->hexon = 0;
	mlx->sphere = 0;
	mlx->fill = 0;
	mlx->col = ft_col_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!mlx->win_ptr)
		ft_perror("mlx_new_window");
	mlx_set_keys(mlx);
	fdf->mlx = mlx;
}

int	mlx_related_stuff(t_map *map, t_angles *a, char *title)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(*fdf));
	if (!fdf)
		ft_perror(__func__);
	fdf->map = map;
	fdf->angles = a;
	ft_mlx_init(fdf, title);
	ft_create_img(fdf->mlx);
	ft_create_backimg(fdf->mlx);
	ft_create_overlay(fdf->mlx);
	ft_create_hexa(fdf->mlx);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
		fdf->mlx->img->img_ptr, 0, 0);
	mlx_hook(fdf->mlx->win_ptr, ON_KEYDOWN, 0, key_down, fdf);
	mlx_hook(fdf->mlx->win_ptr, ON_KEYUP, 0, key_released, fdf);
	mlx_hook(fdf->mlx->win_ptr, ON_DESTROY, 0, mlx_exit, fdf->mlx);
	mlx_loop_hook(fdf->mlx->mlx_ptr, mlx_draw, fdf);
	mlx_mouse_hook(fdf->mlx->win_ptr, mouse_button_pressed, fdf);
	mlx_loop(fdf->mlx->mlx_ptr);
	return (0);
}
