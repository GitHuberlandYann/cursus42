/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:49:10 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 10:49:10 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_new_wall(t_map *map, t_parsing *curr, int x)
{
	if (curr->prev && x && x < curr->prev->size
		&& ft_strchr("0XP", curr->prev->line[x]) && !(curr->line[x - 1] == '1'
			&& ft_strchr("0XP", curr->prev->line[x - 1])))
		new_wall_north(map, curr, x, curr->line_number);
	if (curr->next && x && x < curr->next->size
		&& ft_strchr("0XP", curr->next->line[x]) && !(curr->line[x - 1] == '1'
			&& ft_strchr("0XP", curr->next->line[x - 1])))
		new_wall_south(map, curr, x, curr->line_number);
	if (x > 1 && curr->prev && curr->next && ft_strchr("0XP", curr->line[x - 1])
		&& !(curr->prev->line[x] == '1'
			&& ft_strchr("0XP", curr->prev->line[x - 1])))
		new_wall_west(map, curr, x, curr->line_number);
	if (x < curr->size - 1 && curr->prev && curr->next
		&& ft_strchr("0XP", curr->line[x + 1]) && !(curr->prev->line[x] == '1'
			&& ft_strchr("0XP", curr->prev->line[x + 1])))
		new_wall_east(map, curr, x, curr->line_number);
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

		// printf("debug %s", tmp->line);
void	create_walls(t_map *map, t_parsing *lines, t_parsing *tmp)
{
	int			index;

	while (tmp)
	{
		index = 0;
		while (tmp->line[index])
		{
			if (tmp->line[index] == '1')
				add_new_wall(map, tmp, index);
			else if (ft_strchr("dD", tmp->line[index])
				&& add_door(map, tmp, index))
				return (free_return_all(lines, map));
			else if (tmp->line[index] == 'P' && set_portal(map, tmp, index, NO))
				return (free_return_all(lines, map));
			else if (tmp->line[index] == 'A'
				&& add_animated_wall(map, tmp, index))
				return (free_return_all(lines, map));
			++index;
		}
		tmp = tmp->next;
	}
	if (link_empty(map))
		return (free_return_all(lines, map));
	free_return_lines(lines, map, 0);
}
