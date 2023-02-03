/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:54:21 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/03 17:46:18 by marvin           ###   ########.fr       */
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
		if (!ft_strchr(" 01D~_][NSWE\n", str[index]))
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
		free(map->line);
		map->line = get_next_line(fd);
	}
	return (0);
}