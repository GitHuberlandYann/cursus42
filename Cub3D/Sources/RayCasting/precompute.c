/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:01:26 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/03 16:01:26 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_obj_line(t_line *oline, t_vert *pos, t_vert	*obj_pos)
{
	double	angle;

	angle = atan2(pos->y - obj_pos->y, obj_pos->x - pos->x);
	set_point(&oline->pt1,
		obj_pos->x - cos(angle) * 0.2 + cos(angle + M_PI_2) * 0.5,
		obj_pos->y + sin(angle) * 0.2 - sin(angle + M_PI_2) * 0.5,
		0);
	set_point(&oline->pt2,
		obj_pos->x - cos(angle) * 0.2 + cos(angle - M_PI_2) * 0.5,
		obj_pos->y + sin(angle) * 0.2 - sin(angle - M_PI_2) * 0.5,
		0);
}

void	precompute_obj_lines(t_vert *pos, t_obj *objs)
{
	t_vert	obj_pos;

	while (objs)
	{
		if (objs->type == FDF)
		{
			set_point(&obj_pos, objs->fdf->pos.x, objs->fdf->pos.y, 0);
			set_obj_line(&objs->oline, pos, &obj_pos);
		}
		else if (objs->type != WIN)
			set_obj_line(&objs->oline, pos, &objs->pos);
		objs = objs->next;
	}
}

void	precompute_floor_ceilling(t_player *player, t_img *(fc_textures[2]))
{
	if (!fc_textures[FLOOR])
		return ;
	fc_textures[FLOOR]->atplayer.x = (player->pos.x + 0.5)
		* fc_textures[FLOOR]->width;
	fc_textures[FLOOR]->atplayer.y = (player->pos.y + 0.5)
		* fc_textures[FLOOR]->height;
}
