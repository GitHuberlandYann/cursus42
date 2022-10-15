/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:28:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 09:32:43 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("files/text_array_size", O_RDONLY);
	fd2 = open("files/text_file", O_RDONLY);
	printf("in main, fd : %d, fd2 : %d\n", fd, fd2);
	if (fd && fd2)
	{
		printf("buffer_size : %d\n", BUFFER_SIZE);
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		while (line && line2)
		{
			printf("LINE : %s", line);
			printf("LINE2: %s", line2);
			free(line);
			free(line2);
			line = get_next_line(fd);
			line2 = get_next_line(fd2);
		}
		system("leaks a.out");
		close(fd2);
		return (close(fd));
	}
	return (0);
}
