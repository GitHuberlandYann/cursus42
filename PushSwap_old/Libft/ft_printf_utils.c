/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:25:26 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 13:32:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_get_type(char c)
{
	if (c == 'i')
		return ('d');
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%')
		return (c);
	return ('E');
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_nbrlen(int nb)
{
	int	res;

	res = 1 + (nb < 0);
	while (nb / 10)
	{
		nb /= 10;
		++res;
	}
	return (res);
}
