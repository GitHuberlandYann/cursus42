/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:23:41 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/21 18:09:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	console_map_content(t_map *map)
{
	int		cnt;
	t_wall	*w;

	printf("\n\n\t\t~map content~\n");
	printf("\nline     : |%s|\n", map->line);
	printf("north    : |%s|\n", map->textures[NO]);
	printf("south    : |%s|\n", map->textures[SO]);
	printf("west     : |%s|\n", map->textures[WE]);
	printf("east     : |%s|\n", map->textures[EA]);
	printf("floor    : %x\n", map->fc_colors[FLOOR]);
	printf("ceilling : %x\n", map->fc_colors[CEILLING]);
	printf("floor text    : |%s|\n", map->fc_textures[FLOOR]);
	printf("ceilling text : |%s|\n", map->fc_textures[CEILLING]);
	printf("door    : |%s|\n", map->ds_textures[FLOOR]);
	printf("door_side : |%s|\n", map->ds_textures[CEILLING]);
	printf("texture barrel : |%s|\n", map->obj_textures[BARREL]);
	printf("texture pillar : |%s|\n", map->obj_textures[PILLAR]);
	printf("texture post : |%s|\n", map->obj_textures[POST]);
	cnt = 0;
	w = map->walls;
	while (w)
	{
		printf("%d: size %d, [%lf, %lf] - [%lf, %lf]\n", cnt, w->size, w->wline.pt1.x, w->wline.pt1.y, w->wline.pt2.x, w->wline.pt2.y);
		w = w->next;
		++cnt;
	}
	printf("wall count : %d\n", cnt);
}
