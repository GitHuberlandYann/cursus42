/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:31:12 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 20:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

double	ft_rotation_x(t_angles *a, t_vertice *node)
{
	double	res;

	res = a->cb * a->cg * node->x;
	res += (a->sa * a->sb * a->cg - a->ca * a->sg) * node->y;
	res += (a->ca * a->sb * a->cg + a->sa * a->sg) * node->y;
	return (res);
}

double	ft_rotation_y(t_angles *a, t_vertice *node)
{
	double	res;

	res = a->cb * a->sg * node->x;
	res += (a->sa * a->sb * a->sg + a->ca * a->cg) * node->y;
	res += (a->ca * a->sb * a->sg - a->sa * a->cg) * node->y;
	return (res);
}
