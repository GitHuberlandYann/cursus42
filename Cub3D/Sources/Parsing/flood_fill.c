/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:44:28 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/04 14:23:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(t_parsing *current, int index)
{
	int	res;

	if (!current || index >= current->size)
		return (1);
	if ((!index && current->line[index] != '1')
		|| current->line[index] == ' ' || current->line[index] == '\n')
		return (1);
	if (ft_strchr("1XdP", current->line[index]))
		return (0);
	if (current->line[index] != 'D')
		current->line[index] = 'X';
	else
		current->line[index] = 'd';
	res = flood_fill(current, index + 1);
	if (!res)
		res = flood_fill(current, index - 1);
	if (!res)
		res = flood_fill(current->prev, index);
	if (!res)
		res = flood_fill(current->next, index);
	return (res);
}
