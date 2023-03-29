/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:31:01 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/29 11:18:44 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vert	get_inter(t_ray *ray, t_vert pt2, t_vert pt3, t_vert pt4)
{
	double	denominator;
	double	t;
	double	u;
	t_vert	pt1;
	t_vert	res;

	pt1 = ray->ray.pt1;
	res.z = 0;
	denominator = (pt1.x - pt2.x) * (pt3.y - pt4.y)
		- (pt1.y - pt2.y) * (pt3.x - pt4.x);
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
	t_vert	pt4;
	t_vert	intersection;
	double	dist;

	pt4.x = ray->ray.pt1.x + cos(ray->angle);
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	while (walls)
	{
		intersection = get_inter(ray, pt4, walls->wline.pt1, walls->wline.pt2);
		if (intersection.z)
		{
			dist = get_dist(ray->ray.pt1, intersection);
			if (dist < ray->dist)
			{
				ray->ray.pt2 = intersection;
				ray->dist = dist;
				ray->hit = walls->wline.side;
				ray->u = ft_fmod((intersection.z - 1) * walls->size, 1);
			}
		}
		walls = walls->next;
	}
}
