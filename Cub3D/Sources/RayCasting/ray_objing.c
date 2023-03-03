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
	// ray->dist = dist;
	// ray->hit = NO;
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

static void	sort_ray_obj(t_obj *start)
{
	t_obj		*tmp;
	double		dswap;
	t_objtype	tswap;
	t_vert		vswap;
	t_line		lswap;
	int			iswap;
	t_fdf		*fdfswap;

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
			iswap = tmp->size;
			tmp->size = tmp->next_ray->size;
			tmp->next_ray->size = iswap;
			lswap = tmp->oline;
			tmp->oline = tmp->next_ray->oline;
			tmp->next_ray->oline = lswap;
			fdfswap = tmp->fdf;
			tmp->fdf = tmp->next_ray->fdf;
			tmp->next_ray->fdf = fdfswap;
			// printf("after swap : %lf > %lf\n", tmp->dist, tmp->next_ray->dist);
			return (sort_ray_obj(start));
		}
		tmp = tmp->next_ray;
	}
}

// static t_line	set_obj_line(t_obj *obj, t_ray *ray)
// {
// 	double	angle;
// 	t_line	res;

// 	if (obj->type == WIN)
// 		return (obj->oline);
// 	else if (obj->type == FDF)
// 	{
// 		angle = atan2((ray->ray.pt1.y - obj->fdf->pos.y), (obj->fdf->pos.x - ray->ray.pt1.x));
// 		set_point(&res.pt1, obj->fdf->pos.x - cos(angle) * 0.2 + cos(angle + M_PI_2) * 0.5,
// 			obj->fdf->pos.y + sin(angle) * 0.2 - sin(angle + M_PI_2) * 0.5, 0);
// 		set_point(&res.pt2, obj->fdf->pos.x - cos(angle) * 0.2 + cos(angle - M_PI_2) * 0.5,
// 			obj->fdf->pos.y + sin(angle) * 0.2 - sin(angle - M_PI_2) * 0.5, 0);
// 	}
// 	else
// 	{
// 		angle = atan2((ray->ray.pt1.y - obj->pos.y), (obj->pos.x - ray->ray.pt1.x));
// 		set_point(&res.pt1, obj->pos.x - cos(angle) * 0.2 + cos(angle + M_PI_2) * 0.5,
// 			obj->pos.y + sin(angle) * 0.2 - sin(angle + M_PI_2) * 0.5, 0);
// 		set_point(&res.pt2, obj->pos.x - cos(angle) * 0.2 + cos(angle - M_PI_2) * 0.5,
// 			obj->pos.y + sin(angle) * 0.2 - sin(angle - M_PI_2) * 0.5, 0);
// 	}
// 	return (res);
// }

static void	ray_add_other_player(t_ray *ray, t_vert *inter, t_obj *obj, double dist)
{
	t_obj	*objs;

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
	{
		objs = ray->objs;
		while (objs->next_ray)
		{
			if (dist > objs->next_ray->dist)
			{
				obj->next_ray = objs->next_ray;
				objs->next_ray = obj;
				break ;
			}
			objs = objs->next_ray;
		}
		if (!objs->next_ray)
			objs->next_ray = obj;
	}
	if (dist < ray->mdist)
		ray->mdist = dist;
}

static void	ray_other_player(t_player *other, t_ray *ray, t_vert pt4)
{
	t_vert	intersection;
	double	dist;

	intersection = get_inter(ray, pt4, other->obj->oline.pt1, other->obj->oline.pt2);
	if (intersection.z)
	{
		dist = get_dist(ray->ray.pt1, intersection);
		if (dist < ray->dist)
			ray_add_other_player(ray, &intersection, other->obj, dist);
	}
}

void	ray_objing(t_obj *objs, t_player *other, t_ray *ray)
{
	t_vert	pt4;
	// t_line	obj_line;
	t_vert	intersection;
	double	dist;

	pt4.x = ray->ray.pt1.x + cos(ray->angle);
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	ray->mdist = ray->dist;
	while (objs)
	{
		// obj_line = set_obj_line(objs, ray);
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
		ray_other_player(other, ray, pt4);
}
