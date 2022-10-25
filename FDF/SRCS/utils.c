/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:19:29 by marvin            #+#    #+#             */
/*   Updated: 2022/10/22 15:19:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_create_img(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		mlx_exit(mlx);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	mlx->img = img;
}

int	***ft_mapdup(t_fdf *fdf)
{
	int		***res;
	int		row;
	int		col;
	float	xtmp;
	float	ytmp;
	float	vtmp;

	res = malloc(sizeof(*res) * fdf->map->maplen);
	if (!res)
		return (0);
	row = 0;
	while (row < fdf->map->maplen)
	{
		res[row] = malloc(sizeof(*res[row]) * fdf->map->rowlen);
		if (!res[row])
			return (0); //and free but fkit for now
		col = 0;
		while (col < fdf->map->rowlen)
		{
			res[row][col] = malloc(sizeof(*res[row][col]) * 2);
			if (!res[row][col])
				return (0);
			xtmp = ft_get_xcase(col, fdf->map->rowlen, fdf->mlx->size_x, fdf->mlx->offset_x);
			ytmp = ft_get_ycase(row, fdf->map->maplen, fdf->mlx->size_y, fdf->mlx->offset_y);
			vtmp = ft_get_vcase(fdf->map->map[row][col], fdf->map->max_value, fdf->map->maplen, fdf->mlx->size_y, fdf->map->ratio);
			res[row][col][0] = ft_rotation_x(fdf->angles, xtmp, ytmp, vtmp);
			res[row][col][1] = ft_rotation_y(fdf->angles, xtmp, ytmp, vtmp);
			++col;
		}
		++row;
	}
	return (res);
}

void	ft_display_lst_content(t_list *lst)
{
	while (lst)
	{
		ft_printf("lstc : %s", lst->content);
		lst = lst->next;
	}
}

void	ft_display_map_content(t_map *res)
{
	int	row;
	int	column;

	//ft_printf("map size : %d, row size : %d\n", res->maplen, res->rowlen);
	row = 0;
	while (row < res->maplen)
	{
		column = 0;
		while (column < res->rowlen)
		{
			ft_putchars(' ', 5 - ft_nbrlen(res->map[row][column]));
			ft_putnbr(res->map[row][column]);
			++column;
		}
		ft_putchar('\n');
		++row;
	}
}
//#include <stdio.h>
int	ft_get_color(float value, int white)
{
	int	res;

	if (white || !value)
		return (0xffffff);
	res = 0xffffff; //starting color
	if (value > 0)
		res += (0xff00ff - 0xffffff) * value; //endcolor
	else
		res += (0x80 - 0xffffff) * (-value);//printf("neg : %f\n", value);
	return (res);
}
