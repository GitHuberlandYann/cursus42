/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:41 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/22 12:27:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_arg(char type, va_list *ap)
{
	if (type == 'c')
		ft_putchar(va_arg(*ap, int));
	else if (type == 's')
		ft_putstr(va_arg(*ap, char *));
	else if (type == 'p')
		ft_putaddresshexa(va_arg(*ap, void *));
	else if (type == 'd')
		ft_putnbr(va_arg(*ap, int));
	else if (type == 'u')
		ft_putunbr(va_arg(*ap, unsigned int));
	else if (type == 'x')
		ft_puthexa(va_arg(*ap, unsigned int), 0);
	else if (type == 'X')
		ft_puthexa(va_arg(*ap, unsigned int), 1);
	else if (type == '%')
		ft_putchar(type);
}

void	ft_main_loop(const char *str, va_list *ap)
{
	int		index;
	char	type;

	index = 0;
	while (str[index])
	{
		if (str[index] != '%')
			ft_putchar(str[index]);
		else
		{
			index ++;
			type = ft_get_type(str[index]);
			if (type != 'E')
				ft_display_arg(type, ap);
			else
				break ;
		}
		index ++;
	}
}

void	ft_printf(const char *str, ...)
{
	va_list	ap;

	if (!str)
		return ;
	va_start(ap, str);
	ft_main_loop(str, &ap);
	va_end(ap);
}
