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
			xtmp = ft_get_xcase(col, fdf->map->rowlen, fdf->mlx->size_x);
			ytmp = ft_get_ycase(row, fdf->map->maplen, fdf->mlx->size_y);
			vtmp = ft_get_vcase(fdf->map, fdf->map->map[row][col], fdf->mlx->size_y);
			res[row][col][0] = ft_rotation_x(fdf->angles, xtmp, ytmp, vtmp) + fdf->mlx->offset_x;
			res[row][col][1] = ft_rotation_y(fdf->angles, xtmp, ytmp, vtmp) + fdf->mlx->offset_y;
			// res[row][col][0] = ft_rotation_x(fdf->angles, (float)col * (float)fdf->mlx->size_x / (float)fdf->map->rowlen, 
			// 								(float)row * (float)fdf->mlx->size_y / (float)fdf->map->maplen, fdf->map->map[row][col] * fdf->map->ratio) + fdf->mlx->offset_x;
			// res[row][col][1] = ft_rotation_y(fdf->angles, (float)col * (float)fdf->mlx->size_x / (float)fdf->map->rowlen, 
			// 								(float)row * (float)fdf->mlx->size_y / (float)fdf->map->maplen, fdf->map->map[row][col] * fdf->map->ratio) + fdf->mlx->offset_y;
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
int	ft_get_color(float value, int colors, float ratio)
{
	int	res;

	if (!colors || !value || !ratio)
		return (0xffffff);
	res = 0xffffff; //starting color
	if ((value > 0 && ratio > 0) || (value < 0 && ratio < 0))
		res += (0xff00ff - 0xffffff) * value; //endcolor
	else
		res += (0x80 - 0xffffff) * (fabsf(value));
	return (res);
}
