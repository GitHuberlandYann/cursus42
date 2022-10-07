/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:39:56 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 14:39:56 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(int c, int *res)
{
	ft_putchar_fd((char) c, 1, res);
}

void	ft_printf_string(char *str, int *res)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		(*res) += ft_strlen(str);
	}
	else
		ft_printf_string("(null)", res);
}

void	ft_printf_address(void *ptr, int *res)
{
	ft_putstr_fd("0x", 1);
	(*res) += 2;
	ft_convert_address_to_hexa((unsigned long) ptr, res);
}

void	ft_printf_decimal(int nb, int *res)
{
	ft_putnbr_fd(nb, 1, res);
}

void	ft_printf_int(int nb, int *res)
{
	ft_putnbr_fd(nb, 1, res);
}
