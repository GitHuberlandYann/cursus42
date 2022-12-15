/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:24:58 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/15 10:38:03 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_point(t_vertice *pt, t_vertice delta, t_vertice o, double c)
{
	pt->x += delta.x;
	pt->zcol += c;
	if (delta.x)
		pt->y = delta.z * (pt->x - o.x) + o.y;
	else
		pt->y += delta.y;
}

static void	mlx_fill_triangle(t_fdf *fdf, t_vertice a, t_vertice b, t_vertice c)
{
	t_vertice	delta;
	t_vertice	deltc;
	t_vertice	starta;
	t_vertice	startc;
	double		len;

	set_points(&starta, &startc, a, c);
	set_delta(&delta, a, b);
	set_delta(&deltc, c, b);
	len = set_len(&delta, &deltc);
	set_cols(&a, &b, &c, len);
	while (len > 0)
	{
		mlx_draw_line(fdf, a, c);
		move_point(&a, delta, starta, a.z);
		move_point(&c, deltc, startc, b.z);
		--len;
	}
}

static void	mlx_fill_sphere(t_fdf *fdf)
{
	t_face		*tmp;
	t_vertice	a;
	t_vertice	b;
	t_vertice	c;
	t_vertice	d;

	tmp = fdf->map->faces;
	while (tmp)
	{
		plane_to_sphere(fdf->map, &a, tmp->face[0]);
		plane_to_sphere(fdf->map, &b, tmp->face[1]);
		plane_to_sphere(fdf->map, &c, tmp->face[2]);
		plane_to_sphere(fdf->map, &d, tmp->face[3]);
		a = set_vert(fdf, &a, 1);
		b = set_vert(fdf, &b, 1);
		c = set_vert(fdf, &c, 1);
		d = set_vert(fdf, &d, 1);
		mlx_fill_triangle(fdf, a, b, c);
		mlx_fill_triangle(fdf, a, d, c);
		tmp = tmp->next;
	}
}

void	mlx_fill_faces(t_fdf *fdf)
{
	t_face		*tmp;
	t_vertice	a;
	t_vertice	b;
	t_vertice	c;
	t_vertice	d;

	if (fdf->mlx->sphere)
		return (mlx_fill_sphere(fdf));
	tmp = fdf->map->faces;
	while (tmp)
	{
		a = set_vert(fdf, tmp->face[0], 0);
		b = set_vert(fdf, tmp->face[1], 0);
		c = set_vert(fdf, tmp->face[2], 0);
		d = set_vert(fdf, tmp->face[3], 0);
		mlx_fill_triangle(fdf, a, b, c);
		mlx_fill_triangle(fdf, a, d, c);
		tmp = tmp->next;
	}
}
