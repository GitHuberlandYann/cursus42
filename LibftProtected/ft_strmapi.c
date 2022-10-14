/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:40:23 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 17:20:22 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	index;
	unsigned int	len;

	if (!s || !*f)
		return (0);
	len = (unsigned int)ft_strlen(s);
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	index = 0;
	while (index < len)
	{
		res[index] = (*f)(index, s[index]);
		index ++;
	}
	res[index] = '\0';
	return (res);
}
