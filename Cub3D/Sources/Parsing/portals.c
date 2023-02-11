/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:48:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/05 17:48:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_portal(t_map *map, int num, int link)
{
	if (!map->portals)
	{
		map->portals = ft_malloc(sizeof(*map->portals), "add_portal");
		map->portals->num = num;
		map->portals->link = link;
		map->portals->pline.side = CUT;
		map->portals->next = 0;
		map->portals->last = map->portals;
	}
	else
	{
		map->portals->last->next = ft_malloc(sizeof(*map->portals), "add_portal");
		map->portals->last = map->portals->last->next;
		map->portals->last->num = num;
		map->portals->last->link = link;
		map->portals->last->pline.side = CUT;
		map->portals->last->next = 0;
		map->portals->last->last = 0;
	}
}

static int	ft_atoi_por(t_map *map, int *index, int sindex, int *number)
{
	if (map->line[*index] == '0' && !ft_strchr(" :\n", map->line[*index + 1]))
		return (output_error(MSG_LINKZEROPAD));
	*number = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		*number = 10 * (*number) + map->line[*index] - '0';
		++(*index);
		if (*number > 255)
			return (output_error(MSG_LINK255));
	}
	if (sindex == *index)
		return (output_error(MSG_LINKUNSET));
	if (map->line[*index] == ':' && map->line[*index + 1] >= '0' && map->line[*index + 1] <= '9')
		++(*index);
	return (0);
}

static int	charge_portal(t_map *map, int x, int y, t_side orientation)
{
	t_portal	*target;

	target = map->portals;
	while (target)
	{
		// printf("debug num %d\n", target->num);
		if (target->num == map->portal_count)
		{
			target->x = x;
			target->y = y;
			target->pline.side = orientation;
			if (orientation == NO)
			{
				set_point(&target->pline.pt1, x + 0.5, y, 0);
				set_point(&target->pline.pt2, x - 0.5, y, 0);
			}
			else if (orientation == SO)
			{
				set_point(&target->pline.pt1, x - 0.5, y, 0);
				set_point(&target->pline.pt2, x + 0.5, y, 0);
			}
			else if (orientation == EA)
			{
				set_point(&target->pline.pt1, x, y + 0.5, 0);
				set_point(&target->pline.pt2, x, y - 0.5, 0);
			}
			else if (orientation == WE)
			{
				set_point(&target->pline.pt1, x, y - 0.5, 0);
				set_point(&target->pline.pt2, x, y + 0.5, 0);
			}
			return (0);
		}
		target = target->next;
	}
	return (output_error(MSG_NOLINK));
}

int	link_portals(t_map *map)
{
	int	index;
	int	num;
	int	link;

	index = 5;
	if (ft_atoi_por(map, &index, index, &num))
		return (1);
	if (ft_atoi_por(map, &index, index, &link))
		return (1);
	if (!only_spaces(map, index))
		return (output_error(MSG_LINKEND));
	add_portal(map, num, link);
	// printf("portal %d linked with %d\n", num, link);
	return (0);
}

int	set_portal(t_map *map, t_parsing *line, int x, int y)
{
	t_side	orientation;

	if (!x || !y || !line->next || x >= line->prev->size || x >= line->next->size)
		return (output_error(MSG_PORTAL_BORDER));
	if (line->line[x - 1] == '1' && line->line[x + 1] == '1' && line->prev->line[x] != '1' && (line->next->line[x] == '1' || line->next->line[x] == 'P'))
	{
		orientation = NO;
		if (flood_fill(line->prev, x))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else if (line->line[x - 1] == '1' && line->line[x + 1] == '1' && (line->prev->line[x] == '1' || line->prev->line[x] == 'P') && line->next->line[x] != '1')
	{
		orientation = SO;
		if (flood_fill(line->next, x))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else if (line->line[x - 1] != '1' && (line->line[x + 1] == '1' || line->line[x + 1] == 'P') && line->prev->line[x] == '1' && line->next->line[x] == '1')
	{
		orientation = WE;
		if (flood_fill(line, x - 1))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else if ((line->line[x - 1] == '1' || line->line[x - 1] == 'P') && line->line[x + 1] != '1' && line->prev->line[x] == '1' && line->next->line[x] == '1')
	{
		orientation = EA;
		if (flood_fill(line, x + 1))
			return (output_error(MSG_UNCLOSEDPORTAL));
	}
	else
		return (output_error(MSG_CENTER_PORTAL));
	if (charge_portal(map, x, y, orientation))
		return (1);
	++map->portal_count;
	return (0);
}

int	link_empty(t_map *map)
{
	t_portal	*tmp;

	tmp = map->portals;
	while (tmp)
	{
		if (tmp->pline.side == CUT || tmp->link >= map->portal_count)
			return (output_error(MSG_UNUSEDLINK));
		tmp = tmp->next;
	}
	return (0);
}

/* We don't handle floor/ceilling textures with portals */
int	conflict_pt(t_map *map)
{
	if (map->portals && map->fc_textures[FLOOR])
		return (output_error(MSG_PORTAL_FLOOR));
	else if (map->portals && map->fc_textures[CEILLING])
		return (output_error(MSG_PORTAL_CEILLING));
	return (0);
}
