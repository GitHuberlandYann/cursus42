#include "push_swap.h"

static int	ft_get_cost(t_stack *a, t_stack *b, int value, int indexb)
{
	int	rota;
	int	rotb;

	rota = ft_get_place_insert(a, value);
	if (rota > a->size / 2)
		rota -= a->size;
	if (indexb <= b->size / 2)
		rotb = indexb;
	else
		rotb = indexb - b->size;
	if (rota >= 0 && rotb >= 0)
		return (ft_max(rota, rotb));
	else if (rota < 0 && rotb < 0)
		return (-ft_min(rota, rotb));
	else if (rota >= 0 && rotb < 0)
		return (rota - rotb);
	else
		return (rotb - rota);
}

static int	ft_find_cheapest(t_stack *a, t_stack *b)
{
	int	index;
	int	tmp_cost;
	int	res;
	int	res_cost;

	res = b->arr[0];
	res_cost = ft_get_cost(a, b, res, 0);
	index = 1;
	while (index < b->size)
	{
		tmp_cost = ft_get_cost(a, b, b->arr[index], index);
		if (tmp_cost < res_cost)
		{
			res = b->arr[index];
			res_cost = tmp_cost;
		}
		++index;
	}
	return (res);
}

static void	ft_put_ontop(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->arr[index] != value)
		++index;
	while (stack->arr[0] != value)
	{
		if (index <= stack->size / 2)
			ft_operation(stack, NULL, R);
		else
			ft_operation(stack, NULL, RR);
	}
}

static void	ft_insert_back(t_stack *a, t_stack *b)
{
	int	value_to_insert;
	int	place_to_insert;

	while (b->size)
	{
		value_to_insert = ft_find_cheapest(a, b);
		ft_put_ontop(b, value_to_insert);
		place_to_insert = ft_get_place_insert(a, value_to_insert);
		if (place_to_insert < 0)
			place_to_insert += a->size;
		ft_put_ontop(a, a->arr[place_to_insert]);
		ft_exec_push(a, b, "pa\n");
	}
}

void	ft_sort_big(t_stack *a, t_stack *b)
{
	t_stack *lis;

	(void)b;
	lis = ft_longest_subseq(a);
	if (!lis)
		return ;
	// ft_putstr("\nLIS -> ");
	// ft_display_stack(*lis);
	ft_push_unwanted(a, b, lis);
	free(lis->arr);
	free(lis);
	ft_insert_back(a, b);
	ft_put_ontop(a, 0);
	ft_exec_push(a, b, ""); //print rotations and swaps left
}
