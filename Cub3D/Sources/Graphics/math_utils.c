/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:36:03 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/12 18:02:38 by marvin           ###   ########.fr       */
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
	pt->x = cos(map->player->direction - M_PI / 2) * (pt2->x - map->player->pos.x)
		- sin(map->player->direction - M_PI / 2) * (pt2->y - map->player->pos.y)
		+ map->map_width / 2;
	pt->y = sin(map->player->direction - M_PI / 2) * (pt2->x - map->player->pos.x)
		+ cos(map->player->direction - M_PI / 2) * (pt2->y - map->player->pos.y)
		+ map->map_height - map->map_height / 10;
	if (scale)
	{
		pt->x *= map->wall_width;
		pt->y *= map->wall_width;
	}
}

int	in_circle(t_vertice *pt, double x, double y, double radius)
{
	t_vertice	center;

	center.x = x;
	center.y = y;
	return (get_dist(*pt, center) <= radius);
}

void	set_angles(t_cub *cub)
{
	int	index;

	index = -1;
	while (++index < WIN_WIDTH)
	{
		cub->angles[index] = atan((WIN_WIDTH / 2 - index) / cub->settings->fov_width);
	}
}
