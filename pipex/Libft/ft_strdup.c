/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:16:52 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/16 17:53:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	size_t	strlen;
	size_t	index;
	char	*res;

	strlen = ft_strlen(str);
	res = malloc(sizeof(*res) * (strlen + 1));
	if (!res)
		return (0);
	index = 0;
	while (index < strlen + 1)
	{
		res[index] = str[index];
		index ++;
	}
	return (res);
}
