/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:42:14 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/17 14:32:00 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atoi_col(t_map *map, int *index, int sindex, t_ground ground)
{
	int	number;

	if (map->line[*index] == '0' && !ft_strchr(" ,\n", map->line[*index + 1]))
		return (output_error(MSG_RGBZEROPAD));
	number = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		number = 10 * number + map->line[*index] - '0';
		++(*index);
		if (number > 255)
			return (output_error(MSG_RGB255));
	}
	if (sindex == *index)
		return (output_error(MSG_RGBUNSET));
	if (map->line[*index] == ',' && map->line[*index + 1] >= '0'
		&& map->line[*index + 1] <= '9')
		++(*index);
	map->fc_colors[ground] = map->fc_colors[ground] * 0x100 + number;
	return (0);
}

int	only_spaces(t_map *map, int index)
{
	while (map->line[index] == ' ')
		++index;
	return (!(map->line[index] && map->line[index] != '\n'));
}

int	transform_color(t_map *map, t_ground ground)
{
	int	index;

	map->fc_colors[ground] = 0;
	index = 2;
	if (ft_atoi_col(map, &index, index, ground))
		return (1);
	if (ft_atoi_col(map, &index, index, ground))
		return (1);
	if (ft_atoi_col(map, &index, index, ground))
		return (1);
	if (!only_spaces(map, index))
		return (output_error(MSG_FCEND));
	return (0);
}
