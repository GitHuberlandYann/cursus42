/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:34:42 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/07 16:54:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_loop_bonus2(const char *str, int *index, int *res, va_list ap)
{
	int		previous;
	int		nb;
	va_list	ap_cpy;

	previous = 0;
	va_copy(ap_cpy, ap);
	nb = va_arg(ap_cpy, int);
	va_end(ap_cpy);
	while (str[*index] == ' ' || str[*index] == '#' || str[*index] == '+')
	{
		if (str[*index] == '#' && str[*index + 1] == 'x' && nb != 0)
			ft_printf_string("0x", res);
		else if (str[*index] == '#' && str[*index + 1] == 'X' && nb != 0)
			ft_printf_string("0X", res);
		else if (str[*index] == ' ' && !(previous % 2) && nb >= 0)
			previous += ft_lb2_printf_char(' ', res, 1);
		else if (str[*index] == '+' && previous < 2 && nb >= 0)
			previous += ft_lb2_printf_char('+', res, 2);
		(*index)++;
	}
}

int	ft_len_arg(const char *str, int index, int *spaces, va_list ap_cpy)
{
	int	len;

	len = 0;
	if (str[index] == 'd' || str[index] == 'i')
		len = ft_nbrlen(va_arg(ap_cpy, int));
	else if (str[index] == 'c')
		len = 1;
	else if (str[index] == 's')
	{
		len = ft_strlen(va_arg(ap_cpy, char *));
		if (!len)
			(*spaces) -= 6;
	}
	else if (str[index] == 'p')
	{
		if (va_arg(ap_cpy, void *) != (void *)0)
			(*spaces) -= 14;
		else
			(*spaces) -= 3;
	}
	else if (str[index] == 'u')
		len = ft_unbrlen(va_arg(ap_cpy, unsigned int), 10);
	else if (str[index] == 'x' || str[index] == 'X')
		len = ft_unbrlen(va_arg(ap_cpy, unsigned int), 16);
	return (len);
}

void	ft_loop_bonus_width(const char *str, int *index, int *res, va_list ap)
{
	int		len;
	int		spaces;
	int		space_index;
	va_list	ap_cpy;

	va_copy(ap_cpy, ap);
	spaces = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		spaces = spaces * 10 + str[*index] - '0';
		(*index)++;
	}
	space_index = 0;
	len = ft_len_arg(str, *index, &spaces, ap_cpy);
	while (space_index < spaces - len)
	{
		ft_printf_char(' ', res);
		space_index ++;
	}
	va_end(ap_cpy);
}
