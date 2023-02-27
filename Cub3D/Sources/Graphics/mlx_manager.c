/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:20:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/27 14:51:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_set	*ft_set_init(void)
{
	t_set	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->fov_width = WIN_WIDTH_2;
	res->fov_enable = 0;
	res->fov_dist = 5;
	res->dist_feel = 1;
	res->mini_follow = 0;
	res->mini_enable = 0;
	res->wall_width = 25;
	res->radius_divww = MAP_RADIUS / res->wall_width;
	res->recurse_level = 7;
	res->offset.x = WIN_WIDTH - MAP_DIAMETER - 20;
	res->offset.y = 20;
	res->timepoint = 0;
	res->godmode = 0;
	return (res);
}

static void	ft_img_init(t_mlx *mlx, t_map *map)
{
	t_obj	*objs;
	t_anim	*anims;
	int		cnt;

	if (map->player_count == 1)
		mlx->render3d = ft_create_img(mlx, WIN_WIDTH, WIN_HEIGHT);
	else
	{
		mlx->render3d = ft_create_img(mlx, WIN_WIDTH, WIN_HEIGHT_2);
		mlx->render3dbis = ft_create_img(mlx, WIN_WIDTH, WIN_HEIGHT_2);
	}
	mlx->textures[NO] = ft_create_xpmimg(mlx, map->textures[NO], NO);
	mlx->textures[SO] = ft_create_xpmimg(mlx, map->textures[SO], SO);
	mlx->textures[WE] = ft_create_xpmimg(mlx, map->textures[WE], WE);
	mlx->textures[EA] = ft_create_xpmimg(mlx, map->textures[EA], EA);
	mlx->fc_textures[FLOOR] = ft_create_xpmimg(mlx, map->fc_textures[FLOOR], 0);
	mlx->fc_textures[CEILLING] = ft_create_xpmimg(mlx, map->fc_textures[CEILLING], 1);
	mlx->ds_textures[0] = ft_create_xpmimg(mlx, map->ds_textures[0], 0);
	mlx->ds_textures[1] = ft_create_xpmimg(mlx, map->ds_textures[1], 1);
	mlx->obj_textures[BARREL] = ft_create_xpmimg(mlx, map->obj_textures[BARREL], 0);
	mlx->obj_textures[PILLAR] = ft_create_xpmimg(mlx, map->obj_textures[PILLAR], 1);
	mlx->obj_textures[POST] = ft_create_xpmimg(mlx, map->obj_textures[POST], 2);
	mlx->obj_textures[CUST] = ft_create_xpmimg(mlx, map->obj_textures[CUST], 3);
	mlx->obj_textures[WIN] = ft_create_xpmimg(mlx, map->obj_textures[WIN], 4);
	objs = map->objs;
	while (objs)
	{
		if (objs->type == FDF)
			objs->fdf->canva = ft_create_img(mlx, WIN_FDFX, WIN_FDFY);
		objs = objs->next;
	}
	anims = map->anims;
	cnt = 0;
	while (anims)
	{
		if (anims->str)
			anims->frame = ft_create_xpmimg(mlx, anims->str, cnt++);
		else
			break;
		free(anims->str);
		anims->str = 0;
		anims = anims->next;
	}
}

static t_mlx	*ft_mlx_init(char *title, t_map *map)
{
	t_mlx	*mlx;

	mlx = ft_malloc(sizeof(*mlx), __func__);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_perror(__func__);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!mlx->win_ptr)
		ft_perror("mlx_new_window");
	ft_img_init(mlx, map);
	mlx->keys = ft_malloc(sizeof(*mlx->keys), "keys_init");
	mlx->keys->vertical = 0;
	mlx->keys->verticalbis = 0;
	mlx->keys->horizontal = 0;
	mlx->keys->sprint = 0;
	mlx->keys->sprintbis = 0;
	mlx->keys->steering = 0;
	mlx->keys->steeringbis = 0;
	mlx->keys->fov_width = 0;
	mlx->keys->fov_enable = 0;
	mlx->keys->fov_dist = 0;
	mlx->keys->dist_feel = 0;
	mlx->keys->wall_width = 0;
	mlx->keys->mini_follow = 0;
	mlx->keys->mini_enable = 0;
	mlx->keys->mousedate = 1;
	mlx->keys->door = 0;
	mlx->keys->doorbis = 0;
	mlx->keys->godmode = 0;
	mlx->mouse_pos.z = 1;
	mlx->fps = 30;
	ft_strcpy(mlx->fpstr, "fps : ");
	return (mlx);
}

void	launch_mlx(t_map *map, char	*title)
{
	t_cub	cub;

	cub.map = map;
	cub.mlx = ft_mlx_init(title, map);
	cub.settings = ft_set_init();
	set_ray_angles(cub.settings->fov_width, map->player, map->playerbis);
	mlx_hook(cub.mlx->win_ptr, ON_DESTROY, 0, mlx_exit, 0);
	if (map->player_count == 1)
	{
		mlx_hook(cub.mlx->win_ptr, ON_KEYDOWN, 1L<<0, key_down, &cub);
		mlx_hook(cub.mlx->win_ptr, ON_KEYUP, 1L<<1, key_released, &cub);
		mlx_hook(cub.mlx->win_ptr, ON_MOUSEMOVE, 1L<<6, mouse_move, &cub);
		mlx_loop_hook(cub.mlx->mlx_ptr, redraw_all, &cub);
	}
	else
	{
		mlx_hook(cub.mlx->win_ptr, ON_KEYDOWN, 1L<<0, key_down_2p, &cub);
		mlx_hook(cub.mlx->win_ptr, ON_KEYUP, 1L<<1, key_released_2p, &cub);
		mlx_loop_hook(cub.mlx->mlx_ptr, redraw_all_2p, &cub);
	}
	mlx_loop(cub.mlx->mlx_ptr);
}
