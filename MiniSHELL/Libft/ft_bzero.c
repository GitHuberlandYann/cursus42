#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*ptrs;

	if (!s)
		return ;
	ptrs = s;
	index = 0;
	while (index < n)
	{
		ptrs[index] = 0;
		index ++;
	}
}
