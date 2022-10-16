/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:36:22 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/16 16:55:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(unsigned char c, int fd, int *res)
{
	write(fd, &c, 1);
	(*res)++;
}

void	ft_putstr_fd(char *str, int size, int fd, int *res)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (size != -1 && size < len)
		len = size;
	write(fd, str, len);
	(*res) += len;
}

void	ft_putnbr_fd(int nb, int fd, int *res)
{
	if (nb / 10)
		ft_putnbr_fd(nb / 10, fd, res);
	ft_putchar_fd(ft_abs(nb % 10) + '0', fd, res);
}

void	ft_putunbr_fd(unsigned int nb, int fd, int *res)
{
	if (nb / 10)
		ft_putunbr_fd(nb / 10, fd, res);
	ft_putchar_fd(ft_abs(nb % 10) + '0', fd, res);
}

void	ft_puthexa_fd(unsigned int nb, int upper, int fd, int *res)
{
	char	mod;

	if (nb / 16)
		ft_puthexa_fd(nb / 16, upper, fd, res);
	mod = nb % 16 + '0';
	if (mod > '9' && !upper)
		mod += 'a' - ('9' + 1);
	else if (mod > '9')
		mod += 'A' - ('9' + 1);
	ft_putchar_fd(mod, fd, res);
}
