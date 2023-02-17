/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:54:19 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/17 14:48:52 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atoi_obj(t_map *map, int *index, int sindex)
{
	int	number;

	if (map->line[*index] == '0' && !ft_strchr(" ,\n", map->line[*index + 1]))
		return (output_error(MSG_OBJZEROPAD) - 1);
	number = 0;
	while (map->line[*index] >= '0' && map->line[*index] <= '9')
	{
		number = 10 * number + map->line[*index] - '0';
		++(*index);
		if (number > 255)
			return (output_error(MSG_OBJ255) - 1);
	}
	if (sindex == *index)
		return (output_error(MSG_OBJUNSET) - 1);
	if (map->line[*index] == ',' && map->line[*index + 1] >= '0'
		&& map->line[*index + 1] <= '9')
		++(*index);
	if (!number)
		return (output_error(MSG_OBJZERO) - 1);
	return (number);
}

static t_obj	*new_obj(t_objtype type, int x, int y)
{
	t_obj	*res;

	res = ft_malloc(sizeof(*res), "add_obj");
	res->type = type;
	set_point(&res->pos, x, y, 0);
	res->next = 0;
	res->last = 0;
	return (res);
}

int	load_texture_obj(t_map *map, t_objtype type)
{
	if (type == BARREL && map->obj_textures[type])
		return (output_error(MSG_TWOBARRELS));
	if (type == PILLAR && map->obj_textures[type])
		return (output_error(MSG_TWOPILLARS));
	map->obj_textures[type] = ft_strdup(&map->line[3]);
	map->obj_textures[type][ft_strlen(map->obj_textures[type]) - 1] = '\0';
	return (0);
}

int	add_obj(t_map *map, t_objtype type)
{
	int	x;
	int	y;
	int	index;

	index = 2;
	x = ft_atoi_obj(map, &index, index);
	if (!x)
		return (1);
	y = ft_atoi_obj(map, &index, index);
	if (!y)
		return (1);
	if (!only_spaces(map, index))
		return (output_error(MSG_OBJEND));
	if (!map->objs)
	{
		map->objs = new_obj(type, x, y);
		map->objs->last = map->objs;
	}
	else
	{
		map->objs->last->next = new_obj(type, x, y);
		map->objs->last = map->objs->last->next;
	}
	return (0);
}
