/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:24:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 10:07:46 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	char		*ptrdst;
	const char	*ptrsrc;

	if (!src && !dst)
		return (0);
	index = n;
	ptrdst = dst;
	ptrsrc = src;
	while (index > 0)
	{
		index --;
		ptrdst[index] = ptrsrc[index];
	}
	return (dst);
}
