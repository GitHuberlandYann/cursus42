/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:53:55 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 13:05:32 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	needex;

	if (!haystack || !needle)
		return (0);
	if (!needle[0])
		return ((char *) haystack);
	index = 0;
	while (index < len && haystack[index])
	{
		if (haystack[index] == needle[0])
		{
			needex = 0;
			while (needle[needex] && haystack[index + needex]
				&& needle[needex] == haystack[index + needex]
				&& index + needex < len)
				needex ++;
			if (!needle[needex])
				return ((char *) &haystack[index]);
		}
		index ++;
	}
	return (0);
}
