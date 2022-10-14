/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:48 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 08:32:48 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current->next)
	{
		ft_lstdelone(current, del);
		current = current->next;
	}
	ft_lstdelone(current, del);
	*lst = 0;
}
