/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:20:05 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/18 14:20:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

int	ft_parse(const char *str, int start, t_parse *current)
{
	int	end;

	end = start;
	current->type = ft_get_type(str, start);
	if (current->type != 'E')
	{
		end = ft_get_end(str, start);
		current->arglen = ft_arglen(current->type, current->ap);
		if (current->type != '%')
			current->int_copy = va_arg(current->ap, int);
		ft_parse_bonus2(str, start, end, current);
		if (ft_check_minus(str, start, end))
			current->minus = ft_atoi(str, start, end);
		else if (ft_check_zero(str, start, end)
			&& (!ft_check_precision(str, start, end) || current->type == '%'))
			current->zero = ft_atoi(str, start, end);
		else
			current->width = ft_atoi(str, start, end);
		if (ft_check_precision(str, start, end) && !current->zero)
			current->precision = ft_atoi_precision(str, start, end);
		if (!current->precision && !current->int_copy)
			current->arglen = 2 * (current->type == 'p');
	}
	return (end);
}

char	ft_get_type(const char *str, int index)
{
	while (str[index] && str[index] != 'c' && str[index] != 's'
		&& str[index] != 'p' && str[index] != 'd' && str[index] != 'i'
		&& str[index] != 'u' && str[index] != 'x' && str[index] != 'X'
		&& str[index] != '%')
		index ++;
	if (str[index] == 'i')
		return ('d');
	else if (str[index])
		return (str[index]);
	return ('E');
}

int	ft_get_end(const char *str, int index)
{
	while (str[index] != 'c' && str[index] != 's' && str[index] != 'p'
		&& str[index] != 'd' && str[index] != 'i' && str[index] != 'u'
		&& str[index] != 'x' && str[index] != 'X' && str[index] != '%')
		index ++;
	return (index);
}

int	ft_special_case_string(va_list ap_cpy)
{
	int		res;
	char	*str;

	str = va_arg(ap_cpy, char *);
	res = ft_strlen(str);
	if (!str)
		res = 6;
	return (res);
}

int	ft_arglen(char c, va_list ap)
{
	int		len;
	va_list	ap_cpy;

	va_copy(ap_cpy, ap);
	len = 0;
	if (c == 'd')
		len = ft_nbrlen(va_arg(ap_cpy, int));
	else if (c == 'c')
		len = 1;
	else if (c == 's')
		len = ft_special_case_string(ap_cpy);
	else if (c == 'p')
		len = (2
				+ ft_addresslen((unsigned long) va_arg(ap_cpy, void *)));
	else if (c == 'u')
		len = ft_unbrlen(va_arg(ap_cpy, unsigned int), 10);
	else if (c == 'x' || c == 'X')
		len = ft_unbrlen(va_arg(ap_cpy, unsigned int), 16);
	else if (c == '%')
		len = 1;
	va_end(ap_cpy);
	return (len);
}
