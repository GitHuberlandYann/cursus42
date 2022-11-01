/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:00:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/28 16:21:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	int		index;
	int		sign;
	long	res;
	long	save;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index ++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index ++] == '-')
			sign *= -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		save = res;
		res = res * 10 + str[index ++] - '0';
		if (res < save)
			return (save);
	}
	return (res * sign);
}
