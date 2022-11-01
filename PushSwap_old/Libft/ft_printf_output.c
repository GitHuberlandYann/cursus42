/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:19:23 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 12:25:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
}

void	ft_putnbr2(int nb)
{
	if (nb / 10)
		ft_putnbr2(nb / 10);
	ft_putchar(ft_abs(nb % 10) + '0');
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	ft_putnbr2(nb);
}

void	ft_putunbr(unsigned int nb)
{
	if (nb / 10)
		ft_putunbr(nb / 10);
	ft_putchar(ft_abs(nb % 10) + '0');
}
