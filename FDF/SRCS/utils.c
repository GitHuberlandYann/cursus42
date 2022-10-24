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

int	***ft_mapdup(t_mlx *mlx, t_map *map, t_angles *a)
{
	int		***res;
	int		row;
	int		col;
	float	xtmp;
	float	ytmp;
	float	vtmp;

	res = malloc(sizeof(*res) * map->maplen);
	if (!res)
		return (0);
	row = 0;
	while (row < map->maplen)
	{
		res[row] = malloc(sizeof(*res[row]) * map->rowlen);
		if (!res[row])
			return (0); //and free but fkit for now
		col = 0;
		while (col < map->rowlen)
		{
			res[row][col] = malloc(sizeof(*res[row][col]) * 2);
			if (!res[row][col])
				return (0);
			xtmp = ft_get_xcase(col, map->rowlen, mlx->size_x);
			ytmp = ft_get_ycase(row, map->maplen, mlx->size_y);
			vtmp = ft_get_vcase(map->map[row][col], map->max_value, map->maplen, mlx->size_y);
			res[row][col][0] = ft_rotation_x(a, xtmp, ytmp, vtmp);
			res[row][col][1] = ft_rotation_y(a, xtmp, ytmp, vtmp);
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

int	ft_get_color(float value, int white)
{
	int	res;

	if (white || !value)
		return (0xffffff);
	res = 0xff00;
	res += (0xff0000) * value;
	return (res);
}
