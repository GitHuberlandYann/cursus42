#include "push_swap.h"

void	ft_display_stack(t_stack stack)
{
	int	index;

	ft_printf("stack of size %d : ", stack.size);
	index = 0;
	while (index < stack.size)
	{
		ft_printf("%d ", stack.arr[index ++]);
	}
	ft_printf(" - r %d, rr %d\n", stack.r, stack.rr);
}

int	ft_stack_sorted(t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->size - 1)
	{
		if (stack->arr[index] > stack->arr[index + 1])
			return (0);
		++index;
	}
	return (1);
}
