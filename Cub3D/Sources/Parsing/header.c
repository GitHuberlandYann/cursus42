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

static int	end_strcmp_line(t_map *map)
{
	if (!ft_strncmp("WIND ", map->line, 5) && ++map->haswindow
		&& add_window(map))
		return (free_return_line(map->line));
	if (!ft_strncmp("WINDT ", map->line, 6) && load_texture_obj(map, WIN))
		return (free_return_line(map->line));
	if (!ft_strncmp("FDF ", map->line, 4) && load_map_fdf(map))
		return (free_return_line(map->line));
	if (!ft_strncmp("FRAME ", map->line, 6))
		load_frame(map);
	return (0);
}

static int	more_strcmp_line(t_map *map)
{
	if (!ft_strncmp("B ", map->line, 2) && ++map->hasbarrel
		&& add_obj(map, BARREL))
		return (free_return_line(map->line));
	if (!ft_strncmp("BT ", map->line, 3) && load_texture_obj(map, BARREL))
		return (free_return_line(map->line));
	if (!ft_strncmp("P ", map->line, 2) && ++map->haspillar
		&& add_obj(map, PILLAR))
		return (free_return_line(map->line));
	if (!ft_strncmp("PT ", map->line, 3) && load_texture_obj(map, PILLAR))
		return (free_return_line(map->line));
	if (!ft_strncmp("POST ", map->line, 5) && ++map->haspost && add_post(map))
		return (free_return_line(map->line));
	if (!ft_strncmp("POSTT ", map->line, 6) && load_texture_obj(map, POST))
		return (free_return_line(map->line));
	if (!ft_strncmp("CUST ", map->line, 5) && ++map->hascustom
		&& add_custom(map))
		return (free_return_line(map->line));
	if (!ft_strncmp("CUSTT ", map->line, 6) && load_texture_obj(map, CUST))
		return (free_return_line(map->line));
	return (end_strcmp_line(map));
}

static int	strcmp_line(t_map *map)
{
	if (!ft_strncmp("NO ", map->line, 3) && load_texture_w(map, NO))
		return (free_return_line(map->line));
	if (!ft_strncmp("SO ", map->line, 3) && load_texture_w(map, SO))
		return (free_return_line(map->line));
	if (!ft_strncmp("WE ", map->line, 3) && load_texture_w(map, WE))
		return (free_return_line(map->line));
	if (!ft_strncmp("EA ", map->line, 3) && load_texture_w(map, EA))
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
	return (more_strcmp_line(map));
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

		// printf("curr line : %s", map->line);
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
		trim_spaces(map->line, 0, 0, ft_strlen(map->line));
		if (strcmp_line(map))
			return (1);
		free(map->line);
		map->line = get_next_line(fd);
	}
	if ((map->hasbarrel && !map->obj_textures[BARREL])
		|| (map->haspillar && !map->obj_textures[PILLAR])
		|| (map->haspost && !map->obj_textures[POST])
		|| (map->hascustom && !map->obj_textures[CUST])
		|| (map->haswindow && !map->obj_textures[WIN]))
	{
		output_error(MSG_OBJTEXTURE);
		return (free_return_line(map->line));
	}
	return (0);
}
