/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:49:15 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 10:49:15 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atod_decimals(t_map *map, int *index, double *number)
{
	int		len;
	int		deci;

	++(*index);
	deci = 0;
	len = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		deci = 10 * deci + map->line[*index] - '0';
		++len;
		++(*index);
		if (deci > 255)
			return (output_error(MSG_WINDDECI255));
	}
	if (!len)
		return (output_error(MSG_WINDDECIUNSET));
	*number += deci / pow(10, len);
	return (0);
}

static double	ft_atod(t_map *map, int *index, int sindex)
{
	double	number;

	if (map->line[*index] == '0' && !ft_strchr(" .,\n", map->line[*index + 1]))
		return (output_error(MSG_WINDZEROPAD) - 1);
	number = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		number = 10 * number + map->line[*index] - '0';
		++(*index);
		if (number > 255)
			return (output_error(MSG_WIND255) - 1);
	}
	if (sindex == *index)
		return (output_error(MSG_WINDUNSET) - 1);
	if (map->line[*index] != '.')
		return (output_error(MSG_WINDDOT) - 1);
	if (ft_atod_decimals(map, index, &number))
		return (0);
	if (map->line[*index] == ',' && map->line[*index + 1] >= '0'
		&& map->line[*index + 1] <= '9')
		++(*index);
	if (!number)
		return (output_error(MSG_WINDZERO) - 1);
	return (number);
}

static void	add_new_window(t_map *map, t_line line)
{
	t_obj	*new;
	double	size;

	size = (int)get_dist(line.pt1, line.pt2);
	if (!size)
		return ;
	new = ft_malloc(sizeof(*new), "add_window");
	new->type = WIN;
	line.pt1.z = 0;
	line.pt2.z = 0;
	new->oline = line;
	new->size = size;
	new->next = 0;
	new->last = 0;
	if (!map->objs)
		map->objs = new;
	else
		map->objs->last->next = new;
	map->objs->last = new;
}

int	add_window(t_map *map)
{
	t_line	wline;
	int		index;

	index = 5;
	wline.pt1.x = ft_atod(map, &index, index);
	if (!wline.pt1.x)
		return (1);
	wline.pt1.y = ft_atod(map, &index, index);
	if (!wline.pt1.y)
		return (1);
	wline.pt2.x = ft_atod(map, &index, index);
	if (!wline.pt2.x)
		return (1);
	wline.pt2.y = ft_atod(map, &index, index);
	if (!wline.pt2.y)
		return (1);
	if (!only_spaces(map, index))
		return (output_error(MSG_WINDEND));
	add_new_window(map, wline);
	return (0);
}
