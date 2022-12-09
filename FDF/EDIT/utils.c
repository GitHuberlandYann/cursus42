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

int	mlx_exit(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
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
