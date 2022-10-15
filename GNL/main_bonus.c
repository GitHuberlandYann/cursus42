/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:28:46 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 12:20:09 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>

int	iTest = 1;

void check(int succes)
{
	if (succes)
		printf("%d : OK", iTest);
	else
		printf("%d : KO", iTest);
}

void gnl(int fd, char const * expectedReturn)
{
	char *  gnlReturn = get_next_line(fd);

	printf("fd : %.4d, ", fd);
	if (expectedReturn == NULL)
		check(gnlReturn == NULL);
	else
		check(!strcmp(gnlReturn, expectedReturn));
	printf(" -> %s",gnlReturn);
	if (!gnlReturn)
		printf("\n");
	free(gnlReturn);
	iTest++;
}

int	main(void)
{
	int	fd[4];

	//printf("open_max : %d\n", OPEN_MAX);

	fd[0] = open("files/41_with_nl", O_RDONLY);
	/* 1 */ gnl(1000, NULL);
	/* 2 */ gnl(fd[0], "0123456789012345678901234567890123456789\n");

	fd[1] = open("files/42_with_nl", O_RDONLY);
	/* 3 */ gnl(1001, NULL);
	/* 4 */ gnl(fd[1], "01234567890123456789012345678901234567890\n");

	fd[2] = open("files/43_with_nl", O_RDONLY);
	/* 5 */ gnl(1002, NULL);
	/* 6 */ gnl(fd[2], "012345678901234567890123456789012345678901\n");

	/* 7 */ gnl(1003, NULL);
	/* 8 */ gnl(fd[0], "0");

	/* 9 */ gnl(1004, NULL);
	/* 10 */ gnl(fd[1], "1");

	/* 11 */ gnl(1005, NULL);
	/* 12 */ gnl(fd[2], "2");

	/* 13 */ gnl(fd[0], NULL);
	/* 14 */ gnl(fd[1], NULL);
	/* 15 */ gnl(fd[2], NULL);


	fd[3] = open("files/nl", O_RDONLY);
	/* 16 */ gnl(1006, NULL);
	/* 17 */ gnl(fd[3], "\n");
	/* 18 */ gnl(1007, NULL);
	/* 19 */ gnl(fd[3], NULL);

	return (0);
}



// int	main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	char	*line;
// 	char	*line2;

// 	fd = open("files/text_array_size", O_RDONLY);
// 	fd2 = open("files/text_file", O_RDONLY);
// 	printf("in main, fd : %d, fd2 : %d\n", fd, fd2);
// 	if (fd && fd2)
// 	{
// 		printf("buffer_size : %d\n", BUFFER_SIZE);
// 		line = get_next_line(fd);
// 		line2 = get_next_line(fd2);
// 		while (line && line2)
// 		{
// 			printf("LINE : %s", line);
// 			printf("LINE2: %s", line2);
// 			free(line);
// 			free(line2);
// 			line = get_next_line(fd);
// 			line2 = get_next_line(fd2);
// 		}
// 		printf("%d\n", OPEN_MAX);
// 		system("leaks a.out");
// 		close(fd2);
// 		return (close(fd));
// 	}
// 	return (0);
// }
