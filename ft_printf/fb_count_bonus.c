/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:34:20 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/17 13:34:20 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

int	ft_max(int len, int prec)
{
	if (len > prec)
		return (len);
	return (prec);
}

int	ft_min(int len, int prec)
{
	if (len < prec || prec == -1)
		return (len);
	return (prec);
}

int	ft_count_front_spaces(t_parse *current)
{
	int	res;

	res = current->width;
	if (current->type == 'd')
	{
		res -= (current->space && (current->int_copy >= 0));
		res -= (current->plus && (current->int_copy >= 0));
		current->precision += (current->int_copy < 0);
	}
	else if (current->type == 'x' || current->type == 'X')
		res -= 2 * (current->hashtag && current->int_copy);
	if (current->type != 's' && current->type != '%')
		res -= ft_max(current->arglen, current->precision);
	else
		res -= ft_min(current->arglen, current->precision);
	return (res);
}

int	ft_count_zeros(t_parse *cur)
{
	int	res;

	res = cur->zero;
	if (cur->type == 'd' && cur->precision == -1)
		res -= ((cur->space || cur->plus) && (cur->int_copy >= 0));
	if (cur->precision != -1 && cur->type != 's' && cur->type != '%')
		res += cur->precision;
	res -= cur->arglen;
	if (cur->hashtag && (cur->type == 'x' || cur->type == 'X'))
		res -= 2 * (cur->int_copy != 0 && cur->precision == -1);
	return (res);
}

int	ft_count_back_spaces(t_parse *current)
{
	int	res;

	res = current->minus;
	if (current->type == 'd')
	{
		res -= (current->space && (current->int_copy >= 0));
		res -= (current->plus && (current->int_copy >= 0));
	}
	else if (current->type == 'x' || current->type == 'X')
		res -= 2 * (current->hashtag && current->int_copy);
	if (current->type != 's' && current->type != '%')
		res -= ft_max(current->arglen, current->precision);
	else
		res -= ft_min(current->arglen, current->precision);
	return (res);
}
