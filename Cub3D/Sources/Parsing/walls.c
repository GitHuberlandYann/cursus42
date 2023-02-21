#include "cub3d.h"

// static t_wall	*new_wall(int x, int y)
// {
// 	t_wall	*res;

// 	res = ft_malloc(sizeof(*res), "add_wall");
// 	res->x = x;
// 	res->y = y;
// 	set_point(&res->edges[NO].pt1, x + 0.5, y - 0.5, 0);
// 	set_point(&res->edges[NO].pt2, x - 0.5, y - 0.5, 0);
// 	res->edges[NO].side = NO;
// 	set_point(&res->edges[EA].pt1, x + 0.5, y + 0.5, 0);
// 	set_point(&res->edges[EA].pt2, x + 0.5, y - 0.5, 0);
// 	res->edges[EA].side = EA;
// 	set_point(&res->edges[SO].pt1, x - 0.5, y + 0.5, 0);
// 	set_point(&res->edges[SO].pt2, x + 0.5, y + 0.5, 0);
// 	res->edges[SO].side = SO;
// 	set_point(&res->edges[WE].pt1, x - 0.5, y - 0.5, 0);
// 	set_point(&res->edges[WE].pt2, x - 0.5, y + 0.5, 0);
// 	res->edges[WE].side = WE;
// 	res->next = 0;
// 	res->last = 0;
// 	return (res);
// }

static int	add_wall(t_map *map, t_parsing *curr, int x, int y)
{
	if (curr->prev && x && x < curr->prev->size && ft_strchr("0XP", curr->prev->line[x])
		&& !(curr->line[x - 1] == '1' && ft_strchr("0XP", curr->prev->line[x - 1])))
		new_wall_north(map, curr, x, y);
	if (curr->next && x && x < curr->next->size && ft_strchr("0XP", curr->next->line[x])
		&& !(curr->line[x - 1] == '1' && ft_strchr("0XP", curr->next->line[x - 1])))
		new_wall_south(map, curr, x, y);
	if (x > 1 && curr->prev && curr->next && ft_strchr("0XP", curr->line[x - 1])
		&& !(curr->prev->line[x] == '1' && ft_strchr("0XP", curr->prev->line[x - 1])))
		new_wall_west(map, curr, x, y);
	if (x < curr->size - 1 && curr->prev && curr->next && ft_strchr("0XP", curr->line[x + 1])
		&& !(curr->prev->line[x] == '1' && ft_strchr("0XP", curr->prev->line[x + 1])))
		new_wall_east(map, curr, x, y);
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
		// printf("debug %s", tmp->line);
		while (tmp->line[index])
		{
			if (tmp->line[index] == '1')
				add_wall(map, tmp, index, y);
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
