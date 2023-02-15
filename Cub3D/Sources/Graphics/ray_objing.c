/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:55:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/15 17:11:56 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_add_obj(t_ray *ray, t_vertice *inter, t_obj *obj, double dist)
{
	obj->u = inter->z - 1;
	obj->dist = dist;
	obj->next_ray = 0;
	obj->last_ray = 0;
	if (!ray->objs)
		ray->objs = obj;
	else
	{
		ray->objs->last_ray->next_ray = obj;
		ray->objs->last_ray = obj;
	}
}

void	ray_objing(t_obj *objs, t_ray *ray, double angle) //still need to sort objs by dist
{
	t_vertice	pt4;
	t_line		obj_line;
	t_vertice	intersection;
	double		dist;

	pt4.x = ray->ray.pt1.x + cos(ray->angle);
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	ray->objs = 0;
	while (objs)
	{
		set_point(&obj_line.pt1, objs->pos.x + cos(angle + M_PI_2) * 0.5, objs->pos.y - sin(angle + M_PI_2) * 0.5, 0); //add offset towards player
		set_point(&obj_line.pt2, objs->pos.x + cos(angle - M_PI_2) * 0.5, objs->pos.y - sin(angle - M_PI_2) * 0.5, 0);
		intersection = get_inter(ray, pt4, obj_line.pt1, obj_line.pt2);
		if (intersection.z)
		{
			dist = get_dist(ray->ray.pt1, intersection);
			if (dist < ray->dist)
				ray_add_obj(ray, &intersection, objs, dist);
		}
		objs = objs->next;
	}
}
