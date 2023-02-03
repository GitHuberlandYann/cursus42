/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:31:01 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/03 19:06:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vertice	ray_walling_fov(t_player *player, t_wall *walls, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	t_vertice	shortest;

	pt4.x = player->pos.x + cos(settings->ray_angle) * settings->fov_dist;
	pt4.y = player->pos.y - sin(settings->ray_angle) * settings->fov_dist;
	shortest.z = 10000;
	while (walls)
	{
		index = 0;
		while (index < 4)
		{
			if (walls->edges[index].side != CUT)
			{
				intersection = get_inter_fov(player->pos, pt4, walls->edges[index].pt1, walls->edges[index].pt2);
				if (intersection.z && get_dist(player->pos, intersection) < shortest.z)
				{
					shortest = intersection;
					shortest.z = get_dist(player->pos, intersection);
				}
				else if (!intersection.z && settings->fov_dist < shortest.z)
				{
					shortest = pt4;
					shortest.z = settings->fov_dist;
				}
			}
			++index;
		}
		walls = walls->next;
	}
	return (shortest);
}

t_vertice	get_inter(t_vertice pt1, t_vertice pt2, t_vertice pt3, t_vertice pt4)
{
	double		denominator;
	double		t;
	double		u;
	t_vertice	res;

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
	}
	return (res);
}

t_vertice	get_inter_fov(t_vertice pt1, t_vertice pt2, t_vertice pt3, t_vertice pt4)
{
	double		denominator;
	double		t;
	double		u;
	t_vertice	res;

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
	}
	return (res);
}

t_vertice	ray_walling(t_player *player, t_wall *walls, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	t_vertice	shortest;

	if (settings->fov_enable)
		return (ray_walling_fov(player, walls, settings));
	pt4.x = player->pos.x + cos(settings->ray_angle);
	pt4.y = player->pos.y - sin(settings->ray_angle);
	shortest.z = 10000;
	while (walls)
	{
		index = 0;
		while (index < 4)
		{
			if (walls->edges[index].side != CUT)
			{
				intersection = get_inter(player->pos, pt4, walls->edges[index].pt1, walls->edges[index].pt2);
				if (intersection.z && get_dist(player->pos, intersection) < shortest.z)
				{
					shortest = intersection;
					shortest.z = get_dist(player->pos, intersection);
				}
			}
			++index;
		}
		walls = walls->next;
	}
	return (shortest);
}
