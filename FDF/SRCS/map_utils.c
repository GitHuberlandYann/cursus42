/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:10:26 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/16 14:25:30 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertice	*fill_v(t_map *map, t_vertice *src)
{
	int			index;
	t_vertice	*res;

	res = malloc(sizeof(*res) * map->height * map->width);
	if (!res)
		ft_perror(__func__);
	index = 0;
	while (src)
	{
		res[index] = *src;
		src = src->next;
		++index;
	}
	return (res);
}

static void	ft_faceadd_back(t_map *map, t_face *new)
{
	if (!map->faces_last)
	{
		map->faces_last = new;
		map->faces = new;
	}
	else
	{
		map->faces_last->next = new;
		map->faces_last = new;
	}
}

void	ft_faces_init(t_map *map)
{
	int			y;
	int			x;
	t_face		*f;
	t_vertice	*v;

	v = fill_v(map, map->vert);
	y = -1;
	while (++y < map->height - 1)
	{
		x = -1;
		while (++x < map->width - 1)
		{
			f = malloc(sizeof(*f));
			if (!f)
				ft_perror(__func__);
			f->face[0] = &v[y * map->width + x];
			f->face[3] = &v[y * map->width + x + 1];
			f->face[1] = &v[(y + 1) * map->width + x];
			f->face[2] = &v[(y + 1) * map->width + x + 1];
			f->next = 0;
			ft_faceadd_back(map, f);
		}
	}
}
