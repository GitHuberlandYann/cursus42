/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:25:46 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/07 19:32:25 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_parsing	*new_parsing_node(char *line, t_parsing *previous,
	int line_number)
{
	t_parsing	*res;

	res = ft_malloc(sizeof(*res), "add_line");
	res->player_count = ft_strchr_cntset(line, "NSWE");
	res->line = line;
	res->line_number = line_number;
	res->size = ft_strlen(line);
	res->prev = previous;
	res->next = 0;
	res->last = 0;
	res->player_line = 0;
	return (res);
}

static int	add_line(t_parsing **lines, char *line, int line_number)
{
	if (!*lines)
	{
		*lines = new_parsing_node(line, 0, line_number);
		(*lines)->last = *lines;
	}
	else
	{
		(*lines)->last->next = new_parsing_node(line, (*lines)->last,
				line_number);
		(*lines)->last = (*lines)->last->next;
	}
	if ((*lines)->last->player_count)
	{
		if (!(*lines)->player_line)
		{
			(*lines)->player_line = (*lines)->last;
			if ((*lines)->last->player_count == 2)
				(*lines)->playerbis_line = (*lines)->last;
		}
		else
			(*lines)->playerbis_line = (*lines)->last;
	}
	if (!line_from_map(line, 1))
		return (output_error(MSG_INVALIDCHAR));
	return (0);
}

static int	error_check(t_map *map, t_parsing *lines)
{
	int	index;

	if (!map->player_count)
		return (output_error(MSG_NOPLAYER));
	index = 0;
	while (lines->player_line->line[index]
		&& !ft_strchr("NSWE", lines->player_line->line[index]))
		++index;
	if (flood_fill(lines->player_line, index))
		return (output_error(MSG_UNCLOSED));
	if (map->player_count == 2)
	{
		index = 0;
		while (lines->playerbis_line->line[index])
			++index;
		--index;
		while (index > 0
			&& !ft_strchr("NSWE", lines->playerbis_line->line[index]))
			--index;
		if (ft_strchr("NSWE", lines->playerbis_line->line[index])
			&& flood_fill(lines->playerbis_line, index))
			return (output_error(MSG_UNCLOSEDBIS));
	}
	return (0);
}

		// printf("curr map line : %s", map->line);
int	read_map(t_map *map, int fd)
{
	t_parsing	*lines;
	int			line_number;

	lines = 0;
	line_number = 0;
	map->player_count = 0;
	while (map->line && ++line_number)
	{
		if (add_line(&lines, map->line, line_number - 1))
			return (free_return_lines(lines, map, 0));
		map->player_count += lines->last->player_count;
		if (map->player_count > 2)
		{
			free_return_lines(lines, map, 0);
			return (output_error(MSG_TOOMANYPLAYERS));
		}
		map->line = get_next_line(fd);
	}
	init_players(map, lines);
	if (error_check(map, lines))
		return (free_return_lines(lines, map, map->player_count > 0));
	create_walls(map, lines, lines);
	return (!map->walls);
}
