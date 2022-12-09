/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fill_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:10:25 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/09 14:13:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

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
