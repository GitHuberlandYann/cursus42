/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:34:42 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 12:34:10 by yhuberla         ###   ########.fr       */
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
		else if (str[*index] == ' ' && !(previous % 2) && nb >= 0
			&& ft_get_type(str, *index) != 's')
			previous += ft_lb2_printf_char(' ', res, 1);
		else if (str[*index] == '+' && previous < 2 && nb >= 0)
			previous += ft_lb2_printf_char('+', res, 2);
		(*index)++;
	}
}

void	ft_loop_bonus_zero(const char *str, int *index, int *res, va_list ap)
{
	int		len;
	int		zeros;
	char	type;
	va_list	ap_cpy;

	va_copy(ap_cpy, ap);
	(*index)++;
	while (str[*index] == '0')
		(*index)++;
	zeros = ft_atoi_printf(str, index);
	type = ft_get_type(str, *index);
	len = ft_len_arg(type, &zeros, ap_cpy);
	if (str[*index] == '.')
	{
		if (ft_atoi_dotzero(str, *index) > len || ft_get_int_copy(ap) == 0)
			len = ft_atoi_dotzero(str, *index);
		if (type == 'd' || type == 'i')
			len += (ft_get_int_copy(ap) < 0) + (len == 0 && ft_get_int_copy(ap) != 0);
		ft_printf_many_char(' ', zeros - len, res);
	}
	else
		ft_printf_many_char('0', zeros - len, res);
	va_end(ap_cpy);
}

void	ft_loop_bonus_width(const char *str, int *index, int *res, va_list ap)
{
	int		len;
	int		spaces;
	int		index_dot;
	va_list	ap_cpy;

	va_copy(ap_cpy, ap);
	spaces = ft_atoi_printf(str, index);
	len = ft_len_arg(ft_get_type(str, *index), &spaces, ap_cpy);
	if (str[*index] == '.')
	{
		index_dot = *index + 1;
		index_dot = ft_atoi_printf(str, &index_dot);
		if (len > index_dot)
			len = index_dot;
	}
	ft_printf_many_char(' ', spaces - len, res);
	va_end(ap_cpy);
}

int	ft_loop_bonus_minus(const char *str, int *index, va_list ap)
{
	int		len;
	int		spaces;
	int		index_dot;
	char	type;
	va_list	ap_cpy;

	va_copy(ap_cpy, ap);
	(*index)++;
	while (str[*index] == '-')
		(*index)++;
	type = ft_get_type(str, *index);
	spaces = ft_atoi_printf(str, index);
	len = ft_len_arg(type, &spaces, ap_cpy);
	if (str[*index] == '.')
	{
		index_dot = *index + 1;
		index_dot = ft_atoi_printf(str, &index_dot);
		if (ft_checkstatement_minus(len, index_dot, type, ap))
			len = index_dot + (ft_get_int_copy(ap_cpy) < 0 && type != 's');
	}
	va_end(ap_cpy);
	return (spaces - len);
}

int	ft_loop_bonus_dot(const char *str, int *index, int *res, va_list *ap)
{
	int		len;
	int		zeros;
	int		minus;
	va_list	ap_cpy;

	va_copy(ap_cpy, *ap);
	minus = ft_atoi_printf(str, index);
	zeros = minus;
	len = ft_len_arg(ft_get_type(str, *index), &zeros, ap_cpy);
	if (str[*index] == 's')
		zeros = ft_printf_string_dot(va_arg(*ap, char *), zeros, res);
	else if (str[*index] == 'd' || str[*index] == 'i')
		len -= ft_get_int_copy(*ap) < 0;
	ft_printf_many_char('0', zeros - len, res);
	if (len < minus)
		minus = len;
	va_end(ap_cpy);
	return (minus);
}
