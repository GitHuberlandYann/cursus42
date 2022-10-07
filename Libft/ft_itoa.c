/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:18:23 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/04 17:18:08 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_mallen_itoa(int n)
{
	size_t	res;

	res = 2;
	if (n < 0)
		res ++;
	while (n / 10)
	{
		res ++;
		n /= 10;
	}
	return (res);
}

void	ft_fill_itoa(char	*str, long n, int index)
{
	if (n / 10)
		ft_fill_itoa(str, n / 10, index - 1);
	str[index] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	mallen;

	mallen = ft_get_mallen_itoa(n);
	res = malloc(sizeof(*res) * mallen);
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		ft_fill_itoa(res, -(long) n, mallen - 2);
	}
	else
		ft_fill_itoa(res, n, mallen - 2);
	res[mallen - 1] = '\0';
	return (res);
}
