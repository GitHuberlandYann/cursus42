/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:20:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/08 18:27:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_settings	*ft_settings_init(void)
{
	t_settings	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->fov_width = M_PI / 3;
	res->fov_enable = 0;
	res->fov_dist = 5;
	res->dist_feel = 0;
	res->mini_follow = 0;
	res->mini_enable = 0;
	res->recurse_level = 7;
	return (res);
}

static void	ft_img_init(t_mlx *mlx, char *(textures[4]))
{
	mlx->minimap = ft_create_img(mlx, MINIMAP_WIDTH, MINIMAP_WIDTH);
	mlx->render3d = ft_create_img(mlx, WIN_WIDTH, WIN_HEIGHT);
	ft_create_xpmimg(mlx, textures, NO);
	ft_create_xpmimg(mlx, textures, SO);
	ft_create_xpmimg(mlx, textures, WE);
	ft_create_xpmimg(mlx, textures, EA);
}

static t_mlx	*ft_mlx_init(char *title, char *(textures[4]))
{
	t_mlx	*mlx;

	mlx = ft_malloc(sizeof(*mlx), __func__);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_perror(__func__);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!mlx->win_ptr)
		ft_perror("mlx_new_window");
	ft_img_init(mlx, textures);
	mlx->keys = ft_malloc(sizeof(*mlx->keys), "keys_init");
	mlx->keys->vertical = 0;
	mlx->keys->horizontal = 0;
	mlx->keys->sprint = 0;
	mlx->keys->steering = 0;
	mlx->keys->fov_width = 0;
	mlx->keys->fov_enable = 0;
	mlx->keys->fov_dist = 0;
	mlx->keys->dist_feel = 0;
	mlx->keys->mini_follow = 0;
	mlx->keys->mini_enable = 0;
	mlx->keys->mousedate = 0;
	mlx->keys->door = 0;
	mlx->mouse_pos.z = 1;
	return (mlx);
}

void	launch_mlx(t_map *map, char	*title)
{
	t_cub	cub;

	cub.map = map;
	cub.mlx = ft_mlx_init(title, map->textures);
	cub.settings = ft_settings_init();
	clear_render(cub.mlx->render3d, cub.map->fc_colors);
	render_map(cub.mlx->render3d, cub.map->player, cub.map, &cub);
	mlx_put_image_to_window(cub.mlx->mlx_ptr, cub.mlx->win_ptr,
		cub.mlx->render3d->img_ptr, 0, 0);
	if (cub.settings->mini_enable)
	{
		fill_minimap(&cub);
		mlx_put_image_to_window(cub.mlx->mlx_ptr, cub.mlx->win_ptr,
			cub.mlx->minimap->img_ptr, (WIN_WIDTH - MINIMAP_WIDTH) / 4, (WIN_HEIGHT - MINIMAP_WIDTH) / 4);
	}
	mlx_hook(cub.mlx->win_ptr, ON_KEYDOWN, 1L<<0, key_down, &cub);
	mlx_hook(cub.mlx->win_ptr, ON_KEYUP, 1L<<1, key_released, &cub);
	mlx_hook(cub.mlx->win_ptr, ON_DESTROY, 0, mlx_exit, 0);
	mlx_hook(cub.mlx->win_ptr, ON_MOUSEMOVE, 1L<<6, mouse_move, &cub);
	mlx_loop_hook(cub.mlx->mlx_ptr, redraw_all, &cub);
	// mlx_mouse_hook(cub.mlx->win_ptr, mouse_button_pressed, &cub);
	mlx_loop(cub.mlx->mlx_ptr);
}
