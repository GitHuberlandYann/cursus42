/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:40:49 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/10 17:40:49 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_end_line(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index ++;
	}
	return (0);
}

char	*ft_free_return(char *str)
{
	if (str)
		free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*buf;
	char		*line;
	int			read_ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	read_ret = 1;
	while (!find_end_line(memory) && read_ret > 0)
	{
		buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
		if (!buf)
			return (ft_free_return(memory));
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = '\0';
		memory = ft_strjoin(memory, buf);
		if (!memory)
			return (0);
		free(buf);
	}
	if (memory && read_ret > 0)
	{
		line = ft_strcpy_until(memory, find_end_line(memory));
		memory = ft_strcpy_from(memory, find_end_line(memory) + 1);
	}
	else if (read_ret <= 0 && !memory[0])
		return (0);
	else
	{
		line = ft_strdup(memory);
		if (memory)
			free(memory);
		memory = 0;
	}
	return (line);
}

/*char	*get_next_line(int fd)
{
	static char	*memory;
	char		live_read[BUFFER_SIZE + 1]; //problem with BUFFER_SIZE < 1, so malloc instead ?
	char		*line;
	int			read_ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_ret = 1;
	while (!find_end_line(memory) && read_ret > 0) //read more while no '\n' and no EOF
	{
		//printf("in gnl loop, fd : %d\n", fd);
		read_ret = read(fd, live_read, BUFFER_SIZE);
		live_read[read_ret] = '\0';
		//printf("buff : %d, amount read : %d, chars read : %s\n", BUFFER_SIZE, read_ret, live_read);
		memory = ft_strjoin(memory, live_read);
		//printf("--start--\nlive_read : %s, new memory : %s\n--end\n", live_read, memory);
		if (!memory)
			return (0);
	}
	line = 0;
	//printf("index of end line : %d\n", find_end_line(memory));
	//printf("test index : %d\n", find_end_line("This first line is meh.\n"));
	//printf("char before : %c\n", memory[find_end_line(memory) - 2]);
	//printf("char after : %c\n", memory[find_end_line(memory) + 1]);
	if (memory && read_ret > 0)
	{
		line = ft_strcpy_until(memory, find_end_line(memory));
		memory = ft_strcpy_from(memory, find_end_line(memory) + 1);
		//printf("line : %s, memory : %s\n", line, memory);
	}
	else if (read_ret <= 0 && !memory[0])
		return (0);
	else
	{
		line = ft_strdup(memory);
		memory = "";
	}
	return (line);
}*/
