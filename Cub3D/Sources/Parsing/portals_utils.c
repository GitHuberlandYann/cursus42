#include "cub3d.h"

static void	set_portal_line(t_portal *target, int x, int y)
{
	if (target->pline.side == NO)
	{
		set_point(&target->pline.pt1, x + 0.5, y, 0);
		set_point(&target->pline.pt2, x - 0.5, y, 0);
	}
	else if (target->pline.side == SO)
	{
		set_point(&target->pline.pt1, x - 0.5, y, 0);
		set_point(&target->pline.pt2, x + 0.5, y, 0);
	}
	else if (target->pline.side == EA)
	{
		set_point(&target->pline.pt1, x, y + 0.5, 0);
		set_point(&target->pline.pt2, x, y - 0.5, 0);
	}
	else if (target->pline.side == WE)
	{
		set_point(&target->pline.pt1, x, y - 0.5, 0);
		set_point(&target->pline.pt2, x, y + 0.5, 0);
	}
}

static int	charge_portal(t_map *map, int x, int y, t_side orientation)
{
	t_portal	*target;

	target = map->portals;
	while (target)
	{
		if (target->num == map->portal_count)
		{
			target->x = x;
			target->y = y;
			target->pline.side = orientation;
			set_portal_line(target, x, y);
			return (0);
		}
		target = target->next;
	}
	return (output_error(MSG_NOLINK));
}

static int	set_other_orientations(t_parsing *line, int x, t_side *orientation)
{
	if (line->line[x - 1] != '1'
		&& (line->line[x + 1] == '1' || line->line[x + 1] == 'P')
		&& line->prev->line[x] == '1' && line->next->line[x] == '1')
	{
		*orientation = WE;
		if (flood_fill(line, x - 1))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else if ((line->line[x - 1] == '1' || line->line[x - 1] == 'P')
		&& line->line[x + 1] != '1' && line->prev->line[x] == '1'
		&& line->next->line[x] == '1')
	{
		*orientation = EA;
		if (flood_fill(line, x + 1))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else
		return (output_error(MSG_CENTER_PORTAL));
	return (0);
}

int	set_portal(t_map *map, t_parsing *line, int x, t_side orientation)
{
	if (!x || !line->line_number || !line->next || x >= line->prev->size
		|| x >= line->next->size)
		return (output_error(MSG_PORTAL_BORDER));
	if (line->line[x - 1] == '1' && line->line[x + 1] == '1'
		&& line->prev->line[x] != '1'
		&& (line->next->line[x] == '1' || line->next->line[x] == 'P'))
	{
		orientation = NO;
		if (flood_fill(line->prev, x))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else if (line->line[x - 1] == '1' && line->line[x + 1] == '1'
		&& (line->prev->line[x] == '1' || line->prev->line[x] == 'P')
		&& line->next->line[x] != '1')
	{
		orientation = SO;
		if (flood_fill(line->next, x))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else if (set_other_orientations(line, x, &orientation))
		return (1);
	if (charge_portal(map, x, line->line_number, orientation))
		return (1);
	++map->portal_count;
	return (0);
}
