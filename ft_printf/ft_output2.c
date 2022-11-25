/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:21:26 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/25 12:32:50 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nb, int upper, t_res *res)
{
	char	mod;

	if (nb / 16)
		ft_puthexa(nb / 16, upper, res);
	mod = nb % 16 + '0';
	if (mod > '9' && !upper)
		mod += 'a' - ('9' + 1);
	else if (mod > '9')
		mod += 'A' - ('9' + 1);
	ft_putchar(mod, res);
}

void	ft_putaddresshexa2(unsigned long nb, t_res *res)
{
	char	mod;

	if (nb / 16)
		ft_putaddresshexa2(nb / 16, res);
	mod = nb % 16 + '0';
	if (mod > '9')
		mod += 'a' - ('9' + 1);
	ft_putchar(mod, res);
}

void	ft_putaddresshexa(void *ptr, t_res *res)
{
	ft_putstr("0x", res);
	ft_putaddresshexa2((unsigned long) ptr, res);
}
