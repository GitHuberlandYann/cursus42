#include "cub3d.h"

void	precompute_floor_ceilling(t_player *player, t_img *(fc_textures[2]))
{
	if (!fc_textures[FLOOR])
		return ;
	fc_textures[FLOOR]->atplayer.x = (player->pos.x + 0.5) * fc_textures[FLOOR]->width;
	fc_textures[FLOOR]->atplayer.y = (player->pos.y + 0.5) * fc_textures[FLOOR]->height;
}

void	precompute_obj_lines(t_vert *pos, t_obj *objs)
{
	double	angle;

	while (objs)
	{
		if (objs->type == FDF)
		{
			angle = atan2(pos->y - objs->fdf->pos.y, objs->fdf->pos.x - pos->x);
			set_point(&objs->oline.pt1, objs->fdf->pos.x - cos(angle) * 0.2 + cos(angle + M_PI_2) * 0.5,
				objs->fdf->pos.y + sin(angle) * 0.2 - sin(angle + M_PI_2) * 0.5, 0);
			set_point(&objs->oline.pt2, objs->fdf->pos.x - cos(angle) * 0.2 + cos(angle - M_PI_2) * 0.5,
				objs->fdf->pos.y + sin(angle) * 0.2 - sin(angle - M_PI_2) * 0.5, 0);
		}
		else if (objs->type != WIN)
		{
			angle = atan2(pos->y - objs->pos.y, objs->pos.x - pos->x);
			set_point(&objs->oline.pt1, objs->pos.x - cos(angle) * 0.2 + cos(angle + M_PI_2) * 0.5,
				objs->pos.y + sin(angle) * 0.2 - sin(angle + M_PI_2) * 0.5, 0);
			set_point(&objs->oline.pt2, objs->pos.x - cos(angle) * 0.2 + cos(angle - M_PI_2) * 0.5,
				objs->pos.y + sin(angle) * 0.2 - sin(angle - M_PI_2) * 0.5, 0);
		}
		objs = objs->next;
	}
}