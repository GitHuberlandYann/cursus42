/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:03:56 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/07 14:58:20 by yhuberla         ###   ########.fr       */
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
