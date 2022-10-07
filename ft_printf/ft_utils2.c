/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:40:01 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 14:40:01 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_to_hexa(unsigned int nb, int upper, int *res)
{
	char	mod;

	if (nb / 16)
		ft_convert_to_hexa(nb / 16, upper, res);
	mod = nb % 16 + '0';
	if (mod > '9' && !upper)
		mod += 'a' - ('9' + 1);
	else if (mod > '9')
		mod += 'A' - ('9' + 1);
	ft_putchar_fd(mod, 1, res);
}

void	ft_printf_unsigned_int(unsigned int nb, int *res)
{
	ft_putnbr_fd(nb, 1, res);
}

void	ft_printf_hexa_lower(unsigned int nb, int *res)
{
	ft_convert_to_hexa(nb, 0, res);
}

void	ft_printf_hexa_upper(unsigned int nb, int *res)
{
	ft_convert_to_hexa(nb, 1, res);
}

void	ft_printf_percent(int *res)
{
	ft_putchar_fd('%', 1, res);
}
