#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //delete me

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *str);
char	*ft_strcpy_from(char *str, int start);
char	*ft_strcpy_until(char *str, int size);

#endif