/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:19:23 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/18 15:39:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(unsigned char c, int *res)
{
	write(1, &c, 1);
	(*res)++;
}

void	ft_putstr(char *str, int *res)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	(*res) += len;
}

void	ft_putnbr2(int nb, int *res)
{
	if (nb / 10)
		ft_putnbr2(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}

void	ft_putnbr(int nb, int *res)
{
	if (nb < 0)
		ft_putchar('-', res);
	ft_putnbr2(nb, res);
}

void	ft_putunbr(unsigned int nb, int *res)
{
	if (nb / 10)
		ft_putunbr(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}
