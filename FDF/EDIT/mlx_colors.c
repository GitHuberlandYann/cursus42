/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:14:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/09 12:15:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_edit.h"

static unsigned int	gradient_col(unsigned cola, unsigned colb, double percent)
{
	t_vertice		a;
	t_vertice		b;
	t_vertice		col;

	a.x = (cola / 0x10000);
	a.y = (cola / 0x100 - a.x * 0x100);
	a.z = (cola - a.y * 0x100 - a.x * 0x10000);
	b.x = (colb / 0x10000);
	b.y = (colb / 0x100 - b.x * 0x100);
	b.z = (colb - b.y * 0x100 - b.x * 0x10000);
	col.x = a.x + percent * (b.x - a.x);
	col.y = a.y + percent * (b.y - a.y);
	col.z = a.z + percent * (b.z - a.z);
	return ((int)col.z + (int)col.y * 0x100 + (int)col.x * 0x10000);
}

static double	percent_col(double start, double end, double percent)
{
	return ((percent - start) / (end - start));
}

unsigned int	get_color(double z, int max)
{
	double			perc;
	unsigned int	res;

	perc = -z / (double)max;
	if (perc <= 0.0)
		res = gradient_col(0xC1FF, 0x50, percent_col(0, -1.0, perc));
	else if (perc <= 0.32)
		res = gradient_col(0x26E07, 0xACFDB0, percent_col(0, 0.32, perc));
	else if (perc <= 0.60)
		res = gradient_col(0x785801, 0xdbba5e, percent_col(0.32, 0.60, perc));
	else
		res = 0xffffff;
	return (res);
}
