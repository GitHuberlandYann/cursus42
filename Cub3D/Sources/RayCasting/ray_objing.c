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
	if (obj->type == WIN)
		obj->u = ft_fmod((inter->z - 1) * obj->size, 1);
	else
		obj->u = inter->z - 1;
	obj->dist = dist;
	obj->next_ray = 0;
	obj->last_ray = 0;
	if (!ray->objs)
		ray->objs = obj;
	else
		ray->objs->last_ray->next_ray = obj;
	ray->objs->last_ray = obj;
	if (dist < ray->mdist)
		ray->mdist = dist;
}

static void	swap_obj(t_obj *tmp)
{
	double		dswap;
	int			iswap;
	t_line		lswap;
	t_fdf		*fdfswap;

	dswap = tmp->u;
	tmp->u = tmp->next_ray->u;
	tmp->next_ray->u = dswap;
	dswap = tmp->dist;
	tmp->dist = tmp->next_ray->dist;
	tmp->next_ray->dist = dswap;
	iswap = tmp->size;
	tmp->size = tmp->next_ray->size;
	tmp->next_ray->size = iswap;
	lswap = tmp->oline;
	tmp->oline = tmp->next_ray->oline;
	tmp->next_ray->oline = lswap;
	fdfswap = tmp->fdf;
	tmp->fdf = tmp->next_ray->fdf;
	tmp->next_ray->fdf = fdfswap;
}

static void	sort_ray_obj(t_obj *start)
{
	t_obj		*tmp;
	t_objtype	tswap;
	t_vert		vswap;

	tmp = start;
	while (tmp->next_ray)
	{
		if (tmp->dist < tmp->next_ray->dist)
		{
			tswap = tmp->type;
			tmp->type = tmp->next_ray->type;
			tmp->next_ray->type = tswap;
			set_point(&vswap, tmp->pos.x, tmp->pos.y, 0);
			set_point(&tmp->pos, tmp->next_ray->pos.x, tmp->next_ray->pos.y, 0);
			set_point(&tmp->next_ray->pos, vswap.x, vswap.y, 0);
			swap_obj(tmp);
			return (sort_ray_obj(start));
		}
		tmp = tmp->next_ray;
	}
}

void	ray_objing(t_obj *objs, t_player *other, t_ray *ray)
{
	t_vert	pt4;
	t_vert	intersection;
	double	dist;

	pt4.x = ray->ray.pt1.x + cos(ray->angle);
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	ray->mdist = ray->dist;
	while (objs)
	{
		intersection = get_inter(ray, pt4, objs->oline.pt1, objs->oline.pt2);
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
	if (other)
		ray_other_player(other->obj, ray, pt4);
}
