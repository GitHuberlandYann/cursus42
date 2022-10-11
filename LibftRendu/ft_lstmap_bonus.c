/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:42:14 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/11 17:42:14 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_free_return_lstmap(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, (*del));
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*copyter;

	if (!lst || !f || !del)
		return (0);
	copy = malloc(sizeof(*copy));
	if (!copy)
		return (0);
	copy->content = (*f)(lst->content);
	copy->next = 0;
	copyter = copy;
	while (lst->next)
	{
		copyter->next = malloc(sizeof(*(copyter->next)));
		if (!copyter->next)
			return (ft_free_return_lstmap(copy, (*del)));
		lst = lst->next;
		copyter = copyter->next;
		copyter->content = (*f)(lst->content);
		copyter->next = 0;
	}
	return (copy);
}
