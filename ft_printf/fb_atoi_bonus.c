/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:19:48 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/18 14:19:48 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"

int	ft_atoi(const char *str, int index, int end)
{
	int	res;

	res = 0;
	while (index < end && str[index] != '.'
		&& !(str[index] >= '1' && str[index] <= '9'))
		index ++;
	while (str[index] >= '0' && str[index] <= '9')
		res = res * 10 + str[index++] - '0';
	return (res);
}

int	ft_atoi_precision(const char *str, int index, int end)
{
	while (str[index] != '.')
		index ++;
	return (ft_atoi(str, index + 1, end));
}
