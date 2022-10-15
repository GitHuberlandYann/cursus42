/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:39:24 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 10:01:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_charset(char c, const char *charset)
{
	size_t	index;

	index = 0;
	while (charset[index])
	{
		if (charset[index] == c)
			return (1);
		index ++;
	}
	return (0);
}

size_t	ft_get_mallen_trim(char const *str, char const *charset, size_t *start)
{
	size_t	index;

	index = 0;
	while (ft_is_charset(str[index], charset))
		index ++;
	*start = index;
	while (str[index])
		index ++;
	if (index > 0)
		index --;
	while (index > *start && ft_is_charset(str[index], charset))
		index --;
	return (index - *start + 2 - (ft_strlen(str) == 0));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	mallen;
	size_t	index;
	size_t	start;
	char	*res;

	if (!s1 || !set)
		return (0);
	start = 0;
	mallen = ft_get_mallen_trim(s1, set, &start);
	res = malloc(sizeof(*res) * mallen);
	if (!res)
		return (0);
	index = 0;
	while (index < mallen - 1)
		res[index ++] = s1[start ++];
	res[index] = '\0';
	return (res);
}
