/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:20:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 20:01:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_settings	*ft_settings_init(void)
{
	t_settings	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->fov_width = 2 * M_PI / 3;
	res->fov_dist = 0;
	res->mini_follow = 0;
	return (res);
}

static t_mlx	*ft_mlx_init(char *title)
{
	t_mlx	*mlx;

	mlx = ft_malloc(sizeof(*mlx), __func__);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_perror(__func__);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!mlx->win_ptr)
		ft_perror("mlx_new_window");
	mlx->minimap = ft_create_img(mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	mlx->keys = ft_malloc(sizeof(*mlx->keys), "keys_init");
	mlx->keys->vertical = 0;
	mlx->keys->horizontal = 0;
	mlx->keys->steering = 0;
	mlx->keys->fov_width = 0;
	return (mlx);
}

void	launch_mlx(t_map *map, char	*title)
{
	t_cub	cub;

	cub.map = map;
	cub.mlx = ft_mlx_init(title);
	cub.settings = ft_settings_init();
	fill_minimap(&cub);
	mlx_put_image_to_window(cub.mlx->mlx_ptr, cub.mlx->win_ptr,
		cub.mlx->minimap->img_ptr, 400, 350);
	mlx_hook(cub.mlx->win_ptr, ON_KEYDOWN, 0, key_down, &cub);
	mlx_hook(cub.mlx->win_ptr, ON_KEYUP, 0, key_released, &cub);
	mlx_hook(cub.mlx->win_ptr, ON_DESTROY, 0, mlx_exit, 0);
	mlx_loop_hook(cub.mlx->mlx_ptr, redraw_all, &cub);
	// mlx_mouse_hook(cub.mlx->win_ptr, mouse_button_pressed, &cub);
	mlx_loop(cub.mlx->mlx_ptr);
}
