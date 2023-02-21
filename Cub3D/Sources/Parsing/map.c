/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/21 17:52:33 by marvin           ###   ########.fr       */
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
		res = ((map->fc_colors[FLOOR] == 0x1000000) && !map->fc_textures[FLOOR])
			+ ((map->fc_colors[CEILLING] == 0x1000000)
				&& !map->fc_textures[CEILLING])
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

static void	free_textures(t_map *map)
{
	void	*tmp;

	free(map->textures[NO]);
	free(map->textures[SO]);
	free(map->textures[WE]);
	free(map->textures[EA]);
	free(map->fc_textures[FLOOR]);
	free(map->fc_textures[CEILLING]);
	free(map->ds_textures[0]);
	free(map->ds_textures[1]);
	free(map->obj_textures[BARREL]);
	free(map->obj_textures[PILLAR]);
	while (map->portals)
	{
		tmp = map->portals;
		map->portals = map->portals->next;
		free(tmp);
	}
	while (map->objs)
	{
		tmp = map->objs;
		map->objs = map->objs->next;
		free(tmp);
	}
}

int	free_return_lines(t_parsing *lines, t_map *map, int free_player)
{
	t_parsing	*tmp;

	if (free_player)
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
	map->fc_textures[FLOOR] = 0;
	map->fc_textures[CEILLING] = 0;
	map->ds_textures[0] = 0;
	map->ds_textures[1] = 0;
	map->obj_textures[BARREL] = 0;
	map->obj_textures[PILLAR] = 0;
	map->obj_textures[POST] = 0;
	map->walls = 0;
	map->doors = 0;
	map->portals = 0;
	map->objs = 0;
	res = read_first_lines(map, fd);
	res = check_header(map, res);
	if (!res)
		res = read_map(map, fd);
	close(fd);
	if (res)
		free_textures(map);
	return (res);
}
