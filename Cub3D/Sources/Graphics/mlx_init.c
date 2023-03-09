/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:51:50 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 10:57:02 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_objs_imgs(t_mlx *mlx, t_map *map)
{
	t_obj	*objs;
	t_anim	*anims;
	int		cnt;

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
			break ;
		free(anims->str);
		anims->str = 0;
		anims = anims->next;
	}
	if (map->playerbis)
		load_player_imgs(mlx);
}

void	ft_img_init(t_mlx *mlx, t_map *map)
{
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
	mlx->fc_textures[CEILLING]
		= ft_create_xpmimg(mlx, map->fc_textures[CEILLING], 1);
	mlx->ds_textures[0] = ft_create_xpmimg(mlx, map->ds_textures[0], 0);
	mlx->ds_textures[1] = ft_create_xpmimg(mlx, map->ds_textures[1], 1);
	mlx->obj_textures[BARREL]
		= ft_create_xpmimg(mlx, map->obj_textures[BARREL], 0);
	mlx->obj_textures[PILLAR]
		= ft_create_xpmimg(mlx, map->obj_textures[PILLAR], 1);
	mlx->obj_textures[POST] = ft_create_xpmimg(mlx, map->obj_textures[POST], 2);
	mlx->obj_textures[CUST] = ft_create_xpmimg(mlx, map->obj_textures[CUST], 3);
	mlx->obj_textures[WIN] = ft_create_xpmimg(mlx, map->obj_textures[WIN], 4);
	init_objs_imgs(mlx, map);
}
