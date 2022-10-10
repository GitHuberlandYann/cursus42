/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:08:20 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/10 11:52:31 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recursive_putnbr(unsigned long n, int fd, int *res)
{
	if (n / 10)
		ft_recursive_putnbr(n / 10, fd, res);
	ft_putchar_fd(n % 10 + '0', fd, res);
}

void	ft_putnbr_fd(long n, int fd, int *res)
{
	if (n < 0)
		ft_recursive_putnbr(-n, fd, res);
	else
		ft_recursive_putnbr(n, fd, res);
}
