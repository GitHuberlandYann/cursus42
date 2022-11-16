/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:00:14 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/16 17:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1len;
	size_t	s2len;
	size_t	index;
	size_t	sub_index;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = malloc(sizeof(*res) * (s1len + s2len + 1));
	if (!res)
		return (0);
	index = 0;
	while (index < s1len)
	{
		res[index] = s1[index];
		index ++;
	}
	sub_index = 0;
	while (sub_index < s2len)
		res[index ++] = s2[sub_index ++];
	res[index] = '\0';
	return (res);
}
