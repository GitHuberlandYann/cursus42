/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:58:52 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/11 15:00:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addresslen(unsigned long nb)
{
	int	res;

	res = 1;
	while (nb / 16)
	{
		res ++;
		nb /= 16;
	}
	return (res);
}
