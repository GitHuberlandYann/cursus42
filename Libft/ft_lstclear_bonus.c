/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:41:37 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/11 17:41:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*save;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		save = current->next;
		ft_lstdelone(current, del);
		current = save;
	}
	*lst = 0;
}
