/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:19:07 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/18 14:19:07 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

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
	ft_putaddresshexa2((unsigned long) ptr, res);
}

void	ft_putchars(unsigned char c, int count, t_res *res)
{
	int	index;

	index = 0;
	while (index < count)
	{
		ft_putchar(c, res);
		++index;
	}
}
