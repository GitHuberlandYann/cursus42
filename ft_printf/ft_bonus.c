/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:34:42 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/08 22:42:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_loop_bonus2(const char *str, int *index, int *res, va_list ap)
{
	int		previous;
	int		nb;

	previous = 0;
	nb = va_arg(ap, int);
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

void	ft_loop_bonus_zero(const char *str, int *index, int *res, va_list ap)
{
	int		len;
	int		zeros;
	//to do : work with nb < 0 (-004 and not 000-4) but not when hexa..
	(*index)++;
	while (str[*index] == '0')
		(*index)++;
	zeros = ft_atoi_printf(str, index);
	len = ft_len_arg(ft_get_type(str, *index), &zeros, ap);
	if (str[*index] == '.')
	{
		len = ft_atoi_dotzero(str, *index);
		ft_printf_many_char(' ', zeros - len, res);
	}
	else
		ft_printf_many_char('0', zeros - len, res);
}

void	ft_loop_bonus_width(const char *str, int *index, int *res, va_list ap)
{
	int		len;
	int		spaces;

	spaces = ft_atoi_printf(str, index);
	len = ft_len_arg(ft_get_type(str, *index), &spaces, ap);
	ft_printf_many_char(' ', spaces - len, res);
}

int	ft_loop_bonus_minus(const char *str, int *index, va_list ap)
{
	int		len;
	int		spaces;

	(*index)++;
	while (str[*index] == '-')
		(*index)++;
	spaces = ft_atoi_printf(str, index);
	len = ft_len_arg(ft_get_type(str, *index), &spaces, ap);
	return (spaces - len);
}

int	ft_loop_bonus_dot(const char *str, int *index, int *res, va_list *ap)
{
	int		len;
	int		zeros;
	int		minus;
	va_list	ap_cpy; //here copy necessary

	va_copy(ap_cpy, *ap);
	minus = ft_atoi_printf(str, index);
	zeros = minus;
	len = ft_len_arg(ft_get_type(str, *index), &zeros, ap_cpy);
	if (str[*index] == 's')
		zeros = ft_printf_string_dot(va_arg(*ap, char *), zeros, res);
	ft_printf_many_char('0', zeros - len, res);
	va_end(ap_cpy);
	if (len < minus)
		minus = len;
	return (minus);
}
