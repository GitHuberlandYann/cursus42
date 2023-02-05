//Add header here
#include "cub3d.h"

static t_portal	*get_linked(t_portal *portals, t_portal *in, t_ray *ray, t_ray *pray)
{
	double	u;

	while (portals)
	{
		if (portals->num == in->link)
		{
			pray->angle = ray->angle - (in->pline.side - 2) * M_PI / 2 + portals->pline.side * M_PI / 2;
			u = ray->u;
			if (in->pline.side == portals->pline.side)
				u = 1 - u;
			set_point(&pray->ray.pt1, portals->pline.pt1.x + u * (portals->pline.pt2.x - portals->pline.pt1.x),  portals->pline.pt1.y + u * (portals->pline.pt2.y - portals->pline.pt1.y), 0);
			return (portals);
		}
		portals = portals->next;
	}
	output_error("no link ????\n");
	return (0);
}

static void	extend_ray(t_player *player, t_ray *ray, t_portal *in, t_cub *cub)
{
	t_ray		pray;
	t_portal	*out;

	(void)player;
	out = get_linked(cub->map->portals, in, ray, &pray);
	pray.dist = 10000;
	if (cub->settings->fov_enable)
		pray.dist = cub->settings->fov_dist - ray->dist;
	set_point(&pray.ray.pt2, pray.ray.pt1.x + cos(pray.angle) * pray.dist, pray.ray.pt1.y - sin(pray.angle) * pray.dist, 0);
	// printf("in %d out %d\n", in->num, out->num);
	// printf("angle of in %d out %d\n", in->pline.side, out->pline.side);
	// printf("angle in %lf out %lf\n", fmod(ray->angle / M_PI * 180, 360), fmod(pray.angle / M_PI * 180, 360));
	ray_walling(player, cub->map->walls, &pray);
	ray_dooring(player, cub->map->doors, &pray);
	ray->dist += pray.dist;
	ray->pray = pray.ray;
	(void)out;
}

void	ray_portaling(t_player *player, t_portal *portals, t_ray *ray, t_cub *cub)
{
	t_vertice	pt4;
	t_vertice	intersection;
	double		dist;
	t_portal	*target;

	pt4.x = player->pos.x + cos(ray->angle);
	pt4.y = player->pos.y - sin(ray->angle);
	target = 0;
	while (portals)
	{
		intersection = get_inter(ray, pt4, portals->pline.pt1, portals->pline.pt2);
		dist = get_dist(player->pos, intersection);
		if (intersection.z && dist < ray->dist)
		{
			ray->ray.pt2 = intersection;
			ray->dist = dist;
			ray->hit = PORTAL;
			target = portals;
		}
		portals = portals->next;
	}
	// (void)cub;
	if (ray->hit == PORTAL && target)
		extend_ray(player, ray, target, cub);
}
