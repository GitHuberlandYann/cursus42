/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:41 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/25 13:30:20 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_arg(char type, t_res *res, va_list *ap)
{
	if (type == 'c')
		ft_putchar(va_arg(*ap, int), res);
	else if (type == 's')
		ft_putstr(va_arg(*ap, char *), res);
	else if (type == 'p')
		ft_putaddresshexa(va_arg(*ap, void *), res);
	else if (type == 'd')
		ft_putnbr(va_arg(*ap, int), res);
	else if (type == 'u')
		ft_putunbr(va_arg(*ap, unsigned int), res);
	else if (type == 'x')
		ft_puthexa(va_arg(*ap, unsigned int), 0, res);
	else if (type == 'X')
		ft_puthexa(va_arg(*ap, unsigned int), 1, res);
	else if (type == '%')
		ft_putchar(type, res);
}

static void	ft_main_loop(const char *str, t_res *res, va_list *ap)
{
	int		index;
	char	type;

	index = 0;
	while (str[index])
	{
		if (str[index] != '%')
			ft_putchar(str[index], res);
		else
		{
			++index;
			type = ft_get_type(str[index]);
			if (type != 'E')
				ft_display_arg(type, res, ap);
			else
				break ;
		}
		if (res->error)
			break ;
		++index;
	}
}

int	ft_printf(const char *str, ...)
{
	t_res	res;
	va_list	ap;

	if (!str)
		return (0);
	va_start(ap, str);
	res.error = 0;
	res.count = 0;
	ft_main_loop(str, &res, &ap);
	va_end(ap);
	if (res.error)
		return (-1);
	return (res.count);
}
