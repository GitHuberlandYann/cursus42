/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:19:23 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/08 16:26:17 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(unsigned char c, int *res)
{
	ssize_t	ret;

	ret = write(1, &c, 1);
	(*res)++;
	if (ret == -1)
		*res = -1000000;
}

void	ft_putstr(char *str, int *res)
{
	int		len;
	ssize_t	ret;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ret = write(1, str, len);
	(*res) += len;
	if (ret == -1)
		*res = -1000000;
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
