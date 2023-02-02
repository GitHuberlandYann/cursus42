/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:36:03 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/02 14:23:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_dist(t_vertice pt1, t_vertice pt2)
{
	return (sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2)));
}

void	set_point(t_vertice *pt, double x, double y, double z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

void	set_point_follow(t_vertice *pt, t_vertice *pt2, t_map *map, int scale)
{
	pt->x = cos(map->player->direction - M_PI / 2) * (pt2->x - map->player->offset.x)
		- sin(map->player->direction - M_PI / 2) * (pt2->y - map->player->offset.y)
		+ map->map_width / 2;
	pt->y = sin(map->player->direction - M_PI / 2) * (pt2->x - map->player->offset.x)
		+ cos(map->player->direction - M_PI / 2) * (pt2->y - map->player->offset.y)
		+ map->map_height - map->map_height / 10;
	if (scale)
	{
		pt->x *= map->wall_width;
		pt->y *= map->wall_width;
	}
}

double	get_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
