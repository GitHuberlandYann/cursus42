/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:55:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/21 17:31:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_add_obj(t_ray *ray, t_vert *inter, t_obj *obj, double dist)
{
	obj->u = inter->z - 1;
	obj->dist = dist;
	obj->next_ray = 0;
	obj->last_ray = 0;
	if (!ray->objs)
		ray->objs = obj;
	else
		ray->objs->last_ray->next_ray = obj;
	ray->objs->last_ray = obj;
}

static void	sort_ray_obj(t_obj *start)
{
	t_obj		*tmp;
	double		dswap;
	t_objtype	tswap;
	t_vert		vswap;

	tmp = start;
	while (tmp->next_ray)
	{
		if (tmp->dist < tmp->next_ray->dist)
		{
			// printf("%lf < %lf\n", tmp->dist, tmp->next_ray->dist);
			tswap = tmp->type;
			tmp->type = tmp->next_ray->type;
			tmp->next_ray->type = tswap;
			set_point(&vswap, tmp->pos.x, tmp->pos.y, 0);
			set_point(&tmp->pos, tmp->next_ray->pos.x, tmp->next_ray->pos.y, 0);
			set_point(&tmp->next_ray->pos, vswap.x, vswap.y, 0);
			dswap = tmp->u;
			tmp->u = tmp->next_ray->u;
			tmp->next_ray->u = dswap;
			dswap = tmp->dist;
			tmp->dist = tmp->next_ray->dist;
			tmp->next_ray->dist = dswap;
			// printf("after swap : %lf > %lf\n", tmp->dist, tmp->next_ray->dist);
			return (sort_ray_obj(start));
		}
		tmp = tmp->next_ray;
	}
}

void	ray_objing(t_obj *objs, t_ray *ray, double angle) //still need to sort objs by dist
{
	t_vert	pt4;
	t_line	obj_line;
	t_vert	intersection;
	double	dist;

	pt4.x = ray->ray.pt1.x + cos(ray->angle);
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	ray->objs = 0;
	while (objs)
	{
		set_point(&obj_line.pt1, objs->pos.x + cos(angle + M_PI_2) * 0.5,
			objs->pos.y - sin(angle + M_PI_2) * 0.5, 0); //add offset towards player
		set_point(&obj_line.pt2, objs->pos.x + cos(angle - M_PI_2) * 0.5,
			objs->pos.y - sin(angle - M_PI_2) * 0.5, 0);
		intersection = get_inter(ray, pt4, obj_line.pt1, obj_line.pt2);
		if (intersection.z)
		{
			dist = get_dist(ray->ray.pt1, intersection);
			if (dist < ray->dist)
				ray_add_obj(ray, &intersection, objs, dist);
		}
		objs = objs->next;
	}
	if (ray->objs)
		sort_ray_obj(ray->objs);
}
