/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 10:18:31 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_printf(const char *str, int *index)
{
	int	res;

	res = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		res = res * 10 + str[*index] - '0';
		(*index)++;
	}
	return (res);
}

int	ft_printf_string_dot(char *str, int size, int *res)
{
	int	index;

	if (!str)
		str = "(null)";
	index = 0;
	while (str[index] && index < size)
	{
		ft_putchar_fd(str[index], 1, res);
		index ++;
	}
	return (0);
}

int	ft_lb2_printf_char(char c, int *res, int result)
{
	ft_printf_char(c, res);
	return (result);
}

int	ft_nbrlen(int nb)
{
	int	res;

	res = 1 + (nb < 0);
	while (nb / 10)
	{
		nb /= 10;
		res ++;
	}
	return (res);
}

int	ft_unbrlen(unsigned int nb, int base)
{
	int	res;

	res = 1;
	while (nb / base)
	{
		nb /= base;
		res ++;
	}
	return (res);
}
