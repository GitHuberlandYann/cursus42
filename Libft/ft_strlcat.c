/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:55:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 11:59:38 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;

	if ((!dst && !dstsize) || !dstsize)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	index = 0;
	while (src[index] && index < dstsize - dstlen - 1)
	{
		dst[dstlen + index] = src[index];
		index ++;
	}
	dst[dstlen + index] = '\0';
	while (src[index])
		index ++;
	return (index + dstlen);
}
