/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:51 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/27 13:14:50 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_map_init(void)
{
	t_map	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_perror(__func__);
	res->vert = 0;
	res->faces = 0;
	res->vert_last = 0;
	res->faces_last = 0;
	res->width = 0;
	res->height = 0;
	res->max = 0;
	return (res);
}

static void	ft_vertnew(t_map *map, char *z, int x)
{
	t_vertice	*vert;

	vert = malloc(sizeof(*vert));
	if (!vert)
		ft_perror(__func__);
	vert->x = x;
	vert->y = map->height;
	vert->z = -ft_atoi(z);
	if (fabs(vert->z) > map->max)
		map->max = fabs(vert->z);
	vert->next = 0;
	if (!map->vert_last)
	{
		map->vert_last = vert;
		map->vert = vert;
	}
	else
	{
		map->vert_last->next = vert;
		map->vert_last = vert;
	}
}

static void	ft_add_line(t_map *map, char *line)
{
	int		x;
	char	**arr;

	arr = ft_split(line, ' ');
	if (!arr)
		ft_perror("ft_split");
	free(line);
	x = 0;
	while (arr[x] && arr[x][0] != '\n')
	{
		ft_vertnew(map, arr[x], x);
		++x;
	}
	ft_free_arr(arr);
	if (!map->width)
		map->width = x;
	else if (x != map->width)
		ft_perror("invalid map");
}

t_map	*get_map(char	*path)
{
	int		fd;
	t_map	*res;
	char	*line;

	res = ft_map_init();
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_perror(path);
	line = get_next_line(fd);
	while (line && line[0] && line[0] != '\n')
	{
		ft_add_line(res, line);
		line = get_next_line(fd);
		++res->height;
	}
	close(fd);
	res->ratio = (double)res->height / 10.0 + (res->height < 10);
	ft_faces_init(res);
	if (res->width < 2 || res->height < 2)
		ft_perror("invalid map");
	return (res);
}
