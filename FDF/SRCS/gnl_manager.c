/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:51 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/25 13:38:51 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_free_return(t_list **lst, int **map, char **split)
{
	int	index;

	if (lst)
		ft_lstclear(lst, free);
	if (map)
	{
		index = 0;
		while (map[index])
			free(map[index ++]);
		free(map);
	}
	if (split)
	{
		index = 0;
		while (split[index])
			free(split[index ++]);
		free(split);
	}
	return (0);
}

static int	*ft_split_to_tab(char **split, t_map *map)
{
	int	index;
	int	*res;

	//ft_printf("in split_to_tab, mallen = %d\n", mallen);
	res = malloc(sizeof(*res) * map->rowlen);
	if (!res)
		return (0);
	index = 0;
	while (index < map->rowlen)
	{
		res[index] = ft_atoi(split[index]);
		if (abs(res[index]) > map->max_value) //may want to add abs(res[index])
			map->max_value = abs(res[index]);
		++index;
	}
	return (res);
}

static t_map	*ft_parselst(t_map *res, t_list *lst)
{
	int		index;
	char	**split;

	res->map = malloc(sizeof(*res->map) * (res->maplen));
	if (!res->map)
		return (ft_free_return(&lst, 0, 0));
	res->max_value = 0;
	index = 0;
	while (index < res->maplen)
	{
		split = ft_split(lst->content, ' ');
		if (!split)
			return (ft_free_return(&lst, res->map, 0));
		res->rowlen = ft_arraylen(split);
		if (split[res->rowlen - 1][0] == '\n')
			--res->rowlen;
		res->map[index] = ft_split_to_tab(split, res);
		if (!res->map[index])
			return (ft_free_return(&lst, res->map, split));
		lst = lst->next;
		ft_free_return(0, 0, split);
		++index;
	}
	ft_free_return(&lst, 0, 0);
	return (res);
}

t_map	*get_map(char	*path)
{
	int		fd;
	t_map	*res;
	char	*line;
	t_list	*lst;
	t_list	*tmp;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	fd = open(path, O_RDONLY);
	res->maplen = 0;
	lst = 0;
	if (fd)
	{
		line = get_next_line(fd);
		while (line && line[0])
		{
			++res->maplen;
			tmp = ft_lstnew(line);
			if (!tmp)
				return (ft_free_return(&lst, 0, 0));
			ft_lstadd_back(&lst, tmp);
			line = get_next_line(fd);
		}
		close(fd);
	}
	res = ft_parselst(res, lst);
	res->ratio = (float)res->maplen / 10.0 + (res->maplen < 10);
	return (res);
}
