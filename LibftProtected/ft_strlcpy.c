/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:46:25 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 13:04:42 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	if (!src || !dst)
		return (0);
	index = 0;
	if (!dst || dstsize == 0)
		return (ft_strlen(src));
	while (src[index] && index < dstsize - 1)
	{
		dst[index] = src[index];
		index ++;
	}
	dst[index] = '\0';
	while (src[index])
		index ++;
	return (index);
}
