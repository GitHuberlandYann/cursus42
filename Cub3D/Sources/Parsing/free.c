/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:00:28 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/03 16:00:28 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_more_map_content(t_map *map)
{
	void	*tmp;

	while (map->walls)
	{
		tmp = map->walls;
		map->walls = map->walls->next;
		free(tmp);
	}
	while (map->posts)
	{
		tmp = map->posts;
		map->posts = map->posts->next;
		free(tmp);
	}
	while (map->anims)
	{
		tmp = map->anims;
		free(map->anims->str);
		map->anims->str = 0;
		map->anims = map->anims->next;
		free(tmp);
		if (!map->anims->str)
			break ;
	}
}

static void	free_map_content(t_map *map)
{
	void	*tmp;

	while (map->objs)
	{
		if (map->objs->type == FDF)
		{
			while (map->objs->fdf->map.vert)
			{
				tmp = map->objs->fdf->map.vert;
				map->objs->fdf->map.vert = map->objs->fdf->map.vert->next;
				free(tmp);
			}
			while (map->objs->fdf->map.faces)
			{
				tmp = map->objs->fdf->map.faces;
				map->objs->fdf->map.faces = map->objs->fdf->map.faces->next;
				free(tmp);
			}
			free(map->objs->fdf);
		}
		tmp = map->objs;
		map->objs = map->objs->next;
		free(tmp);
	}
	free_more_map_content(map);
}

void	free_textures(t_map *map)
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
	free(map->obj_textures[POST]);
	free(map->obj_textures[CUST]);
	free(map->obj_textures[WIN]);
	while (map->portals)
	{
		tmp = map->portals;
		map->portals = map->portals->next;
		free(tmp);
	}
	free_map_content(map);
}

int	free_return_lines(t_parsing *lines, t_map *map, int free_player)
{
	t_parsing	*tmp;

	if (free_player)
	{
		free(map->player->obj);
		free(map->player);
		if (map->playerbis)
		{
			free(map->playerbis->obj);
			free(map->playerbis);
		}
	}
	while (lines)
	{
		free(lines->line);
		tmp = lines;
		lines = lines->next;
		free(tmp);
	}
	return (1);
}

int	free_return_line(char *line)
{
	free(line);
	return (1);
}
