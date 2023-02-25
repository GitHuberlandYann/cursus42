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
	int		index;
	char	*line;

	map->line[ft_strlen(map->line) - 1] = '\0';
	index = load_pos(map->line, map->objs->last->fdf);
	if (!index)
		return (1);
	fd = open(&map->line[index], O_RDONLY);
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
		(void)count;//problemo in this case todo
	return (res);
}

int	load_map_fdf(t_map *map)
{
	t_obj	*res;

	res = ft_malloc(sizeof(*res), __func__);
	res->type = FDF;
	res->fdf = ft_malloc(sizeof(*res->fdf), __func__);
	res->fdf->size = 100;
	res->fdf->offset_x = WIN_FDFX_2;
	res->fdf->offset_y = WIN_FDFY;
	res->fdf->map.faces = 0;
	res->fdf->map.faces_last = 0;
	res->fdf->map.vert = 0;
	res->fdf->map.vert_last = 0;
	res->fdf->next = 0;
	res->fdf->last = 0;
	res->next = 0;
	res->last = 0;
	if (!map->objs)
	{
		map->objs = res;
		map->objs->last = map->objs;
	}
	else
	{
		map->objs->last->next = res;
		map->objs->last = map->objs->last->next;
	}
	return (read_map_fdf(map, &res->fdf->map));
}
