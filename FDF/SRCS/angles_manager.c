/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:05:15 by marvin            #+#    #+#             */
/*   Updated: 2022/10/22 17:05:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <stdio.h>
int	ft_rotation_x(t_angles *a, float x, float y, float value)
{
	float	res;

	res = a->ca * a->cb * x;
	res += (a->sa * a->sb * a->cg - a->ca * a->sg) * y;
	res += (a->ca * a->sb * a->cg + a->sa * a->sg) * value;
	return (res); //may need a nearbyint(res) or some rounding shinanigans
}

int	ft_rotation_y(t_angles *a, float x, float y, float value)
{
	float	res;

	res = a->sa * a->cb * x;
	res += (a->sa * a->sb * a->sg + a->ca * a->cg) * y;
	res += (a->ca * a->sb * a->sg + a->sa * a->cg) * value;
	return (res);
}

float	ft_get_xcase(int column, int nbr, t_mlx *mlx)
{
	float	res;
	float	case_width;

	case_width = mlx->size_x / (nbr + 4);
	res = (2 + column) * case_width;
	return (res);
}

float	ft_get_ycase(int row, int nbr, t_mlx *mlx)
{
	float	res;
	float	case_width;

	case_width = mlx->size_y / (nbr + 4);
	res = (2 + row) * case_width;
	return (res);
}

t_angles	*angles_init(float alpha, float beta, float gamma)
{
	t_angles	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->alpha = (alpha * M_PI) / 180;
	res->beta = (beta * M_PI) / 180;
	res->gamma = (gamma * M_PI) / 180;
	res->sa = sin(res->alpha);
	res->ca = cos(res->alpha);
	res->sb = sin(res->beta);
	res->cb = cos(res->beta);
	res->sg = sin(res->gamma);
	res->cg = cos(res->gamma);
	return (res);
}
