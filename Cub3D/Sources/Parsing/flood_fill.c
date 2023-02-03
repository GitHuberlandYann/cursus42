/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:44:28 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/03 15:48:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	border_portal(t_parsing *current, int index, int *portals)
{
	--(*portals);
	return ((ft_strchr("~_", current->line[index]) && (!index || index >= current->size
		|| ft_strchr("0 []", current->line[index - 1])
		|| ft_strchr("0 []", current->line[index + 1])))
		|| (ft_strchr("[]", current->line[index]) && (!current->prev
		|| index >= current->prev->size
		|| ft_strchr("0 ~_", current->prev->line[index])
		|| !current->next || index >= current->next->size
		|| ft_strchr("0 ~_", current->next->line[index]))));
}

int	flood_fill(t_parsing *current, int index, int *portals)
{
	int	res;

	if (!current || index >= current->size)
		return (1);
	if (ft_strchr("~_][", current->line[index]))
		return (border_portal(current, index, portals));
	if ((!index && current->line[index] != '1')
		|| current->line[index] == ' ' || current->line[index] == '\n')
		return (1);
	if (current->line[index] == '1' || current->line[index] == 'X')
		return (0);
	current->line[index] = 'X';
	res = flood_fill(current, index + 1, portals);
	if (!res)
		res = flood_fill(current, index - 1, portals);
	if (!res)
		res = flood_fill(current->prev, index, portals);
	if (!res)
		res = flood_fill(current->next, index, portals);
	return (res);
}
