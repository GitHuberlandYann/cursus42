/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:14:14 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/13 11:02:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	transform_xpm(t_img *dst, t_img *src, double width)
{
	t_vert			ptsrc;
	t_vert			ptdst;
	unsigned int	color;

	set_point(&ptsrc, 0, 0, src->height / width);
	set_point(&ptdst, 0, 0, src->width / width);
	while (ptdst.x < width)
	{
		ptsrc.y = 0;
		ptdst.y = 0;
		while (ptdst.y < width)
		{
			color = mlx_pxl_get(src, ptsrc.x, ptsrc.y);
			mlx_pxl_put(dst, ptdst.x, ptdst.y, color);
			++ptdst.y;
			ptsrc.y += ptdst.z;
		}
		++ptdst.x;
		ptsrc.x += ptdst.z;
	}
}

static void	filter_red(t_img *img, int proportion)
{
	int		x;
	int		y;
	double	quarter;
	char	*col;

	quarter = img->height / 4;
	x = -1;
	while (++x < img->width)
	{
		y = -1;
		while (++y < quarter * proportion)
		{
			col = img->addr + (y * img->line_length + x * img->bytes_per_pixel);
			*(unsigned *) col += 0x600000;
		}
	}
}

t_img	*ft_create_gunimg(t_mlx *mlx, char *texture, t_side side, int type)
{
	t_img	*img;
	t_img	*res;
	int		width;

	if (!texture)
		return (0);
	img = ft_create_xpmimg(mlx, texture, side);
	width = WIN_HEIGHT / (3 * type);
	res = ft_create_img(mlx, width, width);
	transform_xpm(res, img, width);
	mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	free(img);
	return (res);
}

void	display_weapon(t_mlx *mlx, t_player *player, int player_num)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->avatar[4 - player->hp]->img_ptr,
		mlx->avatar[4 - player->hp]->width / 2,
		player_num * WIN_HEIGHT_2 - mlx->avatar[4 - player->hp]->height);
	if (player->state == DEAD)
		return ;
	if (player->state != SHOOTING)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->weap_idle[player->weapon]->img_ptr,
			WIN_WIDTH_2 - mlx->weap_idle[0]->width / 2,
			player_num * WIN_HEIGHT_2 - mlx->weap_idle[0]->height);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->weap_use[player->weapon][player->obj->frame_shoot]->img_ptr,
			WIN_WIDTH_2 - mlx->weap_idle[0]->width / 2,
			player_num * WIN_HEIGHT_2 - mlx->weap_idle[0]->height);
}

void	add_death_filters(t_mlx *mlx, t_player *player, t_player *other)
{
	t_vert	pos;

	if (player->state == DEAD)
		filter_red(mlx->render3d, player->obj->frame_shoot);
	if (other->state == DEAD)
		filter_red(mlx->render3dbis, other->obj->frame_shoot);
	set_point(&pos, WIN_WIDTH_2, mlx->render3d->height / 2, 0);
	draw_circle(mlx->render3d, &pos, 3, RED);
	draw_circle(mlx->render3dbis, &pos, 3, RED);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->render3d->img_ptr, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->render3dbis->img_ptr, 0, WIN_HEIGHT_2);
}