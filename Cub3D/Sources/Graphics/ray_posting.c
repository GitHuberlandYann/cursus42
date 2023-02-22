#include "cub3d.h"

void	solve_singular(t_ray *ray, t_vert *abc, double delta, double m, double p, t_vert *trpt, t_vert *center, double radius)
{
	t_vert	intersection;
	double	dist;

	intersection.x = -abc->y + sqrt(delta) / (2 * abc->x);
	intersection.y = m * intersection.x + p;
	dist = get_dist(*trpt, intersection);
	if (dist < ray->dist)
	{
		set_point(&ray->ray.pt2, intersection.x + center->x, intersection.y + center->y, 0);
		ray->dist = dist;
		ray->hit = CIRCLE;
		ray->u = fmod(acos(intersection.x / radius), 1);
	}
}

void	solve_dual(t_ray *ray, t_vert *abc, double delta, double m, double p, t_vert *trpt, t_vert *center, double radius)
{
	t_vert	intersection;
	t_vert	intersectionbis;
	double	dist;
	double	distbis;

	intersection.x = (-abc->y + sqrt(delta)) / (2 * abc->x);
	intersection.y = m * intersection.x + p;
	intersection.z = 0;
	dist = get_dist(*trpt, intersection);
	intersectionbis.x = (-abc->y - sqrt(delta)) / (2 * abc->x);
	intersectionbis.y = m * intersectionbis.x + p;
	intersectionbis.z = 0;
	distbis = get_dist(*trpt, intersectionbis);
	if ((distbis < dist && (-cos(ray->angle) / (trpt->x - intersectionbis.x) > 0 || sin(ray->angle) / (trpt->y - intersectionbis.y) > 0))
		|| !(-cos(ray->angle) / (trpt->x - intersection.x) > 0 || sin(ray->angle) / (trpt->y - intersection.y) > 0))
	{
		dist = distbis;
		intersection = intersectionbis;
	}
	if (dist < ray->dist && (-cos(ray->angle) / (trpt->x - intersection.x) > 0 || sin(ray->angle) / (trpt->y - intersection.y) > 0))
	{
		set_point(&ray->ray.pt2, intersection.x + center->x, intersection.y + center->y, 0);
		ray->dist = dist;
		ray->hit = CIRCLE;
		ray->u = fmod(acos(intersection.x / radius), 1);
	}
}

void	ray_posting(t_post *posts, t_ray *ray)
{
	double	m;
	double	p;
	t_vert	abc;
	double	delta;
	t_vert	trpt;

	while (posts)
	{
		set_point(&trpt, ray->ray.pt1.x - posts->center.x, ray->ray.pt1.y - posts->center.y, 0);
		m = -tan(ray->angle);
		p = trpt.y - m * trpt.x;
		abc.x = 1 + m * m;
		abc.y = 2 * p * m;
		abc.z = p * p - posts->squared.z;
		delta = abc.y * abc.y - 4 * abc.x * abc.z;
		if (!delta)
			solve_singular(ray, &abc, delta, m, p, &trpt, &posts->center, posts->radius);
		else if (delta > 0)
			solve_dual(ray, &abc, delta, m, p, &trpt, &posts->center, posts->radius);
		posts = posts->next;
	}
}

// void	solve_singular(t_ray *ray, t_vert *abc, double delta, double m, double p)
// {
// 	t_vert	intersection;
// 	double	dist;

// 	intersection.x = -abc->y + sqrt(delta) / (2 * abc->x);
// 	intersection.y = m * intersection.x + p;
// 	dist = get_dist(ray->ray.pt1, intersection);
// 	if (dist < ray->dist)
// 	{
// 		ray->ray.pt2 = intersection;
// 		ray->dist = dist;
// 		ray->hit = CIRCLE;
// 		//todo ray->u ?? I guess acos or asin of inter.x-center.x
// 	}
// }

// void	solve_dual(t_ray *ray, t_vert *abc, double delta, double m, double p)
// {
// 	t_vert	intersection;
// 	t_vert	intersectionbis;
// 	double	dist;
// 	double	distbis;

// 	intersection.x = (-abc->y + sqrt(delta)) / (2 * abc->x);
// 	intersection.y = m * intersection.x + p;
// 	intersection.z = 0;
// 	dist = get_dist(ray->ray.pt1, intersection);
// 	intersectionbis.x = (-abc->y - sqrt(delta)) / (2 * abc->x);
// 	intersectionbis.y = m * intersectionbis.x + p;
// 	intersectionbis.z = 0;
// 	distbis = get_dist(ray->ray.pt1, intersectionbis);
// 	if (distbis < dist && (-cos(ray->angle)/(ray->ray.pt1.x - intersectionbis.x) > 0 || sin(ray->angle) / (ray->ray.pt1.y - intersectionbis.y) > 0))
// 	{
// 		dist = distbis;
// 		intersection = intersectionbis;
// 	}
// 	if (dist < ray->dist && (-cos(ray->angle)/(ray->ray.pt1.x - intersection.x) > 0 || sin(ray->angle) / (ray->ray.pt1.y - intersection.y) > 0))
// 	{
// 		ray->ray.pt2 = intersection;
// 		ray->dist = dist;
// 		ray->hit = CIRCLE;
// 		//todo ray->u ?? I guess acos or asin of inter.x-center.x
// 	}
// }

// void	ray_posting(t_post *posts, t_ray *ray)
// {
// 	double	m;
// 	double	p;
// 	t_vert	abc;
// 	double	delta;

// 	m = -tan(ray->angle);
// 	p = ray->ray.pt1.y - m * ray->ray.pt1.x;
// 	while (posts)
// 	{
// 		abc.x = 1 + m * m;
// 		abc.y = 2 * (p * m - posts->center.y * m - posts->center.x);
// 		abc.z = posts->squared.x + p * p - 2 * p * posts->squared.y + posts->squared.y - posts->squared.z;
// 		delta = abc.y * abc.y - 4 * abc.x * abc.z;
// 		if (!delta)
// 			solve_singular(ray, &abc, delta, m, p);
// 		else if (delta > 0)
// 			solve_dual(ray, &abc, delta, m, p);
// 		posts = posts->next;
// 	}
// }
