/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/03 15:45:26 by marvin           ###   ########.fr       */
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

static int	check_header(t_map *map, int res)
{
	if (!res)
	{
		res = (map->fc_colors[FLOOR] == 0x1000000)
				+ (map->fc_colors[CEILLING] == 0x1000000)
				+ !map->textures[NO] + !map->textures[SO] + !map->textures[WE]
				+!map->textures[EA];
		if (res)
		{
			output_error("Missing line in header of map");
			free(map->line);
		}
	}
	return (res);
}
static void	free_textures(t_map *map, int res)
{
	if (res)
	{
		free(map->textures[NO]);
		free(map->textures[SO]);
		free(map->textures[WE]);
		free(map->textures[EA]);
	}
}

int	free_return_lines(t_parsing *lines, t_map *map)
{
	t_parsing	*tmp;

	if (map->player_count == 1)
		free(map->player);
	while (lines)
	{
		free(lines->line);
		tmp = lines;
		lines = lines->next;
		free(tmp);
	}
	return (1);
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
	res = check_header(map, res);
	if (!res)
		res = read_map(map, fd);
	close(fd);
	free_textures(map, res);
	return (res);
}
