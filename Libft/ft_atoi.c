/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:00:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 09:46:06 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	index;
	size_t	res;
	int		sign;
	int		strlen;

	index = 0;
	sign = 1;
	res = 0;
	strlen = 0;
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index ++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index ++] == '-')
			sign *= -1;
	}
	while (str[index] == '0')
		index ++;
	while (str[index] >= '0' && str[index] <= '9' && ++strlen < 23)
		res = res * 10 + str[index ++] - '0';
	if ((res > 9223372036854775807 || strlen >= 20) && sign == 1)
		return (-1);
	else if ((res - 1 > 9223372036854775807 || strlen >= 20) && sign == -1)
		return (0);
	return (res * sign);
}
