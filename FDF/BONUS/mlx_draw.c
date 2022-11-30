/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:26:07 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 17:26:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static	void	save_keys(t_key *key, t_key *save)
{
	save->rot_x = key->rot_x;
	save->rot_y = key->rot_y;
	save->rot_z = key->rot_z;
	save->vertical = key->vertical;
	save->horizontal = key->horizontal;
	save->zoom = key->zoom;
	// save->rot_special = key->rot_special;
	// save->color = key->color;
	// save->overlay = key->overlay;
}

static int	check_pressed(t_key *key, t_key *save)
{
	if (save->horizontal == 404)
		return (0);
	return (key->rot_x == save->rot_x && key->rot_y == save->rot_y
			&& key->rot_z == save->rot_z && key->horizontal == save->horizontal
			&& key->vertical == save->vertical && key->zoom == save->zoom);
}

static void	mlx_clear_img(t_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_SIZE_X)
	{
		y = 0;
		while (y < WIN_SIZE_Y)
		{
			ft_mlx_pixel_put(img, x, y, color);
			y ++;
		}
		x ++;
	}
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= WIN_SIZE_Y || x < 0 || x >= WIN_SIZE_X)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mlx_draw(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (check_pressed(fdf->mlx->key, fdf->mlx->keycpy))
		return (0);
	mlx_clear_img(fdf->mlx->img, 0x0);
	mlx_map_img(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr,
							fdf->mlx->img->img_ptr, 0, 0);
	save_keys(fdf->mlx->key, fdf->mlx->keycpy);
	return (0);
}
