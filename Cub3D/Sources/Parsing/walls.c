/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:03:46 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 19:10:18 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall	*new_wall(int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), "add_wall");
	res->x = x;
	res->y = y;
	res->north.pt1.x = x - 0.5;
	res->north.pt1.y = y - 0.5;
	res->north.pt2.x = x + 0.5;
	res->north.pt2.y = y - 0.5;
	res->east.pt1.x = x + 0.5;
	res->east.pt1.y = y - 0.5;
	res->east.pt2.x = x + 0.5;
	res->east.pt2.y = y + 0.5;
	res->south.pt1.x = x + 0.5;
	res->south.pt1.y = y + 0.5;
	res->south.pt2.x = x - 0.5;
	res->south.pt2.y = y + 0.5;
	res->west.pt1.x = x - 0.5;
	res->west.pt1.y = y + 0.5;
	res->west.pt2.x = x - 0.5;
	res->west.pt2.y = y - 0.5;
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
	free_return_lines(lines);
	map->width = map->o_right - map->o_left;
	map->height = map->o_down - map->o_up;
	map->wall_width = MINIMAP_WIDTH / map->width;
	map->wall_height = MINIMAP_HEIGHT / map->height;
}

int	flood_fill(t_parsing *current, int index)
{
	int	res;

	if ((!index && current->line[index] != '1') || !current || index >= current->size
		|| current->line[index] == ' ' || current->line[index] == '\n')
		return (1);
	if (current->line[index] == '1' || current->line[index] == 'X')
		return (0);
	current->line[index] = 'X';
	res = flood_fill(current, index + 1);
	if (!res)
		res = flood_fill(current, index - 1);
	if (!res)
		res = flood_fill(current->prev, index);
	if (!res)
		res = flood_fill(current->next, index);
	return (res);
}
