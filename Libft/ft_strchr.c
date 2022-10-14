/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:08:17 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 10:36:03 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char) c)
			return ((char *)&s[index]);
		index ++;
	}
	if (s[index] == (char) c)
		return ((char *)&s[index]);
	return (0);
}
