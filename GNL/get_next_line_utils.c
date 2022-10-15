/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:40:56 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 15:23:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res ++;
	return (res);
}

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
	if (s1)
		free((char *)s1);
	sub_index = 0;
	while (sub_index <= s2len)
		res[index ++] = s2[sub_index ++];
	return (res);
}

char	*ft_strdup(char **str)
{
	int		index;
	int		len;
	char	*res;

	len = (int)ft_strlen(*str);
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	index = 0;
	while (index < len)
	{
		res[index] = (*str)[index];
		index ++;
	}
	res[index] = '\0';
	ft_free_return(str);
	return (res);
}

char	*ft_strcpy_until_nl(char *str)
{
	int		index;
	int		size;
	char	*res;

	size = 0;
	while (str[size] != '\n' && str[size])
		size ++;
	res = malloc(sizeof(*res) * (size + 2));
	if (!res)
		return (0);
	index = 0;
	while (index <= size)
	{
		res[index] = str[index];
		index ++;
	}
	res[index] = '\0';
	return (res);
}

char	*ft_strcpy_from_nl(char **str)
{
	int		len;
	int		start;
	int		index;
	char	*res;

	if (!*str)
		return (0);
	len = (int)ft_strlen(*str);
	start = 0;
	while ((*str)[start] != '\n')
		start ++;
	start ++;
	res = malloc(sizeof(*res) * (len - start + 1));
	if (!res)
		return (ft_free_return(str));
	index = 0;
	while (start < len)
		res[index ++] = (*str)[start ++];
	res[index] = '\0';
	ft_free_return(str);
	return (res);
}
