/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:35:11 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/17 13:35:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddresshexa2_fd(unsigned long nb, int fd, int *res)
{
	char	mod;

	if (nb / 16)
		ft_putaddresshexa2_fd(nb / 16, fd, res);
	mod = nb % 16 + '0';
	if (mod > '9')
		mod += 'a' - ('9' + 1);
	ft_putchar_fd(mod, fd, res);
}

void	ft_putaddresshexa_fd(void *ptr, int fd, int *res)
{
	ft_putstr_fd("0x", -1, fd, res);
	ft_putaddresshexa2_fd((unsigned long) ptr, fd, res);
}

void	ft_putchars_fd(unsigned char c, int count, int fd, int *res)
{
	int	index;

	index = 0;
	while (index < count)
	{
		ft_putchar_fd(c, fd, res);
		index ++;
	}
}
