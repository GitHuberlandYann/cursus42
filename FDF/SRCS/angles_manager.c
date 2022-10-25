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

float	ft_get_xcase(int column, int nbr, int size_x, int offset_x)
{
	float	res;
	float	case_width;

	case_width = ((6 * size_x) / 8) / (nbr + 8);
	res = offset_x + column * case_width;
	return (res);
}

float	ft_get_ycase(int row, int nbr, int size_y, int offset_y)
{
	float	res;
	float	case_width;

	case_width = size_y / (nbr);
	res = offset_y + row * case_width;
	return (res);
}

float	ft_get_vcase(int value, int max_value, int nbr, int size_y, float ratio)
{
	float	res;
	float	case_width;

	case_width = size_y / (nbr);
	if (value != 0)
		res = -case_width * ((float)value / (float)max_value) * ratio;
	else
		res = 0;
	return (res);
}
