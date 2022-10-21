/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_output_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:19:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 16:46:21 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

void	ft_putchar(unsigned char c, int *res)
{
	ssize_t	ret;

	ret = write(1, &c, 1);
	(*res)++;
	if (ret == -1)
		*res = -1000000;
}

void	ft_putstr(char *str, int size, int *res)
{
	int		len;
	ssize_t	ret;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (size != -1 && size < len)
		len = size;
	ret = write(1, str, len);
	(*res) += len;
	if (ret == -1)
		*res = -1000000;
}

void	ft_putnbr(int nb, int *res)
{
	if (nb / 10)
		ft_putnbr(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}

void	ft_putunbr(unsigned int nb, int *res)
{
	if (nb / 10)
		ft_putunbr(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}

void	ft_puthexa(unsigned int nb, int upper, int *res)
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
