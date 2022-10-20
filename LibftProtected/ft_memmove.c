/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:40:52 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 13:01:19 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	char		*ptrdst;
	const char	*ptrsrc;

	if (!dst || !src)
		return (0);
	ptrdst = dst;
	ptrsrc = src;
	if (dst > src)
	{
		index = len;
		while (index-- > 0)
			ptrdst[index] = ptrsrc[index];
	}
	else
	{
		index = 0;
		while (index < len)
		{
			ptrdst[index] = ptrsrc[index];
			index ++;
		}
	}
	return (dst);
}
