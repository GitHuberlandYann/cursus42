/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:25:26 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/18 15:27:24 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_get_type(char c)
{
	if (c == 'i')
		return ('d');
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%')
		return (c);
	return ('E');
}

int	ft_strlen(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res ++;
	return (res);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
