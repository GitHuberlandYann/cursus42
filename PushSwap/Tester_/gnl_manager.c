/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:51:30 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 16:51:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static t_parse	*ft_free_return(t_list **lst, t_parse *res)
{
	int	index;

	ft_lstclear(lst, free);
	if (res->arr)
	{
		index = 0;
		while (res->arr[index])
			free(res->arr[index++]);
		free(res->arr);
	}
	free(res);
	return (0);
}

static t_parse	*ft_parselst(t_list *lst, int size)
{
	t_parse	*res;
	int		index;
	t_list	*lstsave;

	res = malloc(sizeof(*res));
	if (!res)
		return (ft_free_return(&lst, 0));
	res->arr = malloc(sizeof(*res->arr) * (size + 1));
	if (!res->arr)
		return (ft_free_return(&lst, res));
	index = 0;
	while (index < size)
	{
		res->arr[index] = lst->content;
		if (!res->arr[index])
			return (ft_free_return(&lst, res));
		lstsave = lst;
		lst = lst->next;
		free(lstsave);
		++index;
	}
	res->arr[index] = 0;
	res->wc = size;
	return (res);
}

t_parse	*ft_read_output(void)
{
	int		count;
	char	*line;
	t_list	*lst;
	t_list	*tmp;

	line = get_next_line(1);
	lst = 0;
	count = 0;
	while (line && line[0] != '\n')
	{
		++count;
		tmp = ft_lstnew(line);
		if (!tmp)
			return (ft_free_return(&lst, 0));
		ft_lstadd_back(&lst, tmp);
		line = get_next_line(1);
	}
	while (line)
	{
		free(line);
		line = get_next_line(1);
	}
	return (ft_parselst(lst, count));
}
