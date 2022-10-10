#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text_file", O_RDONLY);
	printf("in main, fd : %d\n", fd);
	if (fd)
	{
		printf("buffer_size : %d\n", BUFFER_SIZE);
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
		while (line)
		{
			line = get_next_line(fd);
			printf("%s", line);
			if (line)
				free(line);
		}
		//system("leaks a.out");
		return (close(fd));
	}
	return (0);
}
