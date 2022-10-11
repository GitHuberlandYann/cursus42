/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:12:00 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/11 16:45:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = (int) ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (char) c)
			return ((char *) s + index);
		index --;
	}
	return (NULL);
}
