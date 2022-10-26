/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:40:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/26 19:49:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_fdf * fdf, int	rotation)
{
	fdf->angles->alpha += (M_PI / 180) * (1 - 2 * rotation);
	fdf->angles->sa = sin(fdf->angles->alpha);
	fdf->angles->ca = cos(fdf->angles->alpha);
}

void	rotation_y(t_fdf *fdf, int rotation)
{
	fdf->angles->beta += (M_PI / 180) * (1 - 2 * rotation);
	fdf->angles->sb = sin(fdf->angles->beta);
	fdf->angles->cb = cos(fdf->angles->beta);
}

void	rotation_z(t_fdf *fdf, int rotation)
{
	fdf->angles->gamma += (M_PI / 180) * (1 - 2 * rotation);
	fdf->angles->sg = sin(fdf->angles->gamma);
	fdf->angles->cg = cos(fdf->angles->gamma);
}