#include "cub3d.h"

static void	add_wall(t_map *map, t_wall *wall)
{
	if (!map->walls)
	{
		map->walls = wall;
		map->walls->last = map->walls;
	}
	else
	{
		map->walls->last->next = wall;
		map->walls->last = map->walls->last->next;
	}
	// printf("adding wall\n");
}

void	new_wall_north(t_map *map, t_parsing *curr, int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), "new_wall_north");
	res->wline.side = NO;
	res->size = 0;
	while (curr->line[x + res->size + 1] == '1' && ft_strchr("0XP", curr->prev->line[x + res->size + 1]))
		++res->size;
	set_point(&res->wline.pt1, x + res->size + 0.5, y - 0.5, 0);
 	set_point(&res->wline.pt2, x - 0.5, y - 0.5, 0);
	++res->size;
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}

void	new_wall_south(t_map *map, t_parsing *curr, int x, int y)
{
	t_wall	*res;

	res = ft_malloc(sizeof(*res), "new_wall_south");
	res->wline.side = SO;
	res->size = 0;
	while (curr->line[x + res->size + 1] == '1' && ft_strchr("0XP", curr->next->line[x + res->size + 1]))
		++res->size;
	set_point(&res->wline.pt1, x - 0.5, y + 0.5, 0);
	set_point(&res->wline.pt2, x + res->size + 0.5, y + 0.5, 0);
	++res->size;
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}

void	new_wall_west(t_map *map, t_parsing *curr, int x, int y)
{
	t_wall		*res;
	t_parsing	*tmp;

	res = ft_malloc(sizeof(*res), "new_wall_west");
	res->wline.side = WE;
	res->size = 0;
	tmp = curr->next;
	while (tmp->line[x] == '1' && ft_strchr("0XP", tmp->line[x - 1]))
	{
		++res->size;
		tmp = tmp->next;
	}
	set_point(&res->wline.pt1, x - 0.5, y - 0.5, 0);
	set_point(&res->wline.pt2, x - 0.5, y + res->size + 0.5, 0);
	++res->size;
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}

void	new_wall_east(t_map *map, t_parsing *curr, int x, int y)
{
	t_wall		*res;
	t_parsing	*tmp;

	res = ft_malloc(sizeof(*res), "new_wall_east");
	res->wline.side = EA;
	res->size = 0;
	tmp = curr->next;
	while (tmp->line[x] == '1' && ft_strchr("0XP", tmp->line[x + 1]))
	{
		++res->size;
		tmp = tmp->next;
	}
	set_point(&res->wline.pt1, x + 0.5, y + res->size + 0.5, 0);
	set_point(&res->wline.pt2, x + 0.5, y - 0.5, 0);
	++res->size;
	res->next = 0;
	res->last = 0;
	add_wall(map, res);
}