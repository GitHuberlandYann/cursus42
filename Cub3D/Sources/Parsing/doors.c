//add header here
#include "cub3d.h"

static void	set_horizontal_door(t_door *door, int x, int y)
{
	set_point(&door->edges[0].pt1, x - 0.5, y - 0.5, 0);
	set_point(&door->edges[0].pt2, x - 0.5, y + 0.5, 0);
	door->edges[0].side = EA;
	set_point(&door->edges[1].pt1, x - 0.5, y, 0);
	set_point(&door->edges[1].pt2, x + 0.5, y, 0);
	door->edges[1].side = DOOR;
	set_point(&door->edges[2].pt1, x + 0.5, y - 0.5, 0);
	set_point(&door->edges[2].pt2, x + 0.5, y + 0.5, 0);
	door->edges[2].side = WE;
}

static void	set_vertical_door(t_door *door, int x, int y)
{
	set_point(&door->edges[0].pt1, x - 0.5, y - 0.5, 0);
	set_point(&door->edges[0].pt2, x + 0.5, y - 0.5, 0);
	door->edges[0].side = NO;
	set_point(&door->edges[1].pt1, x, y - 0.5, 0);
	set_point(&door->edges[1].pt2, x, y + 0.5, 0);
	door->edges[1].side = DOOR;
	set_point(&door->edges[2].pt1, x - 0.5, y + 0.5, 0);
	set_point(&door->edges[2].pt2, x + 0.5, y + 0.5, 0);
	door->edges[2].side = SO;
}

static t_door	*new_door(int x, int y, t_side orientation)
{
	t_door	*res;

	res = ft_malloc(sizeof(*res), "add_door");
	res->x = x;
	res->y = y;
	if (orientation == NO)
		set_horizontal_door(res, x, y);
	else
		set_vertical_door(res, x, y);
	res->next = 0;
	res->last = 0;
	return (res);
}

int	add_door(t_map *map, t_parsing *line, int x, int y)
{
	t_side	orientation;

	if (!x || !y || !line->next || x >= line->prev->size || x >= line->next->size)
		return (output_error(MSG_DOOR_BORDER));
	if (line->line[x - 1] == '1' && line->line[x + 1] == '1' && ft_strchr("0D", line->prev->line[x]) && ft_strchr("0D", line->next->line[x]))
		orientation = NO;
	else if (line->prev->line[x] == '1' && line->next->line[x] == '1' && ft_strchr("0D", line->line[x - 1]) && ft_strchr("0D", line->line[x + 1]))
		orientation = WE;
	else
		return (output_error(MSG_CENTER_DOOR));

	if (!map->doors)
	{
		map->doors = new_door(x, y, orientation);
		map->doors->last = map->doors;
	}
	else
	{
		map->doors->last->next = new_door(x, y, orientation);
		map->doors->last = map->doors->last->next;
	}
	return (0);
}
