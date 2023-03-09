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
		map->portals->last->next = ft_malloc(sizeof(*map->portals),
				"add_portal");
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
	if (map->line[*index] == ':' && map->line[*index + 1] >= '0'
		&& map->line[*index + 1] <= '9')
		++(*index);
	return (0);
}

	// printf("portal %d linked with %d\n", num, link);
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
