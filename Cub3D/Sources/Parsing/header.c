/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:54:21 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 16:34:03 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture(t_map *map, t_side side)
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

static int	load_texture_fc(t_map *map, t_ground side)
{
	if (side == FLOOR && map->fc_textures[FLOOR])
		return (output_error(MSG_TWOFT));
	if (side == CEILLING && map->fc_textures[CEILLING])
		return (output_error(MSG_TWOCT));
	map->fc_textures[side] = ft_strdup(&map->line[3]);
	map->fc_textures[side][ft_strlen(map->fc_textures[side]) - 1] = '\0';
	return (0);
}

static int	load_texture_ds(t_map *map, int side)
{
	if (side == 0 && map->ds_textures[side])
		return (output_error(MSG_TWODOORS));
	if (side == 1 && map->ds_textures[side])
		return (output_error(MSG_TWODOORSIDES));
	map->ds_textures[side] = ft_strdup(&map->line[2 + side]);
	map->ds_textures[side][ft_strlen(map->ds_textures[side]) - 1] = '\0';
	return (0);
}

int	line_from_map(char *str, int empty_allowed)
{
	int	index;
	int	res;

	index = 0;
	res = 0;
	while (str[index])
	{
		if (!ft_strchr(" 01ADPNSWE\n", str[index]))
			return (0);
		else if (empty_allowed)
			res = 1;
		else if (str[index] != '\n' && str[index] != ' ')
			res = 1;
		++index;
	}
	return (res);
}

int	read_first_lines(t_map *map, int fd)
{
	map->hasbarrel = 0;
	map->haspillar = 0;
	map->haspost = 0;
	map->hascustom = 0;
	map->haswindow = 0;
	map->line = get_next_line(fd);
	while (map->line && !line_from_map(map->line, 0))
	{
		// printf("curr line : %s", map->line);
		if (!ft_strncmp("NO ", map->line, 3) && load_texture(map, NO))
			return (free_return_line(map->line));
		if (!ft_strncmp("SO ", map->line, 3) && load_texture(map, SO))
			return (free_return_line(map->line));
		if (!ft_strncmp("WE ", map->line, 3) && load_texture(map, WE))
			return (free_return_line(map->line));
		if (!ft_strncmp("EA ", map->line, 3) && load_texture(map, EA))
			return (free_return_line(map->line));
		if (!ft_strncmp("F ", map->line, 2) && transform_color(map, FLOOR))
			return (free_return_line(map->line));
		if (!ft_strncmp("C ", map->line, 2) && transform_color(map, CEILLING))
			return (free_return_line(map->line));
		if (!ft_strncmp("LINK ", map->line, 5) && link_portals(map))
			return (free_return_line(map->line));
		if (!ft_strncmp("FT ", map->line, 3) && load_texture_fc(map, FLOOR))
			return (free_return_line(map->line));
		if (!ft_strncmp("CT ", map->line, 3) && load_texture_fc(map, CEILLING))
			return (free_return_line(map->line));
		if (!ft_strncmp("D ", map->line, 2) && load_texture_ds(map, 0))
			return (free_return_line(map->line));
		if (!ft_strncmp("DS ", map->line, 3) && load_texture_ds(map, 1))
			return (free_return_line(map->line));
		if (!ft_strncmp("B ", map->line, 2) && ++map->hasbarrel && add_obj(map, BARREL))
			return (free_return_line(map->line));
		if (!ft_strncmp("BT ", map->line, 3) && load_texture_obj(map, BARREL))
			return (free_return_line(map->line));
		if (!ft_strncmp("P ", map->line, 2) && ++map->haspillar && add_obj(map, PILLAR))
			return (free_return_line(map->line));
		if (!ft_strncmp("PT ", map->line, 3) && load_texture_obj(map, PILLAR))
			return (free_return_line(map->line));
		if (!ft_strncmp("POST ", map->line, 5) && ++map->haspost && add_post(map))
			return (free_return_line(map->line));
		if (!ft_strncmp("POSTT ", map->line, 6) && load_texture_obj(map, POST))
			return (free_return_line(map->line));
		if (!ft_strncmp("CUST ", map->line, 5) && add_custom(map))
			return (free_return_line(map->line));
		if (!ft_strncmp("CUSTT ", map->line, 6) && load_texture_obj(map, CUST))
			return (free_return_line(map->line));
		if (!ft_strncmp("WIND ", map->line, 5) && ++map->haswindow && add_window(map))
			return (free_return_line(map->line));
		if (!ft_strncmp("WINDT ", map->line, 6) && load_texture_obj(map, WIN))
			return (free_return_line(map->line));
		if (!ft_strncmp("FDF ", map->line, 4) && load_map_fdf(map))
			return (free_return_line(map->line));
		if (!ft_strncmp("FRAME ", map->line, 6))
			load_frame(map);
		free(map->line);
		map->line = get_next_line(fd);
	}
	if ((map->hasbarrel && !map->obj_textures[BARREL]) || (map->haspillar && !map->obj_textures[PILLAR])
		|| (map->haspost && !map->obj_textures[POST]) || (map->hascustom && !map->obj_textures[CUST])
		|| (map->haswindow && !map->obj_textures[WIN]))
	{
		output_error(MSG_OBJTEXTURE);
		return (free_return_line(map->line));
	}
	return (0);
}
