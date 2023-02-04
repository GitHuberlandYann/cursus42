/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:31:01 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/04 17:40:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_walling_fov(t_player *player, t_wall *walls, t_ray *ray, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	double		dist;

	pt4.x = player->pos.x + cos(ray->angle) * settings->fov_dist;
	pt4.y = player->pos.y - sin(ray->angle) * settings->fov_dist;
	ray->dist = 10000;
	set_point(&ray->ray.pt1, player->pos.x, player->pos.y, 0);
	while (walls)
	{
		index = 0;
		while (index < 4)
		{
			if (walls->edges[index].side != CUT)
			{
				intersection = get_inter_fov(ray, pt4, walls->edges[index].pt1, walls->edges[index].pt2);
				dist = get_dist(player->pos, intersection);
				if (intersection.z && dist < ray->dist)
				{
					ray->ray.pt2 = intersection;
					ray->dist = dist;
					ray->hit = walls->edges[index].side;
				}
				else if (!intersection.z && settings->fov_dist < ray->dist)
				{
					ray->ray.pt2 = pt4;
					ray->dist = settings->fov_dist;
					ray->hit = CUT;
				}
			}
			++index;
		}
		walls = walls->next;
	}
}

t_vertice	get_inter(t_ray *ray, t_vertice pt2, t_vertice pt3, t_vertice pt4)
{
	double		denominator;
	double		t;
	double		u;
	t_vertice	pt1;
	t_vertice	res;

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
		res.z = 1;
		res.x = pt1.x + t * (pt2.x - pt1.x);
		res.y = pt1.y + t * (pt2.y - pt1.y);
		ray->u = u;
	}
	return (res);
}

t_vertice	get_inter_fov(t_ray *ray, t_vertice pt2, t_vertice pt3, t_vertice pt4)
{
	double		denominator;
	double		t;
	double		u;
	t_vertice	pt1;
	t_vertice	res;

	pt1 = ray->ray.pt1;
	res.z = 0;
	denominator = (pt1.x - pt2.x) * (pt3.y - pt4.y) - (pt1.y - pt2.y) * (pt3.x - pt4.x);
	if (!denominator)
		return (res);
	t = (pt1.x - pt3.x) * (pt3.y - pt4.y) - (pt1.y - pt3.y) * (pt3.x - pt4.x);
	u = (pt1.x - pt3.x) * (pt1.y - pt2.y) - (pt1.y - pt3.y) * (pt1.x - pt2.x);
	t /= denominator;
	u /= denominator;
	if (t >= 0 && t <= 1 && u >= 0 && u <= 1)
	{
		res.z = 1;
		res.x = pt1.x + t * (pt2.x - pt1.x);
		res.y = pt1.y + t * (pt2.y - pt1.y);
		ray->u = u;
	}
	return (res);
}

void	ray_walling(t_player *player, t_wall *walls, t_ray *ray, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	double		dist;

	if (settings->fov_enable)
		return (ray_walling_fov(player, walls, ray, settings));
	pt4.x = player->pos.x + cos(ray->angle);
	pt4.y = player->pos.y - sin(ray->angle);
	ray->dist = 10000;
	set_point(&ray->ray.pt1, player->pos.x, player->pos.y, 0);
	while (walls)
	{
		index = 0;
		while (index < 4)
		{
			if (walls->edges[index].side != CUT)
			{
				intersection = get_inter(ray, pt4, walls->edges[index].pt1, walls->edges[index].pt2);
				dist = get_dist(player->pos, intersection);
				if (intersection.z && dist < ray->dist)
				{
					ray->ray.pt2 = intersection;
					ray->dist = dist;
					ray->hit = walls->edges[index].side;
				}
			}
			++index;
		}
		walls = walls->next;
	}
}
