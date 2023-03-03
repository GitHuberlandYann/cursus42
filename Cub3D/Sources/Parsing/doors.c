/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:48:17 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/05 17:48:17 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_horizontal_door(t_door *door, int x, int y)
{
	set_point(&door->edges[0].pt1, x - 0.5, y - 0.5, 0);
	set_point(&door->edges[0].pt2, x - 0.5, y + 0.5, 0);
	door->edges[0].side = DOORSIDE;
	set_point(&door->edges[1].pt1, x - 0.5, y, 0);
	set_point(&door->edges[1].pt2, x + 0.5, y, 0);
	set_point(&door->door.pt1, x - 0.5, y, 0);
	set_point(&door->door.pt2, x + 0.5, y, 0);
	door->edges[1].side = DOOR;
	set_point(&door->edges[2].pt1, x + 0.5, y - 0.5, 0);
	set_point(&door->edges[2].pt2, x + 0.5, y + 0.5, 0);
	door->edges[2].side = DOORSIDE;
}

static void	set_vertical_door(t_door *door, int x, int y)
{
	set_point(&door->edges[0].pt1, x - 0.5, y - 0.5, 0);
	set_point(&door->edges[0].pt2, x + 0.5, y - 0.5, 0);
	door->edges[0].side = DOORSIDE;
	set_point(&door->edges[1].pt1, x, y - 0.5, 0);
	set_point(&door->edges[1].pt2, x, y + 0.5, 0);
	set_point(&door->door.pt1, x, y - 0.5, 0);
	set_point(&door->door.pt2, x, y + 0.5, 0);
	door->edges[1].side = DOOR;
	set_point(&door->edges[2].pt1, x - 0.5, y + 0.5, 0);
	set_point(&door->edges[2].pt2, x + 0.5, y + 0.5, 0);
	door->edges[2].side = DOORSIDE;
}

static void	add_new_door(t_map *map, int x, int y, t_side orientation)
{
	t_door	*new;

	new = ft_malloc(sizeof(*new), "add_door");
	new->x = x;
	new->y = y;
	new->side = orientation;
	if (orientation == NO)
		set_horizontal_door(new, x, y);
	else
		set_vertical_door(new, x, y);
	new->state = CLOSED;
	new->next = 0;
	new->last = 0;
	if (!map->doors)
		map->doors = new;
	else
		map->doors->last->next = new;
	map->doors->last = new;
}

int	add_door(t_map *map, t_parsing *line, int x)
{
	t_side	orientation;

	if (!map->hasdoor && (!map->ds_textures[0] || !map->ds_textures[1]))
		return (output_error(MSG_DOORTEXTURE));
	map->hasdoor = 1;
	if (!x || !line->line_number || !line->next || x >= line->prev->size
		|| x >= line->next->size)
		return (output_error(MSG_DOOR_BORDER));
	if (line->line[x - 1] == '1' && line->line[x + 1] == '1'
		&& line->prev->line[x] != '1' && line->next->line[x] != '1')
		orientation = NO;
	else if (line->prev->line[x] == '1' && line->next->line[x] == '1'
		&& line->line[x - 1] != '1' && line->line[x + 1] != '1')
		orientation = WE;
	else
		return (output_error(MSG_CENTER_DOOR));
	add_new_door(map, x, line->line_number, orientation);
	return (0);
}
