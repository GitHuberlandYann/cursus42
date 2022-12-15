/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fill_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:10:25 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/15 14:02:42 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	set_len(t_vertice *delta, t_vertice *deltc)
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

void	set_points(t_vertice *sa, t_vertice *sc, t_vertice a, t_vertice c)
{
	sa->x = a.x;
	sa->y = a.y;
	sc->x = c.x;
	sc->y = c.y;
}

void	set_delta(t_vertice *delta, t_vertice s, t_vertice e)
{
	delta->x = e.x - s.x;
	delta->y = e.y - s.y;
	delta->z = delta->y / delta->x;
}

void	set_cols(t_vertice *a, t_vertice *b, t_vertice *c, double len)
{
	a->z = (b->zcol - a->zcol) / len;
	b->z = (b->zcol - c->zcol) / len;
	c->z = (c->zcol - a->zcol);
}

t_vertice	set_vert(t_fdf *fdf, t_vertice *v, int sph)
{
	t_vertice	r;

	r.x = ft_rotation_x(fdf->angles, v, fdf->map) * fdf->mlx->size
		+ fdf->mlx->offset_x;
	r.y = ft_rotation_y(fdf->angles, v, fdf->map) * fdf->mlx->size
		+ fdf->mlx->offset_y;
	r.zcol = v->z;
	if (sph)
		r.zcol = v->zcol;
	return (r);
}
