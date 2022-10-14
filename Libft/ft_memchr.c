/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:47:30 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 10:01:49 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*ptrs;

	index = 0;
	ptrs = (unsigned char *)s;
	while (index < n)
	{
		if (ptrs[index] == (unsigned char) c)
			return (&ptrs[index]);
		index ++;
	}
	return (0);
}
