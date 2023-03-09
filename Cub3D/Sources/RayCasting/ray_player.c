/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:34:04 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 16:40:57 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	insert_player_objs(t_obj *objs, t_obj *pobj, double dist)
{
	while (objs->next_ray)
	{
		if (dist > objs->next_ray->dist)
		{
			pobj->next_ray = objs->next_ray;
			objs->next_ray = pobj;
			break ;
		}
		objs = objs->next_ray;
	}
	if (!objs->next_ray)
		objs->next_ray = pobj;
}

static void	ray_add_other_player(t_ray *ray, t_vert *inter, t_obj *obj,
	double dist)
{
	obj->u = inter->z - 1;
	obj->dist = dist;
	obj->next_ray = 0;
	obj->last_ray = 0;
	if (!ray->objs)
		ray->objs = obj;
	else if (dist > ray->objs->dist)
	{
		obj->next_ray = ray->objs;
		ray->objs = obj;
	}
	else
		insert_player_objs(ray->objs, obj, dist);
	if (dist < ray->mdist)
		ray->mdist = dist;
}

void	ray_other_player(t_obj *obj, t_ray *ray, t_vert pt4)
{
	t_vert	intersection;
	double	dist;

	intersection = get_inter(ray, pt4, obj->oline.pt1, obj->oline.pt2);
	if (intersection.z)
	{
		dist = get_dist(ray->ray.pt1, intersection);
		if (dist < ray->dist)
			ray_add_other_player(ray, &intersection, obj, dist);
	}
}
