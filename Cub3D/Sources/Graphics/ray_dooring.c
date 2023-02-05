/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dooring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:47:55 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/05 17:47:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_dooring(t_player *player, t_door *doors, t_ray *ray)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	double		dist;

	(void)player;//never used
	pt4.x = ray->ray.pt1.x + cos(ray->angle);
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	while (doors)
	{
		index = 0;
		while (index < 3)
		{
			if (doors->edges[index].side != CUT)
			{
				intersection = get_inter(ray, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				dist = get_dist(ray->ray.pt1, intersection);
				if (intersection.z && dist < ray->dist)
				{
					ray->ray.pt2 = intersection;
					ray->dist = dist;
					ray->hit = doors->edges[index].side;
				}
			}
			++index;
		}
		doors = doors->next;
	}
}

void	try_door(t_player *player, t_door *doors)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	t_ray		ray;
	t_line		*target;

	ray.dist = 10000;
	set_point(&ray.ray.pt1, player->pos.x, player->pos.y, 0);
	target = 0;
	pt4.x = player->pos.x + cos(player->direction);
	pt4.y = player->pos.y - sin(player->direction);
	while (doors)
	{
		index = 0;
		while (index < 3)
		{
			if (doors->edges[index].side == DOOR || doors->edges[index].side == CUT)
			{
				intersection = get_inter(&ray, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				pt4.z = get_dist(player->pos, intersection);
				if (intersection.z && pt4.z < ray.dist)
				{
					ray.dist = pt4.z;
					target = &doors->edges[index];
				}
			}
			++index;
		}
		doors = doors->next;
	}
	if (ray.dist == 10000 || ray.dist > 0.6)
		return ;
	if (target->side == CUT)
		target->side = DOOR;
	else
		target->side = CUT;
}
