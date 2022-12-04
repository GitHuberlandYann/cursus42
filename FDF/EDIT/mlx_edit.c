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

static void ft_edit_pixel_put(t_img *edit, t_map *map, int x, int y, double z)
{
	unsigned	col;
	char		*dst;

	if (y < 0 || y >= edit->height || x < 0 || x >= edit->width)
		return ;
	if (z > 0)
		col = 0x60ff60 - ((double) z / (double) map->max) * 0xff00;
	else if (z < 0)
		col = 0xffff - ((double) -z / (double) map->max) * 0xff00;
	else
		col = 0xffffff;
	dst = edit->addr + (y * edit->line_length + x * (edit->bits_per_pixel / 8));
	*(unsigned int*)dst = col;
}

static void ft_draw_square(t_img *edit, t_map *map, int x, int y, double z)
{
	int			startx;
	int			starty;
	double		sq_width;
	double		sq_height;

	sq_width = (double) edit->width / (double) map->width; //put this in struct, no need to math it out
	sq_height = (double) edit->height / (double) map->height;
	startx = sq_width * x;
	starty = sq_height * y;
	while (startx < sq_width * (x + 1))
	{
		starty = sq_height * y;
		while (starty < sq_height * (y + 1))
		{
			ft_edit_pixel_put(edit, map, startx, starty, z);
			++starty;
		}
		++startx;
	}
}

static t_vertice	ft_get_square(t_img *edit, t_map *map, t_vertice diff)
{
	t_vertice	res;
	double		sq_width;
	double		sq_height;

	sq_width = (double) edit->width / (double) map->width; //put in struct instead
	sq_height = (double) edit->height / (double) map->height;
	res.x = (int) (diff.x / sq_width);
	res.y = (int) (diff.y / sq_height);
	return (res);
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
			ft_draw_square(edit, fdf->map, x, y, vert->z);
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
	sq = ft_get_square(fdf->mlx->edit, fdf->map, diff);
	node = ft_get_node(fdf->map->vert, sq.y * fdf->map->width + sq.x + 1);
	if (fabs(node->z + (double)mode / 10) < fdf->map->max)
		node->z += (double)mode / 10;
	// printf("sq <%d, %d> with mouse at <%d, %d>\n", (int)sq.x, (int)sq.y, fdf->mlx->mx, fdf->mlx->my);
}
