/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:00:01 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/03 16:00:01 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// printf("dir before %lf with angle %lf -> ", dir, angle);
static void	set_angle_index(t_player *other, double dir)
{
	if (dir < -M_PI)
		dir += 2 * M_PI;
	else if (dir > M_PI)
		dir -= 2 * M_PI;
	if (dir >= -M_PI_8 && dir < M_PI_8)
		other->obj->angle_index = 4;
	else if (dir >= M_PI_8 && dir < 3 * M_PI_8)
		other->obj->angle_index = 3;
	else if (dir >= 3 * M_PI_8 && dir < 5 * M_PI_8)
		other->obj->angle_index = 2;
	else if (dir >= 5 * M_PI_8 && dir < 7 * M_PI_8)
		other->obj->angle_index = 1;
	else if (dir >= 7 * M_PI_8 || dir < -7 * M_PI_8)
		other->obj->angle_index = 0;
	else if (dir >= -3 * M_PI_8 && dir < -M_PI_8)
		other->obj->angle_index = 5;
	else if (dir >= -5 * M_PI_8 && dir < -3 * M_PI_8)
		other->obj->angle_index = 6;
	else if (dir >= -7 * M_PI_8 && dir < -5 * M_PI_8)
		other->obj->angle_index = 7;
}

void	precompute_other_player(t_player *player, t_player *other)
{
	double	angle;
	double	dir;

	angle = atan2(player->pos.y - other->pos.y, other->pos.x - player->pos.x);
	set_point(&other->obj->oline.pt1,
		other->pos.x - cos(angle) * 0.2 + cos(angle + M_PI_2) * 0.5,
		other->pos.y + sin(angle) * 0.2 - sin(angle + M_PI_2) * 0.5, 0);
	set_point(&other->obj->oline.pt2,
		other->pos.x - cos(angle) * 0.2 + cos(angle - M_PI_2) * 0.5,
		other->pos.y + sin(angle) * 0.2 - sin(angle - M_PI_2) * 0.5, 0);
	if (angle < -M_PI)
		angle += 2 * M_PI;
	dir = ft_fmod(other->direction, 2 * M_PI);
	if (dir < -M_PI)
		dir += 2 * M_PI;
	else if (dir > M_PI)
		dir -= 2 * M_PI;
	dir -= angle;
	set_angle_index(other, dir);
	other->obj->state = other->state;
}
	// printf("index %d when dir %lf\n", other->obj->angle_index, dir);
