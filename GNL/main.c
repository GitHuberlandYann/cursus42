/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:40:42 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/10 17:40:42 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("files/text_array_size", O_RDONLY);
	printf("in main, fd : %d\n", fd);
	if (fd)
	{
		printf("buffer_size : %d\n", BUFFER_SIZE);
		line = get_next_line(fd);
		while (line)
		{
			printf("LINE : %s", line);
			free(line);
			line = get_next_line(fd);
		}
		//system("leaks a.out");
		return (close(fd));
	}
	return (0);
}
