/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:19:23 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/25 12:46:51 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(unsigned char c, t_res *res)
{
	ssize_t	ret;

	if (res->error)
		return ;
	ret = write(1, &c, 1);
	++res->count;
	if (ret == -1)
		res->error = 1;
}

void	ft_putstr(char *str, t_res *res)
{
	int		len;
	ssize_t	ret;

	if (res->error)
		return ;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ret = write(1, str, len);
	res->count += len;
	if (ret == -1)
		res->error = 1;
}

void	ft_putnbr2(int nb, t_res *res)
{
	if (nb / 10)
		ft_putnbr2(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}

void	ft_putnbr(int nb, t_res *res)
{
	if (nb < 0)
		ft_putchar('-', res);
	ft_putnbr2(nb, res);
}

void	ft_putunbr(unsigned int nb, t_res *res)
{
	if (nb / 10)
		ft_putunbr(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}
