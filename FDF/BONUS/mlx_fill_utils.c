/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fill_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:10:25 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/09 14:47:08 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
