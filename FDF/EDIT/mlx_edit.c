/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:31:17 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 14:31:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

static void	ft_edit_pixel_put(t_img *edit, int x, int y, double z)
{
	unsigned int	col;
	char			*dst;

	if (y < 0 || y >= edit->height || x < 0 || x >= edit->width)
		return ;
	col = get_color(z, edit->max);
	dst = edit->addr + (y * edit->line_length + x * (edit->bits_per_pixel / 8));
	*(unsigned int *) dst = col;
}

static void	ft_draw_square(t_img *edit, int x, int y, double z)
{
	int			startx;
	int			starty;

	startx = edit->sq_width * x;
	starty = edit->sq_height * y;
	while (startx < edit->sq_width * (x + 1))
	{
		starty = edit->sq_height * y;
		while (starty < edit->sq_height * (y + 1))
		{
			ft_edit_pixel_put(edit, startx, starty, z);
			++starty;
		}
		++startx;
	}
}

void	ft_create_edit(t_mlx *mlx, t_map *map)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		ft_perror(__func__);
	img->width = EDIT_WIDTH;
	img->height = img->width * ((float)map->height / (float)map->width);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, img->width, img->height);
	if (!img->img_ptr)
		ft_perror("mlx_new_image");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->sq_width = (double) img->width / (double) map->width;
	img->sq_height = (double) img->height / (double) map->height;
	img->max = map->max;
	mlx->edit = img;
}

void	mlx_map_edit(t_fdf *fdf)
{
	int			x;
	int			y;
	t_vertice	*vert;
	t_img		*edit;

	edit = fdf->mlx->edit;
	x = 0;
	while (x < fdf->map->width)
	{
		y = 0;
		while (y < fdf->map->height)
		{
			vert = ft_get_node(fdf->map->vert, y * fdf->map->width + x + 1);
			ft_draw_square(edit, x, y, vert->z);
			++y;
		}
		++x;
	}
}

void	ft_edit_edit(int mode, t_fdf *fdf)
{
	t_vertice	diff;
	t_vertice	sq;
	t_vertice	*node;

	if (!mode)
		return ;
	diff.x = fdf->mlx->mx - (WIN_SIZE_X - EDIT_WIDTH - 20);
	diff.y = fdf->mlx->my - 20;
	if (diff.x < 0 || diff.x >= EDIT_WIDTH || diff.y < 0
		|| diff.y >= fdf->mlx->edit->height)
		return ;
	sq.x = (int)(diff.x / fdf->mlx->edit->sq_width);
	sq.y = (int)(diff.y / fdf->mlx->edit->sq_height);
	node = ft_get_node(fdf->map->vert, sq.y * fdf->map->width + sq.x + 1);
	if (fabs(node->z + (double)mode) < fdf->map->max)
		node->z += (double)mode;
}
