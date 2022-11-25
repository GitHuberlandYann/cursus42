/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_output_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:19:19 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/25 12:46:45 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

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

void	ft_putstr(char *str, int size, t_res *res)
{
	int		len;
	ssize_t	ret;

	if (res->error)
		return ;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (size != -1 && size < len)
		len = size;
	ret = write(1, str, len);
	res->count += len;
	if (ret == -1)
		res->error = 1;
}

void	ft_putnbr(int nb, t_res *res)
{
	if (nb / 10)
		ft_putnbr(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}

void	ft_putunbr(unsigned int nb, t_res *res)
{
	if (nb / 10)
		ft_putunbr(nb / 10, res);
	ft_putchar(ft_abs(nb % 10) + '0', res);
}

void	ft_puthexa(unsigned int nb, int upper, t_res *res)
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
