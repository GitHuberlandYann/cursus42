/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:31:13 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/20 13:03:06 by yhuberla         ###   ########.fr       */
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

	if (!s1 && !s2)
		return (0);
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
