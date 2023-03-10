/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_posting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:48:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 10:48:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	solve_singular(t_ray *ray, t_solve *solve, t_vert *trpt,
	t_post *post)
{
	t_vert	intersection;
	double	dist;

	intersection.x = -solve->b + sqrt(solve->delta) / (2 * solve->a);
	intersection.y = solve->m * intersection.x + solve->p;
	dist = get_dist(*trpt, intersection);
	if (dist < ray->dist)
	{
		set_point(&ray->ray.pt2, intersection.x + post->center.x,
			intersection.y + post->center.y, 0);
		ray->dist = dist;
		ray->hit = CIRCLE;
		ray->u = ft_fmod(acos(intersection.x / post->radius), 1);
	}
}

static void	set_newshortest(t_ray *ray, t_vert *intersection, t_post *post,
	double dist)
{
	set_point(&ray->ray.pt2, intersection->x + post->center.x,
		intersection->y + post->center.y, 0);
	ray->dist = dist;
	ray->hit = CIRCLE;
	ray->u = ft_fmod(acos(intersection->x / post->radius), 1);
}

static void	solve_dual(t_ray *ray, t_solve *solve, t_vert *trpt, t_post *post)
{
	t_vert	intersection;
	t_vert	intersectionbis;
	double	dist;
	double	distbis;

	intersection.x = (-solve->b + sqrt(solve->delta)) / (2 * solve->a);
	intersection.y = solve->m * intersection.x + solve->p;
	intersection.z = 0;
	dist = get_dist(*trpt, intersection);
	intersectionbis.x = (-solve->b - sqrt(solve->delta)) / (2 * solve->a);
	intersectionbis.y = solve->m * intersectionbis.x + solve->p;
	intersectionbis.z = 0;
	distbis = get_dist(*trpt, intersectionbis);
	if ((distbis < dist && (-cos(ray->angle) / (trpt->x - intersectionbis.x) > 0
				|| sin(ray->angle) / (trpt->y - intersectionbis.y) > 0))
		|| !(-cos(ray->angle) / (trpt->x - intersection.x) > 0
			|| sin(ray->angle) / (trpt->y - intersection.y) > 0))
	{
		dist = distbis;
		intersection = intersectionbis;
	}
	if (dist < ray->dist && (-cos(ray->angle) / (trpt->x - intersection.x) > 0
			|| sin(ray->angle) / (trpt->y - intersection.y) > 0))
		set_newshortest(ray, &intersection, post, dist);
}

void	ray_posting(t_post *posts, t_ray *ray)
{
	t_solve	solve;
	t_vert	trpt;

	while (posts)
	{
		set_point(&trpt, ray->ray.pt1.x - posts->center.x,
			ray->ray.pt1.y - posts->center.y, 0);
		solve.m = -tan(ray->angle);
		solve.p = trpt.y - solve.m * trpt.x;
		solve.a = 1 + solve.m * solve.m;
		solve.b = 2 * solve.p * solve.m;
		solve.c = solve.p * solve.p - posts->squared.z;
		solve.delta = solve.b * solve.b - 4 * solve.a * solve.c;
		if (!solve.delta)
			solve_singular(ray, &solve, &trpt, posts);
		else if (solve.delta > 0)
			solve_dual(ray, &solve, &trpt, posts);
		posts = posts->next;
	}
}
