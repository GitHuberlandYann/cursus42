/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:44:08 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 17:44:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_free_return(int *tab)
{
	free(tab);
	return (1);
}

static int	ft_strtoi(char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		return (SA);
	else if (!ft_strcmp(str, "sb\n"))
		return (SB);
	else if (!ft_strcmp(str, "ss\n"))
		return (SS);
	else if (!ft_strcmp(str, "pa\n"))
		return (PA);
	else if (!ft_strcmp(str, "pb\n"))
		return (PB);
	else if (!ft_strcmp(str, "ra\n"))
		return (RA);
	else if (!ft_strcmp(str, "rb\n"))
		return (RB);
	else if (!ft_strcmp(str, "rr\n"))
		return (RR);
	else if (!ft_strcmp(str, "rra\n"))
		return (RRA);
	else if (!ft_strcmp(str, "rrb\n"))
		return (RRB);
	else if (!ft_strcmp(str, "rrr\n"))
		return (RRR);
	return (-1);
}

static void	ft_exec_double(t_stack *a, t_stack *b, int ins)
{
	if (a->size < 2 && b->size < 2)
		return ;
	if (ins == SS)
	{
		if (a->size >= 2)
			ft_operation(a, b, SA);
		if (b->size >= 2)
			ft_operation(a, b, SB);
	}
	else if (ins == RR)
	{
		if (a->size >= 2)
			ft_operation(a, b, RA);
		if (b->size >= 2)
			ft_operation(a, b, RB);
	}
	else if (ins == RRR)
	{
		if (a->size >= 2)
			ft_operation(a, b, RRA);
		if (b->size >= 2)
			ft_operation(a, b, RRB);
	}
}

static void	ft_exec_instruction(t_stack *a, t_stack *b, int ins)
{
	if (ins == SS || ins == RR || ins == RRR)
		ft_exec_double(a, b, ins);
	else if (ins == SA && a->size < 2)
		return ;
	else if (ins == SB && b->size < 2)
		return ;
	else if (ins == PA && b->size == 0)
		return ;
	else if (ins == PB && a->size == 0)
		return ;
	else if (ins == RA && a->size < 2)
		return ;
	else if (ins == RB && b->size < 2)
		return ;
	else if (ins == RRA && a->size < 2)
		return ;
	else if (ins == RRB && b->size < 2)
		return ;
	ft_operation(a, b, ins);
}

int	ft_exec_instructions(t_stack *a, char **ins)
{
	int		index;
	int		ins_int;
	t_stack	b;

	b.size = 0;
	b.arr = malloc(sizeof(*b.arr) * a->size);
	if (!b.arr)
		return (1);
	index = 0;
	while (ins[index])
	{
		ins_int = ft_strtoi(ins[index]);
		if (ins_int == -1)
			return (ft_free_return(b.arr));
		ft_exec_instruction(a, &b, ins_int);
		++index;
	}
	free(b.arr);
	return (0);
}
