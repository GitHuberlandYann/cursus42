/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:58:52 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 14:40:36 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addresslen(unsigned long nb)
{
	int	res;

	res = 1;
	while (nb / 16)
	{
		res ++;
		nb /= 16;
	}
	return (res);
}

int	ft_checkstatement_minus(int len, int index_dot, char type, va_list ap)
{
	return ((len > index_dot && type == 's')
		|| ((len < index_dot)// || ft_get_int_copy(ap) <= 0)
			&& (type == 'd' || type == 'i'))
				|| ((type == 'u' || type == 'x' || type == 'X')
					&& (len < index_dot || ft_get_int_copy(ap) == 0)));
}

int	ft_space_before(const char *str, int index)
{
	while (str[index] != '%')
		index --;
	index ++;
	while (str[index] == ' ' || str[index] == '#' || str[index] == '+')
	{
		if ((str[index] == ' ' || str[index] == '+') && ft_get_type(str, index) != 's')
			return (1);
		index ++;
	}
	return (0);
}
