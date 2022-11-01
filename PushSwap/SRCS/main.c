#include "push_swap.h"

static int	ft_error(int *tab)
{
	free(tab);
	ft_putstr("Error\n");
	return (1);
}

static int	ft_find_index(int *tab, int value, int size)
{
	int	index;
	int	res;

	index = 0;
	res = 0;
	while (index < size)
	{
		if (tab[index] < value)
			++res;
		++index;
	}
	return (res);
}

static int	*ft_transform_tab(int *tab, int size)
{
	int	index;
	int	*res;

	if (!tab)
		return (NULL);
	res = malloc(sizeof(*res) * size);
	if (!res)
	{
		free(tab);
		return (NULL);
	}
	index = 0;
	while (index < size)
	{
		res[index] = ft_find_index(tab, tab[index], size);
		++index;
	}
	free(tab);
	return (res);
}

static void	ft_set_ab(t_stack *a, t_stack *b, int size)
{
	a->size = size;
	a->r = 0;
	a->rr = 0;
	b->size = 0;
	b->r = 0;
	b->rr = 0;
}

int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac > 1)
	{
		a.arr = ft_parse_args(ac, av);
		a.arr = ft_transform_tab(a.arr, ac - 1);
		if (!a.arr)
			return (ft_error(NULL));
        b.arr = malloc(sizeof(*(b.arr)) * (ac - 1));
        if (!b.arr)
			return (ft_error(a.arr));
		ft_set_ab(&a, &b, ac - 1);
		// ft_display_stack(a);
		// ft_display_stack(b);
		ft_compute(&a, &b);
		// ft_display_stack(a);
		// ft_display_stack(b);
		free(b.arr);
		free(a.arr);
	}
	return (0);
}
