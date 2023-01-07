#include "libft.h"

void	ft_free_arr(char **arr)
{
	int	index;

	if (!arr)
		return ;
	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}
