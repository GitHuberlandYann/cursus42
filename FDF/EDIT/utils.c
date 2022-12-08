/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:43:26 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 13:43:26 by marvin           ###   ########.fr       */
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

void	ft_perror(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

t_vertice	*ft_get_node(t_vertice *vert, int index)
{
	int			count;
	t_vertice	*res;

	res = vert;
	count = 1;
	while (count < index && res)
	{
		res = res->next;
		++count;
	}
	return (res);
}

unsigned int	get_color(double z, int max)
{
	double			percent;
	unsigned int	res;

	percent = -z / (double)max;
	if (percent <= 0.0)
		res = gradient_col(0xff, 0x50, percent_col(0, -1.0, percent));
	else if (percent <= 0.18)
		res = gradient_col(0xfd00, 0x5000, percent_col(0, 0.18, percent));
	else if (percent <= 0.35)
		res = gradient_col(0xdbba5e, 0x785801, percent_col(0.18, 0.35, percent));
	else
		res = 0xffffff;
	return (res);
}
