#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text_array_size", O_RDONLY);
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
		return (close(fd));
	}
	return (0);
}
