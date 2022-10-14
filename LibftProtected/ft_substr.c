/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:24:45 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/04 16:10:19 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	index;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	index = 0;
	while (index < len && start + index < slen && s[start + index])
	{
		res[index] = s[start + index];
		index ++;
	}
	res[index] = '\0';
	return (res);
}
