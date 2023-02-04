//header
#include "cub3d.h"

static void	ray_dooring_fov(t_player *player, t_door *doors, t_ray *ray, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	double		dist;

	pt4.x = player->pos.x + cos(ray->angle) * settings->fov_dist;
	pt4.y = player->pos.y - sin(ray->angle) * settings->fov_dist;
	while (doors)
	{
		index = 0;
		while (index < 3)
		{
			if (doors->edges[index].side != CUT)
			{
				intersection = get_inter_fov(ray, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				dist = get_dist(player->pos, intersection);
				if (intersection.z && dist < ray->dist)
				{
					ray->ray.pt2 = intersection;
					ray->dist = dist;
					ray->hit = doors->edges[index].side;
				}
				else if (!intersection.z && settings->fov_dist < ray->dist)
				{
					ray->ray.pt2 = pt4;
					ray->dist = settings->fov_dist;
					ray->hit = CUT;
				}
			}
			++index;
		}
		doors = doors->next;
	}
}

void	ray_dooring(t_player *player, t_door *doors, t_ray *ray, t_settings *settings)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	double		dist;

	if (settings->fov_enable)
		return (ray_dooring_fov(player, doors, ray, settings));
	pt4.x = player->pos.x + cos(ray->angle);
	pt4.y = player->pos.y - sin(ray->angle);
	while (doors)
	{
		index = 0;
		while (index < 3)
		{
			if (doors->edges[index].side != CUT)
			{
				intersection = get_inter(ray, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				dist = get_dist(player->pos, intersection);
				if (intersection.z && dist < ray->dist)
				{
					ray->ray.pt2 = intersection;
					ray->dist = dist;
					ray->hit = doors->edges[index].side;
				}
			}
			++index;
		}
		doors = doors->next;
	}
}

void	try_door(t_player *player, t_door *doors)
{
	int			index;
	t_vertice	pt4;
	t_vertice	intersection;
	t_ray		ray;
	t_line		*target;

	ray.dist = 10000;
	set_point(&ray.ray.pt1, player->pos.x, player->pos.y, 0);
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
				intersection = get_inter(&ray, pt4, doors->edges[index].pt1, doors->edges[index].pt2);
				pt4.z = get_dist(player->pos, intersection);
				if (intersection.z && pt4.z < ray.dist)
				{
					ray.dist = pt4.z;
					target = &doors->edges[index];
				}
			}
			++index;
		}
		doors = doors->next;
	}
	if (ray.dist == 10000 || ray.dist > 0.6)
		return ;
	if (target->side == CUT)
		target->side = DOOR;
	else
		target->side = CUT;
}
