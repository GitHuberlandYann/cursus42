/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:54:38 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/24 18:06:50 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_map(t_fdf *fdf, int ***map)
{
	int	row;
	int	col;

	row = 0;
	while (row < fdf->map->maplen)
	{
		col = 0;
		while (col < fdf->map->rowlen)
			free(map[row][col++]);
		free(map[row++]);
	}
	free(map);
}

static int	***ft_map2dup(t_fdf *fdf)
{
	int		***res;
	int		row;
	int		col;
	float	xtmp;
	float	ytmp;
	float	vtmp;

	res = malloc(sizeof(*res) * fdf->map2->maplen);
	if (!res)
		return (0);
	row = 0;
	while (row < fdf->map2->maplen)
	{
		res[row] = malloc(sizeof(*res[row]) * fdf->map2->rowlen);
		if (!res[row])
			return (0); //and free but fkit for now
		col = 0;
		while (col < fdf->map2->rowlen)
		{
			res[row][col] = malloc(sizeof(*res[row][col]) * 2);
			if (!res[row][col])
				return (0);
			xtmp = ft_get_xcase(col, fdf->map2->rowlen, fdf->mlx->size_x);
			ytmp = ft_get_ycase(row, fdf->map2->maplen, fdf->mlx->size_y);
			vtmp = ft_get_vcase(fdf->map2, fdf->map2->map[row][col], fdf->mlx->size_y);
			res[row][col][0] = ft_rotation_x(fdf->angles, xtmp, ytmp, vtmp) + fdf->mlx->offset_x;
			res[row][col][1] = ft_rotation_y(fdf->angles, xtmp, ytmp, vtmp) + fdf->mlx->offset_y;
			// res[row][col][0] = ft_rotation_x(fdf->angles, (float)col * (float)fdf->mlx->size_x / (float)fdf->map2->rowlen, 
			// 								(float)row * (float)fdf->mlx->size_y / (float)fdf->map2->maplen, fdf->map2->map[row][col] * fdf->map2->ratio) + fdf->mlx->offset_x;
			// res[row][col][1] = ft_rotation_y(fdf->angles, (float)col * (float)fdf->mlx->size_x / (float)fdf->map2->rowlen, 
			// 								(float)row * (float)fdf->mlx->size_y / (float)fdf->map2->maplen, fdf->map2->map[row][col] * fdf->map2->ratio) + fdf->mlx->offset_y;
			++col;
		}
		++row;
	}
	return (res);
}

void	mlx_map2_img(t_fdf *fdf)
{
	int	***copy;
	int	row;
	int	col;

	if (!fdf->map2)
		return ;
	copy = ft_map2dup(fdf);
	if (!copy)
		mlx_exit(fdf->mlx);
	row = 0;
	while (row < fdf->map2->maplen)
	{
		col = 0;
		while (col < fdf->map2->rowlen)
		{
			mlx_link_node(fdf, copy, row, col);
			++col;
		}
		++row;
	}
	ft_free_map(fdf, copy);
}
