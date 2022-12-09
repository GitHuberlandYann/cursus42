/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:24:58 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/09 14:13:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

static double	set_len(t_vertice *delta, t_vertice *deltc)
{
	double	lena;
	double	lenc;
	double	res;

	lena = sqrt(delta->x * delta->x + delta->y * delta->y);
	lenc = sqrt(deltc->x * deltc->x + deltc->y * deltc->y);
	if (lena > lenc)
		res = lena;
	else
		res = lenc;
	delta->x /= res;
	delta->y /= res;
	deltc->x /= res;
	deltc->y /= res;
	return (res);
}

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

static t_vertice	mlx_set_vert(t_fdf *fdf, t_vertice *v)
{
	t_vertice	r;

	r.x = ft_rotation_x(fdf->angles, v) * fdf->mlx->size + fdf->mlx->offset_x;
	r.y = ft_rotation_y(fdf->angles, v) * fdf->mlx->size + fdf->mlx->offset_y;
	r.zcol = v->z;
	return (r);
}

void	mlx_fill_faces(t_fdf *fdf)
{
	t_face		*tmp;
	t_vertice	a;
	t_vertice	b;
	t_vertice	c;
	t_vertice	d;

	tmp = fdf->map->faces;
	while (tmp)
	{
		a = mlx_set_vert(fdf, tmp->face[0]);
		b = mlx_set_vert(fdf, tmp->face[1]);
		c = mlx_set_vert(fdf, tmp->face[2]);
		d = mlx_set_vert(fdf, tmp->face[3]);
		mlx_fill_triangle(fdf, a, b, c);
		mlx_fill_triangle(fdf, a, d, c);
		tmp = tmp->next;
	}
}
