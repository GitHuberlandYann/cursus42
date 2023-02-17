/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_portaling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:48:04 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/05 17:48:04 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_linked(t_portal *portals, t_ray *ray, t_ray *pray, t_portal *in)
{
	double	u;

	while (portals)
	{
		if (portals->num == in->link)
		{
			pray->angle = ray->angle - (in->pline.side - 2) * M_PI_2 + portals->pline.side * M_PI_2;
			u = 1 - ray->u;
			set_point(&pray->ray.pt1, portals->pline.pt1.x + u * (portals->pline.pt2.x - portals->pline.pt1.x),  portals->pline.pt1.y + u * (portals->pline.pt2.y - portals->pline.pt1.y), 0);
			return ;
		}
		portals = portals->next;
	}
	exit(output_error("no link ????\n"));
}

static void	extend_ray(t_ray *ray, t_cub *cub, t_portal *in)
{
	t_ray		pray;

	get_linked(cub->map->portals, ray, &pray, in);
	pray.dist = 10000;
	if (cub->settings->fov_enable)
		pray.dist = cub->settings->fov_dist - ray->dist;
	pray.hit = CUT;
	pray.recurse_level = ray->recurse_level + 1;
	set_point(&pray.ray.pt2, pray.ray.pt1.x + cos(pray.angle) * pray.dist, pray.ray.pt1.y - sin(pray.angle) * pray.dist, 0);
	// printf("in %d out %d\n", in->num, out->num);
	// printf("angle of in %d out %d\n", in->pline.side, out->pline.side);
	// printf("angle in %lf out %lf\n", fmod(ray->angle / M_PI * 180, 360), fmod(pray.angle / M_PI * 180, 360));
	ray_walling(cub->map->walls, &pray);
	ray_dooring(cub->map->doors, &pray);
	// if (pray.recurse_level < cub->settings->recurse_level)
	// 	ray_portaling(cub->map->portals, &pray, cub);
	ray->dist += pray.dist;
	ray->pray = pray.ray;
	ray->out_angle = pray.angle;
	ray->u = pray.u;
	ray->hit = pray.hit;
	ray->fhit = PORTAL;
}

void	ray_portaling(t_portal *portals, t_ray *ray, t_cub *cub)
{
	t_vert	pt4;
	t_vert	intersection;
	double		dist;
	t_portal	*in;

	pt4.x = ray->ray.pt1.x + cos(ray->angle);
	pt4.y = ray->ray.pt1.y - sin(ray->angle);
	in = 0;
	while (portals)
	{
		intersection = get_inter(ray, pt4, portals->pline.pt1, portals->pline.pt2);
		if (intersection.z)
		{
			dist = get_dist(ray->ray.pt1, intersection);
			if (dist < ray->dist)
			{
				ray->ray.pt2 = intersection;
				ray->dist = dist;
				ray->pdist = dist;
				ray->hit = PORTAL;
				in = portals;
				ray->u = intersection.z - 1;
			}
		}
		portals = portals->next;
	}
	if (ray->hit == PORTAL && in)
		extend_ray(ray, cub, in);
}
