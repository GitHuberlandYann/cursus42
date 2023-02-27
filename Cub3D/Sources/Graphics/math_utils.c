/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:36:03 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/27 14:40:13 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_dist(t_vert pt1, t_vert pt2)
{
	return (sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2)));
}

void	set_point(t_vert *pt, double x, double y, double z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

void	set_point_follow(t_vert *pt, t_vert *pt2, t_map *map, t_set *settings)
{
	double	direction;

	if (settings->mini_follow)
	{
		direction = map->player->direction;
		pt->x = cos(direction - M_PI_2) * (pt2->x - map->player->pos.x)
			- sin(direction - M_PI_2) * (pt2->y - map->player->pos.y);
		pt->y = sin(direction - M_PI_2) * (pt2->x - map->player->pos.x)
			+ cos(direction - M_PI_2) * (pt2->y - map->player->pos.y);
	}
	else
	{
		pt->x = pt2->x - map->player->pos.x;
		pt->y = pt2->y - map->player->pos.y;
	}
	pt->x *= settings->wall_width;
	pt->y *= settings->wall_width;
	pt->x += settings->offset.x + MAP_RADIUS;
	pt->y += settings->offset.y + MAP_RADIUS;
}

int	in_circle(t_vert *pt, double x, double y, double radius)
{
	t_vert	center;

	center.x = x;
	center.y = y;
	return (get_dist(*pt, center) <= radius);
}

void	set_ray_angles(double fov_width, t_player *player, t_player *playerbis)
{
	int		index;

	index = -1;
	while (++index < WIN_WIDTH)
	{
		player->rays[index].preangle = atan((WIN_WIDTH_2 - index) / fov_width);
		if (playerbis)
			playerbis->rays[index].preangle = atan((WIN_WIDTH_2 - index) / fov_width);
	}
}
