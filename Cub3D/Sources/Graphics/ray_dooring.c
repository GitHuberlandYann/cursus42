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

void	ray_dooring(t_door *doors, t_ray *ray)
{
	int			index;
	t_vert	pt4;
	t_vert	intersection;
	double		dist;

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
				if (intersection.z)
				{
					dist = get_dist(ray->ray.pt1, intersection);
					if (dist < ray->dist)
					{
						ray->ray.pt2 = intersection;
						ray->dist = dist;
						ray->hit = doors->edges[index].side;
						ray->u = intersection.z - 1;
					}
				}
			}
			++index;
		}
		doors = doors->next;
	}
}

void	try_door(t_player *player, t_door *doors)
{
	t_vert	pt4;
	t_vert	intersection;
	t_ray		ray;
	t_door		*target;

	ray.dist = 10000;
	set_point(&ray.ray.pt1, player->pos.x, player->pos.y, 0);
	target = 0;
	pt4.x = player->pos.x + cos(player->direction);
	pt4.y = player->pos.y - sin(player->direction);
	while (doors)
	{
		intersection = get_inter(&ray, pt4, doors->door.pt1, doors->door.pt2);
		pt4.z = get_dist(player->pos, intersection);
		if (intersection.z && pt4.z < ray.dist)
		{
			ray.dist = pt4.z;
			target = doors;
		}
		doors = doors->next;
	}
	if (ray.dist == 10000 || ray.dist > 0.6)
		return ;
	// if (target->edges[1].side == CUT)
	// 	target->edges[1].side = DOOR;
	// else
	// 	target->edges[1].side = CUT;
	if (target->state == OPEN)
		target->state = CLOSING;
	else if (target->state == CLOSED)
	{
		target->state = OPENING;
		target->timer = 0;
	}
	else if (target->state == OPENING)
		target->state = CLOSING;
	else if (target->state == CLOSING)
	{
		target->state = OPENING;
		target->timer = 0;
	}
}

void	uptdate_doors(t_door *doors, t_key *key)
{
	while (doors)
	{
		if (doors->state == OPENING)
		{
			key->mousedate = 1;
			if (doors->side == WE || doors->side == EA)
			{
				doors->edges[1].pt1.y += 0.01;
				doors->edges[1].pt2.y += 0.01;
			}
			else if (doors->side == NO || doors->side == SO)
			{
				doors->edges[1].pt1.x += 0.01;
				doors->edges[1].pt2.x += 0.01;
			}
			if (doors->edges[1].pt1.x > doors->x + 0.5 || doors->edges[1].pt1.y > doors->y + 0.5)
			{
				doors->state = OPEN;
				doors->edges[1].side = CUT;
			}
		}
		else if (doors->state == CLOSING)
		{
			key->mousedate = 1;
			doors->edges[1].side = DOOR;
			if (doors->side == WE || doors->side == EA)
			{
				doors->edges[1].pt1.y -= 0.01;
				doors->edges[1].pt2.y -= 0.01;
			}
			else if (doors->side == NO || doors->side == SO)
			{
				doors->edges[1].pt1.x -= 0.01;
				doors->edges[1].pt2.x -= 0.01;
			}
			if (doors->edges[1].pt1.y < doors->y - 0.5 || doors->edges[1].pt1.x < doors->x - 0.5)
				doors->state = CLOSED;
		}
		if (doors->state == OPEN && ++doors->timer == 12000)
			doors->state = CLOSING;
		doors = doors->next;
	}
}
