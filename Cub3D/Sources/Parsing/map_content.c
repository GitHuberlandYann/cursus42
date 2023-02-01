/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:25:46 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 14:01:50 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_parsing	*new_parsing_node(char *line, t_parsing *previous)
{
	t_parsing	*res;

	res = ft_malloc(sizeof(*res), "add_line");
	res->player_count = ft_strchr_cntset(line, "NSWE");
	res->line = line;
	res->size = ft_strlen(line);
	res->prev = previous;
	res->next = 0;
	res->last = 0;
	res->player_line = 0;
	return (res);
}

static int	add_line(t_parsing **lines, char *line)
{
	if (!line_from_map(line, 1))
		return (output_error(MSG_INVALIDCHAR));
	if (!*lines)
	{
		*lines = new_parsing_node(line, 0);
		(*lines)->last = *lines;
		if ((*lines)->player_count)
			(*lines)->player_line = *lines;
	}
	else
	{
		(*lines)->last->next = new_parsing_node(line, (*lines)->last);
		(*lines)->last = (*lines)->last->next;
		if ((*lines)->last->player_count)
			(*lines)->player_line = (*lines)->last;
	}
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
	return (0);
}

int	free_return_lines(t_parsing *lines)
{
	t_parsing	*tmp;

	while (lines)
	{
		free(lines->line);
		tmp = lines;
		lines = lines->next;
		free(tmp);
	}
	return (1);
}

int	read_map(t_map *map, int fd)
{
	t_parsing	*lines;

	lines = 0;
	map->player_count = 0;
	while (map->line)
	{
		printf("curr map line : %s", map->line);
		if (add_line(&lines, map->line))
			return (free_return_lines(lines));
		map->player_count += lines->last->player_count;
		if (map->player_count > 1)
		{
			free_return_lines(lines);
			return (output_error(MSG_TOOMANYPLAYERS));
		}
		map->line = get_next_line(fd);
	}
	if (error_check(map, lines))
		return (free_return_lines(lines));
	create_walls(map, lines);
	return (!lines);
}
