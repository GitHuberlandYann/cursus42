/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:04:35 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/24 17:51:28 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_vertadd_back(t_fdfmap *map, t_vertice *new)
{
	if (!new)
		return ;
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

	res = ft_malloc(sizeof(*res), __func__);
	if (ft_arraylen(content) != 4)
	{
		output_error(MSG_FDFVERT);
		return (0);
	}
	res->x = strtod(content[1], NULL);
	res->y = strtod(content[2], NULL);
	res->z = strtod(content[3], NULL);
	res->next = 0;
	return (res);
}

static void	ft_faceadd_back(t_fdfmap *map, t_face *new)
{
	if (!new)
		return ;
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

	res = ft_malloc(sizeof(*res), __func__);
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

void	ft_add_line(t_fdfmap *res, char *line)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (!ft_strncmp(arr[0], "v", 2))
		ft_vertadd_back(res, ft_vertnew(arr));
	else if (!ft_strncmp(arr[0], "f", 2))
		ft_faceadd_back(res, ft_facenew(arr, res->vert));
	ft_free_arr(arr);
	free(line);
}
