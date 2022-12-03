/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:02:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/03 16:11:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_perror(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free_arr(char **arr)
{
	int	index;

	if (!arr)
		return ;
	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

void	ft_free_map(t_map *map)
{
	t_vertice	*tmpv;
	t_face		*tmpf;

	while (map->vert)
	{
		tmpv = map->vert->next;
		free(map->vert);
		map->vert = tmpv;
	}
	while (map->faces)
	{
		tmpf = map->faces->next;
		free(map->faces);
		map->faces = tmpf;
	}
	free(map);
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
