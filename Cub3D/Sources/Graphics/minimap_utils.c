/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:19:25 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/13 10:59:12 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_disk(t_img *img, t_vert *center, int radius, unsigned int col)
{
	t_vert	pt;
	t_vert	pt2;

	pt2.x = center->x - radius;
	while (pt2.x < center->x + radius)
	{
		pt2.y = center->y - radius;
		while (pt2.y < center->y + radius)
		{
			if (get_dist(*center, pt2) <= radius)
			{
				pt.x = pt2.x;
				pt.y = pt2.y;
				mlx_pxl_put(img, pt.x, pt.y, col);
			}
			++pt2.y;
		}
		++pt2.x;
	}
}

void	draw_circle(t_img *img, t_vert *c, double r, unsigned int color)
{
	t_vert	pt;
	t_vert	pt2;
	double	dist;

	pt2.x = c->x - r;
	while (pt2.x < c->x + r)
	{
		pt2.y = c->y - r;
		while (pt2.y < c->y + r)
		{
			dist = get_dist(*c, pt2);
			if (dist <= r && dist >= r - 1)
			{
				pt.x = pt2.x;
				pt.y = pt2.y;
				mlx_pxl_put(img, pt.x, pt.y, color);
			}
			++pt2.y;
		}
		++pt2.x;
	}
}

void	draw_posts(t_img *img, t_map *map, t_set *sett)
{
	t_post	*post;
	t_vert	center;

	post = map->posts;
	while (post)
	{
		if (in_circle(&post->center, map->player->pos.x, map->player->pos.y,
				sett->radius_divww - post->radius))
		{
			set_point_follow(&center, &post->center, map, sett);
			draw_circle(img, &center, post->radius * sett->wall_width, WHITE);
		}
		post = post->next;
	}
}

void	draw_player(t_img *img, t_set *settings)
{
	t_vert	pos_translate;

	set_point(&pos_translate, settings->offset.x + MAP_RADIUS,
		settings->offset.y + MAP_RADIUS, 0);
	draw_disk(img, &pos_translate, PSIZE, RED);
}

void	add_north(t_img *canva, double angle, t_set *sett)
{
	t_vert	npos;

	if (!sett->mini_follow)
		set_point(&npos, sett->offset.x + MAP_RADIUS, sett->offset.y + 2.5, 0);
	else
		set_point(&npos,
			sett->offset.x + MAP_RADIUS + cos(angle) * (MAP_RADIUS - 2.5),
			sett->offset.y + MAP_RADIUS - sin(angle) * (MAP_RADIUS - 2.5), 0);
	draw_disk(canva, &npos, PSIZE * 2, RED);
}
