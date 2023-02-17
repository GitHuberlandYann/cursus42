/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:03:46 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/17 14:51:46 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	isthere_doorat(t_door *doors, int x, int y)
{
	while (doors)
	{
		if (doors->x == x && doors->y == y)
			return (1);
		doors = doors->next;
	}
	return (0);
}

static void	remove_invisible_walls(t_wall *walls, t_door *doors)
{
	t_wall	*other;

	other = get_wallat(walls, walls->last->x - 1, walls->last->y);
	if (other)
	{
		other->edges[EA].side = CUT;
		walls->last->edges[WE].side = CUT;
	}
	else if (isthere_doorat(doors, walls->last->x - 1, walls->last->y))
			walls->last->edges[WE].side = CUT;
	other = get_wallat(walls, walls->last->x, walls->last->y - 1);
	if (other)
	{
		other->edges[SO].side = CUT;
		walls->last->edges[NO].side = CUT;
	}
	else if (isthere_doorat(doors, walls->last->x, walls->last->y - 1))
			walls->last->edges[NO].side = CUT;
}

static t_wall	*new_wall(int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), "add_wall");
	res->x = x;
	res->y = y;
	set_point(&res->edges[NO].pt1, x + 0.5, y - 0.5, 0);
	set_point(&res->edges[NO].pt2, x - 0.5, y - 0.5, 0);
	res->edges[NO].side = NO;
	set_point(&res->edges[EA].pt1, x + 0.5, y + 0.5, 0);
	set_point(&res->edges[EA].pt2, x + 0.5, y - 0.5, 0);
	res->edges[EA].side = EA;
	set_point(&res->edges[SO].pt1, x - 0.5, y + 0.5, 0);
	set_point(&res->edges[SO].pt2, x + 0.5, y + 0.5, 0);
	res->edges[SO].side = SO;
	set_point(&res->edges[WE].pt1, x - 0.5, y - 0.5, 0);
	set_point(&res->edges[WE].pt2, x - 0.5, y + 0.5, 0);
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
	}
	else
	{
		map->walls->last->next = new_wall(x, y);
		map->walls->last = map->walls->last->next;
	}
	remove_invisible_walls(map->walls, map->doors);
	return (0);
}

static void	free_return_all(t_parsing *lines, t_map *map)
{
	t_wall		*tmp_wall;
	t_door		*tmp_door;

	while (map->walls)
	{
		tmp_wall = map->walls;
		map->walls = map->walls->next;
		free(tmp_wall);
	}
	while (map->doors)
	{
		tmp_door = map->doors;
		map->doors = map->doors->next;
		free(tmp_door);
	}
	free_return_lines(lines, map, 1);
}

t_wall	*get_wallat(t_wall *walls, int x, int y)
{
	while (walls)
	{
		if (walls->x == x && walls->y == y)
			return (walls);
		walls = walls->next;
	}
	return (0);
}

void	create_walls(t_map *map, t_parsing *lines)
{
	int			index;
	int			y;
	t_parsing	*tmp;

	tmp = lines;
	y = 0;
	map->portal_count = 0;
	map->hasdoor = 0;
	while (tmp)
	{
		index = 0;
		while (tmp->line[index])
		{
			if (tmp->line[index] == '1')
				add_wall(map, index, y);
			else if (ft_strchr("dD", tmp->line[index]) && add_door(map, tmp, index, y))
				return (free_return_all(lines, map));
			else if (tmp->line[index] == 'P' && set_portal(map, tmp, index, y))
				return (free_return_all(lines, map));
			++index;
		}
		++y;
		tmp = tmp->next;
	}
	if (link_empty(map) || conflict_pt(map))
		return (free_return_all(lines, map));
	free_return_lines(lines, map, 0);
}
