/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:46:14 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/14 10:36:52 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;
	unsigned int	len;

	if (!s || !f)
		return ;
	len = (unsigned int) ft_strlen(s);
	index = 0;
	while (index < len)
	{
		f(index, &s[index]);
		index ++;
	}
}
