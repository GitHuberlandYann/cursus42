#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t res;

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
	sub_index = 0;
	while (sub_index < s2len)
		res[index ++] = s2[sub_index ++];
	res[index] = '\0';
	if (s1)
		free((void *)s1);
	return (res);
}

char	*ft_strdup(char *str)
{
	int		index;
	int		len;
	char	*res;

	len = (int)ft_strlen(str);
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	index = 0;
	while (index < len)
	{
		res[index] = str[index];
		index ++;
	}
	res[index] = '\0';
	return (res);
}

char	*ft_strcpy_until(char *str, int size)
{
	int		index;
	char	*res;

	res = malloc(sizeof(*res) * (size + 1));
	if (!res)
		return (0);
	index = 0;
	while (index <= size) //<= because we want to copy '\n' too
	{
		res[index] = str[index];
		index ++;
	}
	res [index] = '\0';
	return (res);
}

char	*ft_strcpy_from(char *str, int start)
{
	int		len;
	int		index;
	char	*res;

	if (!str)
		return (0);
	len = (int)ft_strlen(str);
	if (start > len)
		return ("");
	res = malloc(sizeof(*res) * (len - start + 1));
	if (!res)
		return (0); //and some of those frees ?
	index = 0;
	while (start < len)
		res[index ++] = str[start ++];
	res[index] = '\0';
	if (str)
		free(str);
	return (res);
}
