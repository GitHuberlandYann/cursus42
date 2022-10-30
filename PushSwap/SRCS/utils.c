/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:23:24 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 14:23:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stack(t_stack stack)
{
    int	index;

	index = 0;
	ft_printf("size %d, stack: ", stack.size);
	while (index < stack.size)
		ft_printf("%d, ", stack.arr[index++]);
	ft_putchar('\n');
}
