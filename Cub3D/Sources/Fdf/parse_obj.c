/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:37:08 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 17:51:04 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_map_fdf(t_map *map, t_fdfmap *res)
{
	int		fd;
	char	*line;

	map->line[ft_strlen(map->line) - 1] = '\0';
	fd = open(&map->line[4], O_RDONLY);
	if (fd == -1)
		return (output_error(MSG_FDFDF));
	line = get_next_line(fd);
	while (line)
	{
		ft_add_line(res, line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!res->faces)
		return (output_error(MSG_FDFEMPTY));
	return (0);
}

t_vertice	*ft_get_node(t_vertice *vert, int index)
{
	int			count;
	t_vertice	*res;

	res = vert;
	count = 1;
	while (count < index && res->next)
	{
		res = res->next;
		++count;
	}
	if (count < index)
		;//problemo in this case todo
	return (res);
}

int	load_map_fdf(t_map *map)
{
	t_fdf	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->map.faces = 0;
	res->map.faces_last = 0;
	res->map.vert = 0;
	res->map.vert_last = 0;
	res->next = 0;
	res->last = 0;
	if (!map->fdf)
	{
		map->fdf = res;
		map->fdf->last = map->fdf;
	}
	else
	{
		map->fdf->last->next = res;
		map->fdf->last = map->fdf->last->next;
	}
	return (read_map_fdf(map, &res->map));
}
