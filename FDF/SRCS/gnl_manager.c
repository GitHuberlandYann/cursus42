/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:51 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 13:49:17 by marvin           ###   ########.fr       */
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

static int	*ft_split_to_tab(char **split, int mallen)
{
	int	index;
	int	*res;

	//ft_printf("in split_to_tab, mallen = %d\n", mallen);
	res = malloc(sizeof(*res) * mallen);
	if (!res)
		return (0);
	index = 0;
	while (index < mallen)
	{
		res[index] = ft_atoi(split[index]);
		++index;
	}
	return (res);
}

static t_map	*ft_parselst(t_map *res, t_list *lst)
{
	int		index;
	char	**split;
	
	//ft_printf("entering parselist, size = %d\n", res->maplen);
	res->map = malloc(sizeof(*res->map) * (res->maplen));
	if (!res->map)
		return (ft_free_return(&lst, 0, 0));
	index = 0;
	while (index < res->maplen)
	{
		split = ft_split(lst->content, ' ');
		if (!split)
			return (ft_free_return(&lst, res->map, 0));
		res->rowlen = ft_arraylen(split);
		if (split[res->rowlen - 1][0] == '\n')
			--res->rowlen;
		res->map[index] = ft_split_to_tab(split, res->rowlen);
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
	int		size;
	t_map	*res;
	char	*line;
	t_list	*lst;
	t_list	*tmp;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	fd = open(path, O_RDONLY);
	//ft_printf("fd : %d\n", fd);
	size = 0;
	lst = 0;
	if (fd)
	{
		line = get_next_line(fd);
		while (line && line[0])
		{
			//ft_printf("line at index %d : %s", size, line);
			++size;
			tmp = ft_lstnew(line);
			if (!tmp)
				return (ft_free_return(&lst, 0, 0));
			ft_lstadd_back(&lst, tmp);
			line = get_next_line(fd);
		}
		close(fd);
	}
	//ft_display_lst_content(lst);
	res->maplen = size;
	res = ft_parselst(res, lst);
	//ft_display_map_content(res);
	return (res);
}
