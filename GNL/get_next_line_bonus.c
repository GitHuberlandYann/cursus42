/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:22:36 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/21 10:52:06 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_end_line(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index ++;
	}
	return (0);
}

char	*ft_free_return(char **str)
{
	if (*str)
		free(*str);
	*str = 0;
	return (0);
}

char	*gnl_return(char **memory, int read_ret)
{
	char	*line;

	if (*memory && read_ret > 0)
	{
		line = ft_strcpy_until_nl(*memory);
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
	static char	*memory[OPEN_MAX];
	char		*buf;
	int			read_ret;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	read_ret = 1;
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_return(&memory[fd]));
	while (!find_end_line(memory[fd]) && read_ret > 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret >= 0)
			buf[read_ret] = '\0';
		else
			buf[0] = '\0';
		memory[fd] = ft_strjoin(memory[fd], buf);
		if (!memory[fd])
			return (ft_free_return(&buf));
	}
	free(buf);
	return (gnl_return(&memory[fd], read_ret));
}
