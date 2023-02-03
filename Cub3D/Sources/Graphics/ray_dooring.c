//header
#include "cub3d.h"

static t_vertice	ray_dooring_fov(t_player *player, t_door *doors, t_vertice shortest, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;

	pt4.x = player->pos.x + cos(settings->ray_angle) * settings->fov_dist;
	pt4.y = player->pos.y - sin(settings->ray_angle) * settings->fov_dist;
	while (doors)
	{
		index = 0;
		while (index < 3)
		{
			if (doors->edges[index].side != CUT)
			{
				intersection = get_inter_fov(player->pos, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				if (intersection.z && get_dist(player->pos, intersection) < shortest.z)
				{
					shortest = intersection;
					shortest.z = get_dist(player->pos, intersection);
				}
				else if (!intersection.z && settings->fov_dist < shortest.z)
				{
					shortest = pt4;
					shortest.z = settings->fov_dist;
				}
			}
			++index;
		}
		doors = doors->next;
	}
	return (shortest);
}

t_vertice	ray_dooring(t_player *player, t_door *doors, t_vertice shortest, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;

	if (settings->fov_enable)
		return (ray_dooring_fov(player, doors, shortest, settings));
	pt4.x = player->pos.x + cos(settings->ray_angle);
	pt4.y = player->pos.y - sin(settings->ray_angle);
	while (doors)
	{
		index = 0;
		while (index < 3)
		{
			if (doors->edges[index].side != CUT)
			{
				intersection = get_inter(player->pos, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				if (intersection.z && get_dist(player->pos, intersection) < shortest.z)
				{
					shortest = intersection;
					shortest.z = get_dist(player->pos, intersection);
				}
			}
			++index;
		}
		doors = doors->next;
	}
	return (shortest);
}

void	try_door(t_player *player, t_door *doors)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	t_vertice	shortest;
	t_line		*target;

	shortest.z = 10000;
	target = 0;
	pt4.x = player->pos.x + cos(player->direction);
	pt4.y = player->pos.y - sin(player->direction);
	while (doors)
	{
		index = 0;
		while (index < 3)
		{
			if (doors->edges[index].side == DOOR || doors->edges[index].side == CUT)
			{
				intersection = get_inter(player->pos, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				if (intersection.z && get_dist(player->pos, intersection) < shortest.z)
				{
					shortest = intersection;
					shortest.z = get_dist(player->pos, intersection);
					target = &doors->edges[index];
				}
			}
			++index;
		}
		doors = doors->next;
	}
	if (shortest.z == 10000 || shortest.z > 0.6)
		return ;
	if (target->side == CUT)
		target->side = DOOR;
	else
		target->side = CUT;
}
