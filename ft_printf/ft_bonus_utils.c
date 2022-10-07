/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/07 16:41:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
