/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:16:35 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 16:47:08 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

void	ft_display_arg(char type, int precision, int *res, va_list *ap)
{
	if (type == 'c')
		ft_putchar(va_arg(*ap, int), res);
	else if (type == 's')
		ft_putstr(va_arg(*ap, char *), precision, res);
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

void	ft_printf_exec(t_parse *current, int *res, va_list *ap)
{
	ft_putchars(' ', ft_count_front_spaces(current), res);
	if (current->int_copy < 0 && current->type == 'd')
		ft_putchar('-', res);
	else if (current->space && current->int_copy >= 0 && current->type == 'd')
		ft_putchar(' ', res);
	else if (current->plus && current->int_copy >= 0 && current->type == 'd')
		ft_putchar('+', res);
	else if (current->hashtag && current->type == 'x' && current->int_copy)
		ft_putstr("0x", -1, res);
	else if (current->hashtag && current->type == 'X' && current->int_copy)
		ft_putstr("0X", -1, res);
	if (current->type == 'p')
		ft_putstr("0x", -1, res);
	ft_putchars('0', ft_count_zeros(current), res);
	if (!(current->precision) && !(current->int_copy))
		va_arg(*ap, int);
	else
		ft_display_arg(current->type, current->precision, res, ap);
	ft_putchars(' ', ft_count_back_spaces(current), res);
}

int	ft_main_loop(const char *str, t_parse *current, va_list *ap)
{
	int	res;
	int	index;

	res = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] != '%')
			ft_putchar(str[index], &res);
		else
		{
			index ++;
			ft_reset_parsing(current);
			index = ft_parse(str, index, current);
			if (current->type != 'E')
				ft_printf_exec(current, &res, ap);
			else
				break ;
		}
		if (res < 0)
			return (-1);
		index ++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_parse	*current;

	if (!str)
		return (0);
	va_start(ap, str);
	current = malloc(sizeof(*current));
	if (!current)
		return (-1);
	va_copy(current->ap, ap);
	res = ft_main_loop(str, current, &ap);
	va_end(current->ap);
	free(current);
	va_end(ap);
	return (res);
}
