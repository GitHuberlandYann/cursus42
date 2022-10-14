/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:59:37 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/07 17:04:46 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_mallen_split(char const *s, char c)
{
	size_t	index;
	size_t	res;

	index = 0;
	res = 0;
	while (s[index])
	{
		while (s[index] == c)
			index ++;
		if (s[index] && s[index] != c)
		{
			res ++;
			while (s[index] && s[index] != c)
				index ++;
		}
	}
	return (res + 1);
}

char	*ft_get_next_word(char const *s, char c, size_t *ptri)
{
	size_t	len;
	size_t	index;
	char	*res;

	while (s[*ptri] == c)
		*ptri = *ptri + 1;
	len = 0;
	while (s[*ptri + len] && s[*ptri + len] != c)
		len ++;
	len ++;
	res = malloc(sizeof(*res) * len);
	if (!res)
		return (0);
	index = 0;
	while (index < len - 1)
	{
		res[index] = s[*ptri];
		index ++;
		*ptri = *ptri + 1;
	}
	return (res);
}

char	**ft_free_return(char **s, size_t limit)
{
	size_t	index;

	index = 0;
	while (index < limit)
		free(s[index ++]);
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	sindex;
	size_t	mallen;
	char	**res;

	if (!s)
		return (0);
	mallen = ft_get_mallen_split(s, c);
	res = malloc(sizeof(*res) * mallen);
	if (!res)
		return (0);
	index = 0;
	sindex = 0;
	while (index < mallen - 1)
	{
		res[index] = ft_get_next_word(s, c, &sindex);
		if (!res[index])
			return (ft_free_return(res, index));
		index ++;
	}
	res[index] = 0;
	return (res);
}
