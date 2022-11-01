#include "push_swap.h"

static int	*ft_free_return(int *tab)
{
	free(tab);
	return (0);
}

static int	ft_check_arg(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
		{
			if (str[index] != '-' || index > 0 || !str[index + 1])
				return (1);
		}
		++index;
	}
	return (index == 0);
}

static int	ft_duplicate(int *tab, int value, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (tab[index] == value)
			return (1);
		++index;
	}
	return (0);
}

int	*ft_parse_args(int ac, char **av)
{
	int		index;
	int		*res;
	long	buf;

	res = malloc(sizeof(*res) * (ac - 1));
	if (!res)
		return (0);
	index = 1;
	while (index < ac)
	{
		if (ft_check_arg(av[index]))
			return (ft_free_return(res));
		buf = ft_atoi(av[index]);
		if (buf > INT_MAX || buf < INT_MIN || ft_duplicate(res, buf, index - 1))
			return (ft_free_return(res));
		res[index - 1] = buf;
		++index;
	}
	return (res);
}
