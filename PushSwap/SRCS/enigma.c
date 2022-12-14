/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enigma.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:59:53 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 12:59:53 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_compute(t_stack *a, t_stack *b)
{
	if (!ft_kinda_sorted(a))
		ft_put_ontop(a, 0);
	else if (a->size <= 6)
		ft_sort_small(a, b);
	else
		ft_sort_big(a, b);
	ft_exec_push(a, b, "");
}
