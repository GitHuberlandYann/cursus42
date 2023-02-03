/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:03:46 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/03 16:07:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall	*get_wallat(t_wall *walls, int x, int y)
{
	while (walls)
	{
		if (walls->x == x && walls->y == y)
			return (walls);
		walls = walls->next;
	}
	return (0);
}

static void	remove_invisible_walls(t_wall *walls)
{
	t_wall	*other;

	other = get_wallat(walls, walls->last->x - 1, walls->last->y);
	if (other)
	{
		other->edges[EA].side = CUT;
		walls->last->edges[WE].side = CUT;
	}
	other = get_wallat(walls, walls->last->x, walls->last->y - 1);
	if (other)
	{
		other->edges[SO].side = CUT;
		walls->last->edges[NO].side = CUT;
	}
}

static t_wall	*new_wall(int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), "add_wall");
	res->x = x;
	res->y = y;
	set_point(&res->edges[NO].pt1, x - 0.5, y - 0.5, 0);
	set_point(&res->edges[NO].pt2, x + 0.5, y - 0.5, 0);
	res->edges[NO].side = NO;
	set_point(&res->edges[EA].pt1, x + 0.5, y - 0.5, 0);
	set_point(&res->edges[EA].pt2, x + 0.5, y + 0.5, 0);
	res->edges[EA].side = EA;
	set_point(&res->edges[SO].pt1, x + 0.5, y + 0.5, 0);
	set_point(&res->edges[SO].pt2, x - 0.5, y + 0.5, 0);
	res->edges[SO].side = SO;
	set_point(&res->edges[WE].pt1, x - 0.5, y + 0.5, 0);
	set_point(&res->edges[WE].pt2, x - 0.5, y - 0.5, 0);
	res->edges[WE].side = WE;
	res->next = 0;
	res->last = 0;
	return (res);
}

static int	add_wall(t_map *map, int x, int y)
{
	if (!map->walls)
	{
		map->walls = new_wall(x, y);
		map->walls->last = map->walls;
		map->o_left = x;
		map->o_right = x;
		map->o_up = y;
		map->o_down = y;
	}
	else
	{
		map->walls->last->next = new_wall(x, y);
		map->walls->last = map->walls->last->next;
		if (x < map->o_left)
			map->o_left = x;
		if (x > map->o_right)
			map->o_right = x;
		if (y < map->o_up)
			map->o_up = y;
		if (y > map->o_down)
			map->o_down = y;
	}
	remove_invisible_walls(map->walls);
	return (0);
}

void	create_walls(t_map *map, t_parsing *lines)
{
	int			index;
	int			y;
	t_parsing	*tmp;
	
	tmp = lines;
	y = 0;
	while (tmp)
	{
		index = 0;
		while (tmp->line[index])
		{
			if (tmp->line[index] == '1')
				add_wall(map, index, y);
			++index;
		}
		++y;
		tmp = tmp->next;
	}
	free_return_lines(lines, map, 0);
	map->map_width = map->o_right - map->o_left;
	map->map_height = map->o_down - map->o_up;
	map->wall_width = get_min(MINIMAP_WIDTH / map->map_width,
			MINIMAP_WIDTH / map->map_height);
}
