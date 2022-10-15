/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:38:48 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 14:38:48 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_util(char c, va_list *ap, int *res)
{
	if (c == 'c')
		ft_printf_char(va_arg(*ap, int), res);
	else if (c == 's')
		ft_printf_string(va_arg(*ap, char *), res);
	else if (c == 'p')
		ft_printf_address(va_arg(*ap, void *), res);
	else if (c == 'd')
		ft_printf_decimal(va_arg(*ap, int), res);
	else if (c == 'i')
		ft_printf_int(va_arg(*ap, int), res);
	else if (c == 'u')
		ft_printf_unsigned_int(va_arg(*ap, int), res);
	else if (c == 'x')
		ft_printf_hexa_lower(va_arg(*ap, int), res);
	else if (c == 'X')
		ft_printf_hexa_upper(va_arg(*ap, int), res);
	else if (c == '%')
		ft_printf_percent(res);
}

void	ft_printf_exec(const char *str, int *index, int *res, va_list *ap)
{
	int	minus;
	int	plus;

	va_list	ap_cpy;
	va_copy(ap_cpy, *ap);

	minus = 0;
	plus = ft_loop_bonus2(str, index, res, *ap);
	if (str[*index] != '-' && str[*index] != '0')
		ft_loop_bonus_width(str, index, res, *ap);
	if (str[*index] != '0')
		ft_display_sign(ft_get_type(str, *index), plus, res, *ap);
	if (str[*index] == '-')
		minus = ft_loop_bonus_minus(str, index, *ap);
	else if (str[*index] == '0')
		ft_loop_bonus_zero(str, index, res, *ap);
	if (str[*index] == '.')
	{
		(*index)++;
		if (ft_get_type(str, *index) == 's' || ft_get_int_copy(*ap) == 0)
		{
			if (ft_loop_bonus_dot(str, index, res, ap)
				&& ft_get_type(str, *index) != 's' && ft_get_int_copy(*ap) == 0)
				ft_call_util('d', ap, res);
			else if (ft_get_int_copy(*ap) == 0)
				va_arg(*ap, int);
		}
		else
		{
			ft_loop_bonus_dot(str, index, res, ap);
			ft_call_util(str[*index], ap, res);
		}
	}
	else
		ft_call_util(str[*index], ap, res);
	ft_printf_many_char(' ', minus - (ft_space_before(str, *index) && ft_get_int_copy(ap_cpy) >= 0), res);
	va_end(ap_cpy);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		index;
	int		res;

	if (!str)
		return (0);
	va_start(ap, str);
	index = 0;
	res = 0;
	while (str[index])
	{
		if (str[index] != '%')
			ft_putchar_fd(str[index], 1, &res);
		else if (ft_get_type(str, index + 1) != 'E')
		{
			index ++;
			ft_printf_exec(str, &index, &res, &ap);
		}
		index ++;
	}
	va_end(ap);
	return (res);
}
