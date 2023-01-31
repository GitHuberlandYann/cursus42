/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:54:21 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/31 20:19:21 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	line_from_map(char	*str)
{
	int	index;
	int	res;

	index = 0;
	res = 0;
	while (str[index])
	{
		if (!ft_strchr(" 01NSWE\n", str[index]))
			return (0);
		else if (str[index] != '\n' && str[index] != ' ')
			res = 1;
		++index;
	}
	return (res);
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

int	read_first_lines(t_map *map, int fd)
{
	map->line = get_next_line(fd);
	while (map->line && !line_from_map(map->line))
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
		free(map->line);
		map->line = get_next_line(fd);
	}
	return (0);
}