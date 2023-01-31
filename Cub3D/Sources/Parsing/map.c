/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 19:01:49 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_filename(char *file)
{
	int	index;

	if (ft_strncmp("maps/", file, 5))
		return (output_error(MSG_PREFIX));
	index = ft_strlen(file) - 4;
	if (ft_strncmp(".cub", &file[index], 5))
		return (output_error(MSG_SUFFIX));
	return (0);
}

static int	load_texture(t_map *map, t_side side)
{
	if (side == NO && map->textures[NO])
		return (output_error("Two different lines start with 'NO'"));
	else if (side == SO && map->textures[SO])
		return (output_error("Two different lines start with 'SO'"));
	else if (side == WE && map->textures[WE])
		return (output_error("Two different lines start with 'WE'"));
	else if (side == EA && map->textures[EA])
		return (output_error("Two different lines start with 'EA'"));
	map->textures[side] = ft_strdup(&map->line[3]);
	return (0);
}

static int	read_first_lines(t_map *map, int fd)
{
	map->line = get_next_line(fd);
	while (map->line)
	{
		printf("curr line : %s", map->line);
		if (!ft_strncmp("NO ", map->line, 3) && load_texture(map, NO))
			return (1);
		if (!ft_strncmp("SO ", map->line, 3) && load_texture(map, SO))
			return (1);
		if (!ft_strncmp("WE ", map->line, 3) && load_texture(map, WE))
			return (1);
		if (!ft_strncmp("EA ", map->line, 3) && load_texture(map, EA))
			return (1);
		if (!ft_strncmp("F ", map->line, 2) && transform_color(map, FLOOR))
			return (1);
		if (!ft_strncmp("C ", map->line, 2) && transform_color(map, CEILLING))
			return (1);
		if (map->line[0] == '\n')
			;
		free(map->line);
		map->line = get_next_line(fd);
	}
	return (0);
}

static int	free_textures(t_map *map, int res)
{
	if (!res)
	{
		res = (map->fc_colors[FLOOR] == 0x1000000)
				+ (map->fc_colors[CEILLING] == 0x1000000)
				+ !map->textures[NO] + !map->textures[SO] + !map->textures[WE]
				+!map->textures[EA];
		if (res)
			output_error("Missing line in header of map");
	}
	if (res)
	{
		free(map->textures[NO]);
		free(map->textures[SO]);
		free(map->textures[WE]);
		free(map->textures[EA]);
	}
	return (res);
}

int	load_map(t_map *map, char *file)
{
	int	fd;
	int	res;

	if (check_filename(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_perror(file);
	map->line = 0;
	map->textures[NO] = 0;
	map->textures[SO] = 0;
	map->textures[WE] = 0;
	map->textures[EA] = 0;
	map->fc_colors[FLOOR] = 0x1000000;
	map->fc_colors[CEILLING] = 0x1000000;
	map->walls = 0;
	res = read_first_lines(map, fd);
	// if (!res)
	// 	res = read_map(map, fd);
	close(fd);
	free(map->line);
	map->line = 0;
	res = free_textures(map, res);
	return (res);
}
