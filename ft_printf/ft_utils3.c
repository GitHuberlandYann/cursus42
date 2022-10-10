/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:03:56 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/10 11:45:36 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_address_to_hexa(unsigned long nb, int *res)
{
	char	mod;

	if (nb / 16)
		ft_convert_address_to_hexa(nb / 16, res);
	mod = nb % 16 + '0';
	if (mod > '9')
		mod += 'a' - ('9' + 1);
	ft_putchar_fd(mod, 1, res);
}

int	ft_get_int_copy(va_list ap)
{
	int		res;
	va_list	ap_cpy;

	va_copy(ap_cpy, ap);
	res = va_arg(ap_cpy, int);
	va_end(ap_cpy);
	return (res);
}

void	ft_display_sign(const char *str, int index, int *res, va_list ap)
{
	char	type;

	type = ft_get_type(str, index);
	if (type == 'd' || type == 'i')
	{
		if (ft_get_int_copy(ap) < 0)
			ft_putchar_fd('-', 1, res);
	}
}
