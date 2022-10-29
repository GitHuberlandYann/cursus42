/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:21:26 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 13:31:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned int nb, int upper)
{
	char	mod;

	if (nb / 16)
		ft_puthexa(nb / 16, upper);
	mod = nb % 16 + '0';
	if (mod > '9' && !upper)
		mod += 'a' - ('9' + 1);
	else if (mod > '9')
		mod += 'A' - ('9' + 1);
	ft_putchar(mod);
}

void	ft_putaddresshexa2(unsigned long nb)
{
	char	mod;

	if (nb / 16)
		ft_putaddresshexa2(nb / 16);
	mod = nb % 16 + '0';
	if (mod > '9')
		mod += 'a' - ('9' + 1);
	ft_putchar(mod);
}

void	ft_putaddresshexa(void *ptr)
{
	ft_putstr("0x");
	ft_putaddresshexa2((unsigned long) ptr);
}

void	ft_putchars(unsigned char c, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		write(1, &c, 1);
		++index;
	}
}
