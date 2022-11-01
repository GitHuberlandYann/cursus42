#include "push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	int	index;
	int	save;

	index = 0;
	save = stack->arr[index];
	while (index < stack->size - 1)
	{
		stack->arr[index] = stack->arr[index + 1];
		++index;
	}
	stack->arr[index] = save;
}

static void	ft_rrotate(t_stack *stack)
{
	int	index;
	int	save;

	index = stack->size - 1;
	save = stack->arr[index];
	while (index > 0)
	{
		stack->arr[index] = stack->arr[index - 1];
		--index;
	}
	stack->arr[index] = save;
}

static void	ft_push(t_stack *dst, t_stack *src)
{
	int	index;

	index = dst->size;
	while (index > 0)
	{
		dst->arr[index] = dst->arr[index - 1];
		--index;
	}
	dst->arr[0] = src->arr[0];
	while (index < src->size - 1)
	{
		src->arr[index] = src->arr[index + 1];
		++index;
	}
	++(dst->size);
	--(src->size);
}

static void	ft_swap(int *tab)
{
	int	save;

	save = tab[1];
	tab[1] = tab[0];
	tab[0] = save;
}

void	ft_operation(t_stack *main, t_stack *other, int ope)
{
	if (ope == S)
		ft_swap(main->arr);
	else if (ope == P)
		ft_push(main, other);
	else if (ope == R)
	{
		ft_rotate(main);
		++main->r;
	}
	else if (ope == RR)
	{
		ft_rrotate(main);
		++main->rr;
	}
}
