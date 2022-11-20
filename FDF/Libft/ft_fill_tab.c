/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:28:46 by marvin            #+#    #+#             */
/*   Updated: 2022/11/19 14:28:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"  //update header

void	ft_fill_tab(int *tab, int nb, ...)
{
	int		index;
	va_list	ap;

	va_start(ap, nb);
	index = 0;
	while (index < nb)
		tab[index++] = va_arg(ap, int);
	va_end(ap);
}
