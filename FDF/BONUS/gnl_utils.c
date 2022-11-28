/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:04:04 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/28 17:57:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_vertadd_back(t_vertice **vert, t_vertice *new)
{
	t_vertice	*current;

	if (!vert || !new)
		return ;
	current = *vert;
	if (!current)
		*vert = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

static t_vertice	*ft_vertnew(char **content)
{
	t_vertice	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->x = ft_atof(content[1]);
	res->y = ft_atof(content[2]);
	res->z = ft_atof(content[3]);
	res->next = 0;
	return (res);
}

static void	ft_faceadd_back(t_face **face, t_face *new)
{
	t_face	*current;

	if (!face || !new)
		return ;
	current = *face;
	if (!current)
		*face = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

static t_face	*ft_facenew(char **content)
{
	t_face	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->first = ft_atoi(content[1]);
	res->second = ft_atoi(content[2]);
	res->third = ft_atoi(content[3]);
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
		ft_vertadd_back(&res->vert, ft_vertnew(arr)); //todo check error here
	else if (!ft_strcmp(arr[0], "f"))
		ft_faceadd_back(&res->faces, ft_facenew(arr)); //todo check error here
	ft_free_arr(arr);
	free(line);
}
