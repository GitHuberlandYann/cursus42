/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:40:49 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/04 12:14:16 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_end_line(char *str, int *index)
{
	if (!str)
		return (0);
	while (str[*index])
	{
		if (str[*index] == '\n')
			return (1);
		(*index)++;
	}
	return (0);
}

static char	*ft_free_return(char **str)
{
	if (*str)
		free(*str);
	*str = 0;
	return (0);
}

static char	*gnl_return(char **memory, int read_ret)
{
	char	*line;

	if (*memory && read_ret > 0)
	{
		line = ft_strcpy_until_nl(*memory);
		if (!line)
			return (ft_free_return(memory));
		*memory = ft_strcpy_from_nl(memory);
	}
	else if (read_ret <= 0 && !(*memory)[0])
		return (ft_free_return(memory));
	else
		line = ft_strdup(memory);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*buf;
	int			read_ret;
	int			index;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_return(&memory));
	read_ret = 1;
	index = 0;
	while (!find_end_line(memory, &index) && read_ret > 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret * (read_ret >= 0)] = '\0';
		memory = ft_strjoin(memory, buf);
		if (!memory)
			return (ft_free_return(&buf));
	}
	free(buf);
	return (gnl_return(&memory, read_ret));
}
