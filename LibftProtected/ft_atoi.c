/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:00:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 13:59:29 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	index;
	size_t	res;
	int		sign;

	if (!str)
		return (0);
	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
		|| str[index] == '\f' || str[index] == '\r' || str[index] == '\v')
		index ++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index ++;
	}
	while (str[index] >= '0' && str[index] <= '9')
		res = res * 10 + str[index ++] - '0';
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	else if (res - 1 > 9223372036854775807 && sign == -1)
		return (0);
	return (res * sign);
}
