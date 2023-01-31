/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 15:57:58 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_filename(char *file)
{
	int	index;

	if (ft_strnstr("maps/", file, 5))
		return (output_error(MSG_PREFIX));
	index = ft_strlen(file) - 5;
	if (ft_strncmp(".cub", file, 5))
		return (output_error(MSG_SUFFIX));
}

static int	read_first_lines(t_map *map, int fd)
{
	char	*line;

	while (line)
	{
		if (!ft_strncmp("NO ", line, 3))
		else if (!ft_strncmp("SO ", line, 3))
		else if (!ft_strncmp("WE ", line, 3))
		else if (!ft_strncmp("EA ", line, 3))

		else if (!ft_strncmp("F ", line, 2))
		else if (!ft_strncmp("C ", line, 2))
		else if (line[0] == '\n')
		else
			break ;
		free(line);
	}
}

int	load_map(t_map *map, char *file)
{
	int	fd;

	if (check_filename(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_perror(file));
	map->north_texture = 0;
	map->south_texture = 0;
	map->west_texture = 0;
	map->east_texture = 0;
	map->floor_color = 0;
	map->ceilling_color = 0;
	map->walls = 0;
	if (read_first_lines(map, fd))
		return (1);
	if (read_map(map, fd))
		return (1);
	close(fd);
	return (0);
}
