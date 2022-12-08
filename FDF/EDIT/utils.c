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
	double			value;
	unsigned int	res;

	value = -z / (double)max;
	if (value <= 0.02)
		res = 0xff;
	else if (value <= 0.18)
		res = 0xff00;
	else if (value <= 0.35)
		res = 0x800000;
	else
		res = 0xffffff;
	return (res);
}
