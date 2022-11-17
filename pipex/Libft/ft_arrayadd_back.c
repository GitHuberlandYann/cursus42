/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:28:56 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/17 12:29:01 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_return(char **res)
{
	int	index;

	index = 0;
	while (res[index])
		free(res[index++]);
	free(res);
	return (0);
}

char	**ft_arrayadd_back(char **arr, char *str)
{
	int		index;
	int		arrlen;
	char	**res;

	arrlen = ft_arraylen(arr);
	res = malloc(sizeof(*res) * (arrlen + 2));
	if (!res)
		return (0);
	index = 0;
	while (index < arrlen)
	{
		res[index] = arr[index];
		++index;
	}
	res[index] = ft_strdup(str);
	if (!res[index])
		return (ft_free_return(res));
	res[index + 1] = 0;
	return (res);
}
