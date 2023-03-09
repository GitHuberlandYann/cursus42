/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:45:58 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/09 10:45:58 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture_w(t_map *map, t_side side)
{
	if (side == NO && map->textures[NO])
		return (output_error(MSG_TWONO));
	else if (side == SO && map->textures[SO])
		return (output_error(MSG_TWOSO));
	else if (side == WE && map->textures[WE])
		return (output_error(MSG_TWOWE));
	else if (side == EA && map->textures[EA])
		return (output_error(MSG_TWOEA));
	map->textures[side] = ft_strdup(&map->line[3]);
	map->textures[side][ft_strlen(map->textures[side]) - 1] = '\0';
	return (0);
}

int	load_texture_ds(t_map *map, int side)
{
	if (side == 0 && map->ds_textures[side])
		return (output_error(MSG_TWODOORS));
	if (side == 1 && map->ds_textures[side])
		return (output_error(MSG_TWODOORSIDES));
	map->ds_textures[side] = ft_strdup(&map->line[2 + side]);
	map->ds_textures[side][ft_strlen(map->ds_textures[side]) - 1] = '\0';
	return (0);
}

int	load_texture_fc(t_map *map, t_ground side)
{
	if (side == FLOOR && map->fc_textures[FLOOR])
		return (output_error(MSG_TWOFT));
	if (side == CEILLING && map->fc_textures[CEILLING])
		return (output_error(MSG_TWOCT));
	map->fc_textures[side] = ft_strdup(&map->line[3]);
	map->fc_textures[side][ft_strlen(map->fc_textures[side]) - 1] = '\0';
	return (0);
}

int	load_texture_obj(t_map *map, t_objtype type)
{
	if (type == BARREL && map->obj_textures[type])
		return (output_error(MSG_TWOBARRELS));
	if (type == PILLAR && map->obj_textures[type])
		return (output_error(MSG_TWOPILLARS));
	if (type == POST && map->obj_textures[type])
		return (output_error(MSG_TWOPOSTS));
	if (type == CUST && map->obj_textures[type])
		return (output_error(MSG_TWOCUSTS));
	if (type == WIN && map->obj_textures[type])
		return (output_error(MSG_TWOWINDS));
	map->obj_textures[type] = ft_strdup(&map->line[3 + 3 * (type >= POST)]);
	map->obj_textures[type][ft_strlen(map->obj_textures[type]) - 1] = '\0';
	return (0);
}
