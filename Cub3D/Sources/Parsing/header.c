/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:54:21 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/12 14:10:30 by marvin           ###   ########.fr       */
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
	if (side == 1 && map->fc_textures[side])
		return (output_error(MSG_TWODOORSIDES));
	map->ds_textures[side] = ft_strdup(&map->line[2 + side]);
	map->ds_textures[side][ft_strlen(map->ds_textures[side]) - 1] = '\0';
	return (0);
}

static int	free_return_line(char *line)
{
	free(line);
	return (1);
}

int	line_from_map(char *str, int empty_allowed)
{
	int	index;
	int	res;

	index = 0;
	res = 0;
	while (str[index])
	{
		if (!ft_strchr(" 01DPNSWE\n", str[index]))
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
		free(map->line);
		map->line = get_next_line(fd);
	}
	return (0);
}
