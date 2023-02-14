/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:20:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/14 16:48:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_settings	*ft_settings_init(void)
{
	t_settings	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->fov_width = WIN_WIDTH_2;
	res->fov_enable = 0;
	res->fov_dist = 5;
	res->dist_feel = 1;
	res->mini_follow = 0;
	res->mini_enable = 0;
	res->wall_width = 25;
	res->recurse_level = 7;
	res->offset.x = WIN_WIDTH - MAP_DIAMETER - 20;
	res->offset.y = 20;
	res->timepoint = 0;
	return (res);
}

static void	ft_img_init(t_mlx *mlx, char *(textures[4]), char *(fc_textures[2]), char *(ds_textures[2]))
{
	mlx->render3d = ft_create_img(mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->textures[NO] = ft_create_xpmimg(mlx, textures[NO], NO);
	mlx->textures[SO] = ft_create_xpmimg(mlx, textures[SO], SO);
	mlx->textures[WE] = ft_create_xpmimg(mlx, textures[WE], WE);
	mlx->textures[EA] = ft_create_xpmimg(mlx, textures[EA], EA);
	mlx->fc_textures[FLOOR] = ft_create_xpmimg(mlx, fc_textures[FLOOR], 0);
	mlx->fc_textures[CEILLING] = ft_create_xpmimg(mlx, fc_textures[CEILLING], 1);
	mlx->ds_textures[0] = ft_create_xpmimg(mlx, ds_textures[0], 0);
	mlx->ds_textures[1] = ft_create_xpmimg(mlx, ds_textures[1], 1);
}

static t_mlx	*ft_mlx_init(char *title, char *(textures[4]), char *(fc_textures[2]), char *(ds_textures[2]))
{
	t_mlx	*mlx;

	mlx = ft_malloc(sizeof(*mlx), __func__);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_perror(__func__);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!mlx->win_ptr)
		ft_perror("mlx_new_window");
	ft_img_init(mlx, textures, fc_textures, ds_textures);
	mlx->keys = ft_malloc(sizeof(*mlx->keys), "keys_init");
	mlx->keys->vertical = 0;
	mlx->keys->horizontal = 0;
	mlx->keys->sprint = 0;
	mlx->keys->steering = 0;
	mlx->keys->fov_width = 0;
	mlx->keys->fov_enable = 0;
	mlx->keys->fov_dist = 0;
	mlx->keys->dist_feel = 0;
	mlx->keys->wall_width = 0;
	mlx->keys->mini_follow = 0;
	mlx->keys->mini_enable = 0;
	mlx->keys->mousedate = 1;
	mlx->keys->door = 0;
	mlx->mouse_pos.z = 1;
	ft_strcpy(mlx->fpstr, "fps : ");
	return (mlx);
}

void	launch_mlx(t_map *map, char	*title)
{
	t_cub	cub;

	cub.map = map;
	cub.mlx = ft_mlx_init(title, map->textures, map->fc_textures, map->ds_textures);
	cub.settings = ft_settings_init();
	set_ray_angles(&cub);
	mlx_hook(cub.mlx->win_ptr, ON_KEYDOWN, 1L<<0, key_down, &cub);
	mlx_hook(cub.mlx->win_ptr, ON_KEYUP, 1L<<1, key_released, &cub);
	mlx_hook(cub.mlx->win_ptr, ON_DESTROY, 0, mlx_exit, 0);
	mlx_hook(cub.mlx->win_ptr, ON_MOUSEMOVE, 1L<<6, mouse_move, &cub);
	mlx_loop_hook(cub.mlx->mlx_ptr, redraw_all, &cub);
	// mlx_mouse_hook(cub.mlx->win_ptr, mouse_button_pressed, &cub);
	mlx_loop(cub.mlx->mlx_ptr);
}
