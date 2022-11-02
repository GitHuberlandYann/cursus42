/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:17:53 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:17:53 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_stack *a, t_stack *b)
{
	t_stack	*lis;

	(void)b;
	lis = ft_longest_subseq(a);
	if (!lis)
		return ;
	// ft_putstr("\nLIS -> ");
	// ft_display_stack(*lis);
	ft_push_unwanted(a, b, lis);
	free(lis->arr);
	free(lis);
	ft_insert_back(a, b);
	ft_put_ontop(a, 0);
}
