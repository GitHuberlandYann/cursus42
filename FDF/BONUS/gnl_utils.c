/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:04:04 by yhuberla          #+#    #+#             */
/*   Updated: 2022/12/27 13:28:46 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_vertadd_back(t_map *map, t_vertice *new)
{
	if (!map->vert_last)
	{
		map->vert_last = new;
		map->vert = new;
	}
	else
	{
		map->vert_last->next = new;
		map->vert_last = new;
	}
}

static t_vertice	*ft_vertnew(char **content)
{
	t_vertice	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_perror(__func__);
	if (ft_arraylen(content) != 4)
		ft_perror("invalid map");
	res->x = ft_atolf(content[1]);
	res->y = ft_atolf(content[2]);
	res->z = ft_atolf(content[3]);
	res->next = 0;
	return (res);
}

static void	ft_faceadd_back(t_map *map, t_face *new)
{
	if (!map->faces_last)
	{
		map->faces_last = new;
		map->faces = new;
	}
	else
	{
		map->faces_last->next = new;
		map->faces_last = new;
	}
}

static t_face	*ft_facenew(char **content, t_vertice *vert)
{
	t_face	*res;
	int		index;
	int		vert_index;

	res = malloc(sizeof(*res));
	if (!res)
		ft_perror(__func__);
	index = 0;
	while (content[index + 1] && index < 4)
	{
		vert_index = ft_atoi(content[index + 1]);
		res->face[index] = *ft_get_node(vert, vert_index);
		++index;
	}
	res->poly = index;
	res->next = 0;
	return (res);
}

void	ft_add_line(t_map *res, char *line)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (!arr)
		ft_perror("ft_split");
	if (!ft_strcmp(arr[0], "v"))
		ft_vertadd_back(res, ft_vertnew(arr));
	else if (!ft_strcmp(arr[0], "f"))
		ft_faceadd_back(res, ft_facenew(arr, res->vert));
	ft_free_arr(arr);
	free(line);
}
