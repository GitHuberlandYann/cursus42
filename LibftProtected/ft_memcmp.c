/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:50:40 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/07 10:43:42 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		index;
	const char	*ptrs1;
	const char	*ptrs2;

	if (!s1 || !s2 || n <= 0)
		return (0);
	index = 0;
	ptrs1 = (const char *) s1;
	ptrs2 = (const char *) s2;
	while (index < n - 1 && ptrs1[index] == ptrs2[index])
		index ++;
	return ((unsigned char) ptrs1[index] - (unsigned char) ptrs2[index]);
}
/*
*#include <stdio.h>
*#include <string.h>
*int	main(void)
*{
*	char s2[] = {0, 0, 127, 0};
*	char s3[] = {0, 0, 42, 0};
*	printf("%d\n", memcmp(s2, s3, 4));
*	printf("%d\n", ft_memcmp(s2, s3, 4));
*	return (0);
*}
*
* || (((char *)s1)[0] == '\0'
*		&& ((char*)s2)[0] == '\0') at end of if statement
*/
