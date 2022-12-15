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

double	ft_rotation_x(t_angles *a, t_vertice *node, t_map *map)
{
	double	res;

	res = a->cb * a->cg * node->x;
	res += (a->sa * a->sb * a->cg - a->ca * a->sg) * node->y;
	res += (a->ca * a->sb * a->cg + a->sa * a->sg) * node->z / map->max
		* map->ratio;
	return (res);
}

double	ft_rotation_y(t_angles *a, t_vertice *node, t_map *map)
{
	double	res;

	res = a->cb * a->sg * node->x;
	res += (a->sa * a->sb * a->sg + a->ca * a->cg) * node->y;
	res += (a->ca * a->sb * a->sg - a->sa * a->cg) * node->z / map->max
		* map->ratio;
	return (res);
}
