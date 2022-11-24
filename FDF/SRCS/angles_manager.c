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

	res = a->cb * a->cg * x;
	res += (a->sa * a->sb * a->cg - a->ca * a->sg) * y;
	res += (a->ca * a->sb * a->cg + a->sa * a->sg) * value;
	return (res); //may need a nearbyint(res) or some rounding shinanigans
}

int	ft_rotation_y(t_angles *a, float x, float y, float value)
{
	float	res;

	res = a->cb * a->sg * x;
	res += (a->sa * a->sb * a->sg + a->ca * a->cg) * y;
	res += (a->ca * a->sb * a->sg - a->sa * a->cg) * value;
	return (res);
}

float	ft_get_xcase(float column, float len, float size_x)
{
	float	res;
	float	case_width;

	case_width = size_x / len;
	res = column * case_width;
	return (res);
}

float	ft_get_ycase(float row, float len, float size_y)
{
	float	res;
	float	case_width;

	case_width = size_y / len;
	res = row * case_width;
	return (res);
}

float	ft_get_vcase(t_map *map, float value, float size_y)
{
	float	res;
	float	case_width;

	if (!map->max_value)
		return (0);
	case_width = size_y / (float)map->maplen;
	res = -case_width * (value / (float)map->max_value) * map->ratio;
	return (res);
}
