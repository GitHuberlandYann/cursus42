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

#include "checker.h"

static char	**ft_free_return(t_list **lst, char **res)
{
	int	index;

	ft_lstclear(lst, free);
	if (res)
	{
		index = 0;
		while (res[index])
			free(res[index++]);
		free(res);
	}
	return (0);
}

static char	**ft_parselst(t_list *lst, int size)
{
	int		index;
	char	**res;
	t_list	*lstsave;

	res = malloc(sizeof(*res) * (size + 1));
	if (!res)
		return (ft_free_return(&lst, 0));
	index = 0;
	while (index < size)
	{
		res[index] = lst->content;
		if (!res[index])
			return (ft_free_return(&lst, res));
		lstsave = lst;
		lst = lst->next;
		free(lstsave);
		++index;
	}
	res[index] = 0;
	return (res);
}

char	**ft_read_input(void)
{
	int		size;
	char	*line;
	t_list	*lst;
	t_list	*tmp;

	line = get_next_line(0);
	lst = 0;
	size = 0;
	while (line)
	{
		++size;
		tmp = ft_lstnew(line);
		if (!tmp)
			return (ft_free_return(&lst, 0));
		ft_lstadd_back(&lst, tmp);
		line = get_next_line(0);
	}
	return (ft_parselst(lst, size));
}
