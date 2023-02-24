/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:23:41 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 10:49:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	console_map_content(t_map *map)
{
	int		cnt;
	t_wall	*w;
	t_post	*p;
	t_obj	*o;

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
	p = map->posts;
	while (p)
	{
		printf("radius %lf, [%lf, %lf], squared x %lf y %lf r %lf\n", p->radius, p->center.x, p->center.y, p->squared.x, p->squared.y, p->squared.z);
		p = p->next;
	}
	o = map->objs;
	while (o)
	{
		printf("obj type %d at [%lf,%lf], size %d [%lf, %lf] - [%lf, %lf]\n", o->type, o->pos.x, o->pos.y, o->size, o->oline.pt1.x, o->oline.pt1.y, o->oline.pt2.x, o->oline.pt2.y);
		o = o->next;
	}
}
