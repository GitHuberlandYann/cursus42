/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:16:35 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/17 15:54:57 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_struct(t_parse *current)
{
	printf("\ntype : %c\n", current->type);
	printf("arglen : %d\n", current->arglen);
	printf("int_copy : %d\n", current->int_copy);
	printf("space : %d\n", current->space);
	printf("hashtag : %d\n", current->hashtag);
	printf("plus : %d\n", current->plus);
	printf("width : %d\n", current->width);
	printf("minus : %d\n", current->minus);
	printf("zero : %d\n", current->zero);
	printf("precision : %d\n", current->precision);
}

void	ft_display_arg(char type, int precision, int *res, va_list *ap)
{
	if (type == 'c')
		ft_putchar_fd(va_arg(*ap, int), 1, res);
	else if (type == 's')
		ft_putstr_fd(va_arg(*ap, char *), precision, 1, res);
	else if (type == 'p')
		ft_putaddresshexa_fd(va_arg(*ap, void *), 1, res);
	else if (type == 'd')
		ft_putnbr_fd(va_arg(*ap, int), 1, res);
	else if (type == 'u')
		ft_putunbr_fd(va_arg(*ap, unsigned int), 1, res);
	else if (type == 'x')
		ft_puthexa_fd(va_arg(*ap, unsigned int), 0, 1, res);
	else if (type == 'X')
		ft_puthexa_fd(va_arg(*ap, unsigned int), 1, 1, res);
	else if (type == '%')
		ft_putchar_fd(type, 1, res);
}

void	ft_printf_exec(t_parse *current, int *res, va_list *ap)
{
	ft_putchars_fd(' ', ft_count_front_spaces(current), 1, res);
	if (current->int_copy < 0 && current->type == 'd')
		ft_putchar_fd('-', 1, res);
	else if (current->space && current->int_copy >= 0 && current->type == 'd')
		ft_putchar_fd(' ', 1, res);
	else if (current->plus && current->int_copy >= 0 && current->type == 'd')
		ft_putchar_fd('+', 1, res);
	else if (current->hashtag && current->type == 'x' && current->int_copy)
		ft_putstr_fd("0x", -1, 1, res);
	else if (current->hashtag && current->type == 'X' && current->int_copy)
		ft_putstr_fd("0X", -1, 1, res);
	ft_putchars_fd('0', ft_count_zeros(current), 1, res);
	if (!(current->precision) && !(current->int_copy))
		va_arg(*ap, int);
	else
		ft_display_arg(current->type, current->precision, res, ap);
	ft_putchars_fd(' ', ft_count_back_spaces(current), 1, res);
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
			ft_putchar_fd(str[index], 1, &res);
		else
		{
			index ++;
			ft_reset_parsing(current);
			index = ft_parse(str, index, current);
			if (current->type != 'E')
				ft_printf_exec(current, &res, ap);
		}
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
