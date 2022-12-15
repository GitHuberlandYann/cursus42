/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:42:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/15 09:42:01 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_angles(t_angles *a, double alpha, double beta, double gamma)
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

double	ft_rotation_x(t_angles *a, t_vertice *node, t_map *map, int sph)
{
	double	res;
	double	z;

	res = a->cb * a->cg * node->x;
	res += (a->sa * a->sb * a->cg - a->ca * a->sg) * node->y;
	z = node->z;
	if (!sph)
		z = z / map->max * map->ratio;
	res += (a->ca * a->sb * a->cg + a->sa * a->sg) * z;
	return (res);
}

double	ft_rotation_y(t_angles *a, t_vertice *node, t_map *map, int sph)
{
	double	res;
	double	z;

	res = a->cb * a->sg * node->x;
	res += (a->sa * a->sb * a->sg + a->ca * a->cg) * node->y;
	z = node->z;
	if (!sph)
		z = z / map->max * map->ratio;
	res += (a->ca * a->sb * a->sg - a->sa * a->cg) * z;
	return (res);
}
