/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:37:37 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/16 14:20:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index ++;
	return ((unsigned char) s1[index] - (unsigned char) s2[index]);
}
