/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:58 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/18 14:17:58 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

int	ft_strlen(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res ++;
	return (res);
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

int	ft_addresslen(unsigned long nb)
{
	int	res;

	res = 1;
	while (nb / 16)
	{
		nb /= 16;
		res ++;
	}
	return (res);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
