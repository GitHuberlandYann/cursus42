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

float	ft_get_xcase(int column, int nbr, int size_x)
{
	float	res;
	float	case_width;

	case_width = size_x / (nbr + 8);
	res = (2 + column) * case_width;
	return (res);
}

float	ft_get_ycase(int row, int nbr, int size_y)
{
	float	res;
	float	case_width;

	case_width = size_y / (nbr);
	res = (2 + row) * case_width;
	return (res);
}

float	ft_get_vcase(int row, int nbr, int size_y)
{
	float	res;
	float	case_width;

	case_width = size_y / (nbr);
	res = -((size_y / 6) * row) / case_width;
	return (res);
}

void	angles_init(t_angles *a, float alpha, float beta, float gamma)
{
	a->alpha = (alpha * M_PI) / 180;
	a->beta = (beta * M_PI) / 180;
	a->gamma = (gamma * M_PI) / 180;
	a->sa = sin(a->alpha);
	a->ca = cos(a->alpha);
	a->sb = sin(a->beta);
	a->cb = cos(a->beta);
	a->sg = sin(a->gamma);
	a->cg = cos(a->gamma);
}
