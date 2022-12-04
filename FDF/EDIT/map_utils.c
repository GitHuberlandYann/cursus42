/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:51:11 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 13:51:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

static void	ft_vertadd_back(t_map *map, t_vertice *new)
{
	if (!map->vert_last)
	{
		map->vert_last = new;
		map->vert = new;
	}
	else
	{
		map->vert_last->next = new;
		map->vert_last = new;
	}
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

void	ft_vert_init(t_map *map)
{
	int			y;
	int			x;
	t_vertice	*v;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			v = malloc(sizeof(*v));
			if (!v)
				ft_perror(__func__);
			v->x = x;
			v->y = y;
			v->z = 0;
			v->next = 0;
			ft_vertadd_back(map, v);
			++x;
		}
		++y;
	}
}

void	ft_faces_init(t_map *map)
{
	int		y;
	int		x;
	t_face	*f;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			f = malloc(sizeof(*f));
			if (!f)
				ft_perror(__func__);
			f->face[0] = ft_get_node(map->vert, y * map->width + x + 1);
			f->face[3] = ft_get_node(map->vert, y * map->width + x + 2);
			f->face[1] = ft_get_node(map->vert, (y + 1) * map->width + x + 1);
			f->face[2] = ft_get_node(map->vert, (y + 1) * map->width + x + 2);
			f->next = 0;
			ft_faceadd_back(map, f);
			++x;
		}
		++y;
	}
}
