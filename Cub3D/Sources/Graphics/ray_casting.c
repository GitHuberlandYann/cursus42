/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:31:01 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/17 14:31:02 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vert	get_inter(t_ray *ray, t_vert pt2, t_vert pt3, t_vert pt4)
{
	double		denominator;
	double		t;
	double		u;
	t_vert	pt1;
	t_vert	res;

	pt1 = ray->ray.pt1;
	res.z = 0;
	denominator = (pt1.x - pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x - pt4.x);
	if (!denominator)
		return (res);
	t = (pt1.x - pt3.x) * (pt3.y - pt4.y) - (pt1.y - pt3.y) * (pt3.x - pt4.x);
	u = (pt1.x - pt3.x) * (pt1.y - pt2.y) - (pt1.y - pt3.y) * (pt1.x - pt2.x);
	t /= denominator;
	u /= denominator;
	if (t >= 0 && u >= 0 && u <= 1)
	{
		res.z = u + 1;
		res.x = pt1.x + t * (pt2.x - pt1.x);
		res.y = pt1.y + t * (pt2.y - pt1.y);
	}
	return (res);
}

void	ray_walling(t_wall *walls, t_ray *ray)
{
	int			index;
	t_vert	pt4;
	t_vert	intersection;
	double		dist;

	pt4.x = ray->ray.pt1.x + cos(ray->angle); //not opti to do it here and in ray_dooring and ray_portaling
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	while (walls)
	{
		index = 0;
		while (index < 4)
		{
			if (walls->edges[index].side != CUT)
			{
				intersection = get_inter(ray, pt4, walls->edges[index].pt1, walls->edges[index].pt2);
				if (intersection.z)
				{
					dist = get_dist(ray->ray.pt1, intersection);
					if (dist < ray->dist)
					{
						ray->ray.pt2 = intersection;
						ray->dist = dist;
						ray->hit = walls->edges[index].side;
						ray->u = intersection.z - 1;
					}
				}
			}
			++index;
		}
		walls = walls->next;
	}
}

// static void	ray_walling_fov(t_player *player, t_wall *walls, t_ray *ray, t_set *settings)
// {
// 	int			index;
// 	t_vert	pt4;
// 	t_vert	intersection;
// 	double		dist;

// 	pt4.x = player->pos.x + cos(ray->angle) * settings->fov_dist;
// 	pt4.y = player->pos.y - sin(ray->angle) * settings->fov_dist;
// 	ray->dist = 10000;
// 	set_point(&ray->ray.pt1, player->pos.x, player->pos.y, 0);
// 	while (walls)
// 	{
// 		index = 0;
// 		while (index < 4)
// 		{
// 			if (walls->edges[index].side != CUT)
// 			{
// 				intersection = get_inter_fov(ray, pt4, walls->edges[index].pt1, walls->edges[index].pt2);
// 				dist = get_dist(player->pos, intersection);
// 				if (intersection.z && dist < ray->dist)
// 				{
// 					ray->ray.pt2 = intersection;
// 					ray->dist = dist;
// 					ray->hit = walls->edges[index].side;
// 				}
// 				else if (!intersection.z && settings->fov_dist < ray->dist)
// 				{
// 					ray->ray.pt2 = pt4;
// 					ray->dist = settings->fov_dist;
// 					ray->hit = CUT;
// 				}
// 			}
// 			++index;
// 		}
// 		walls = walls->next;
// 	}
// }

// t_vert	get_inter_fov(t_ray *ray, t_vert pt2, t_vert pt3, t_vert pt4)
// {
// 	double		denominator;
// 	double		t;
// 	double		u;
// 	t_vert	pt1;
// 	t_vert	res;

// 	pt1 = ray->ray.pt1;
// 	res.z = 0;
// 	denominator = (pt1.x - pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x - pt4.x);
// 	if (!denominator)
// 		return (res);
// 	t = (pt1.x - pt3.x) * (pt3.y - pt4.y) - (pt1.y - pt3.y) * (pt3.x - pt4.x);
// 	u = (pt1.x - pt3.x) * (pt1.y - pt2.y) - (pt1.y - pt3.y) * (pt1.x - pt2.x);
// 	t /= denominator;
// 	u /= denominator;
// 	if (t >= 0 && t <= 1 && u >= 0 && u <= 1)
// 	{
// 		res.z = 1;
// 		res.x = pt1.x + t * (pt2.x - pt1.x);
// 		res.y = pt1.y + t * (pt2.y - pt1.y);
// 		ray->u = u;
// 	}
// 	return (res);
// }
