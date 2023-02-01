/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:03:46 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 14:03:10 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall	*new_wall(int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), "add_wall");
	res->x = x;
	res->y = y;
	res->next = 0;
	res->last = 0;
	return (res);
}

static int	add_wall(t_wall	**walls, int x, int y)
{
	if (!*walls)
	{
		*walls = new_wall(x, y);
		(*walls)->last = *walls;
	}
	else
	{
		(*walls)->last->next = new_wall(x, y);
		(*walls)->last = (*walls)->last->next;
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
				add_wall(&map->walls, index, y);
			++index;
		}
		++y;
		tmp = tmp->next;
	}
	free_return_lines(lines);
}

int	flood_fill(t_parsing *current, int index)
{
	int	res;

	if (!index || !current || index >= current->size
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
