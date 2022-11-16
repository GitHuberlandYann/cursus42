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

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*save;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		save = current->next;
		free(current);
		current = save;
	}
	*lst = 0;
}
