/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:07:54 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/10 09:07:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_many_char(char c, int size, int *res)
{
	int	index;

	index = 0;
	while (index < size)
	{
		ft_printf_char(c, res);
		index ++;
	}
}

char	ft_get_type(const char *str, int index)
{
	while (str[index] && str[index] != 'c' && str[index] != 's'
		&& str[index] != 'p' && str[index] != 'd' && str[index] != 'i'
		&& str[index] != 'u' && str[index] != 'x' && str[index] != 'X'
		&& str[index] != '%')
		index ++;
	if (str[index] && str[index] != 'i')
		return (str[index]);
	else if (str[index] == 'i')
		return ('d');
	return ('E');
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

int	ft_len_arg(char c, int *spaces, va_list ap)
{
	int		len;
	va_list	ap_cpy;

	va_copy(ap_cpy, ap);
	len = 0;
	if (c == 'd' || c == 'i')
		len = ft_nbrlen(va_arg(ap_cpy, int));
	else if (c == 'c')
		len = 1;
	else if (c == 's')
		len = ft_special_case_string(ap_cpy);
	else if (c == 'p')
		(*spaces) -= (2
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

int	ft_atoi_dotzero(const char *str, int index)
{
	int	res;

	index ++;
	res = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index ++;
	}
	return (res);
}
