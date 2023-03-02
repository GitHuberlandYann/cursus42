/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:49:03 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 10:49:03 by yhuberla         ###   ########.fr       */
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
			return (output_error(MSG_POSTDECI255));
	}
	if (!len)
		return (output_error(MSG_POSTDECIUNSET));
	*number += deci / pow(10, len);
	return (0);
}

static double	ft_atod(t_map *map, int *index, int sindex)
{
	double	number;

	if (map->line[*index] == '0' && !ft_strchr(" .,\n", map->line[*index + 1]))
		return (output_error(MSG_POSTZEROPAD) - 1);
	number = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		number = 10 * number + map->line[*index] - '0';
		++(*index);
		if (number > 255)
			return (output_error(MSG_POST255) - 1);
	}
	if (sindex == *index)
		return (output_error(MSG_POSTUNSET) - 1);
	if (map->line[*index] != '.')
		return (output_error(MSG_POSTDOT) - 1);
	if (ft_atod_decimals(map, index, &number))
		return (0);
	if (map->line[*index] == ',' && map->line[*index + 1] >= '0'
		&& map->line[*index + 1] <= '9')
		++(*index);
	if (!number)
		return (output_error(MSG_POSTZERO) - 1);
	return (number);
}

static void	add_new_post(t_map *map, double x, double y, double radius)
{
	t_post	*new;

	new = ft_malloc(sizeof(*new), "add_post");
	set_point(&new->center, x, y, 0);
	new->radius = radius;
	set_point(&new->squared, x * x, y * y, radius * radius);
	new->next = 0;
	new->last = 0;
	if (!map->posts)
		map->posts = new;
	else
		map->posts->last->next = new;
	map->posts->last = new;
}

int	add_post(t_map *map)
{
	double	x;
	double	y;
	double	radius;
	int		index;

	index = 5;
	x = ft_atod(map, &index, index);
	if (!x)
		return (1);
	y = ft_atod(map, &index, index);
	if (!y)
		return (1);
	radius = ft_atod(map, &index, index);
	if (!radius)
		return (1);
	if (!only_spaces(map, index))
		return (output_error(MSG_POSTEND));
	add_new_post(map, x, y, radius);
	return (0);
}
