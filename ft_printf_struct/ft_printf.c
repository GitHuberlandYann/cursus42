/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:16:35 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 17:11:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parse	ft_parse(const char *str, int *cursor, t_parse *current)
{
	current->arglen = ;
	current->int_copy = va_arg(*(current->ap), int);
	ft_fill_bonus2(str, cursor, current);
	if (str[*cursor] == '-')
		current->
	current->type = ;
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
			ft_parse(str, &index, current);
			if (current->type != 'E')
				ft_printf_exec(current, va_list *ap, &res)
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
		return (0);
	va_copy(*(current->ap), ap);
	res = ft_main_loop(str, current, &ap);
	va_end(*(current->ap));
	free(current);
	va_end(ap);
	return (res);
}