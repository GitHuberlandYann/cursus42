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
	else if(!ft_strcmp(str, "sb\n"))
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

static int	ft_exec_instruction(t_stack *a, t_stack *b, int ins)
{
	if (ins == SA && a->size < 2)
		return (1);
	else if (ins == SB && b->size < 2)
		return (1);
	else if (ins == SS && (a->size < 2 || b->size < 2))
		return (1);
	else if (ins == PA && b->size == 0)
		return (1);
	else if (ins == PB && a->size == 0)
		return (1);
	else if (ins == RA && a->size < 2)
		return (1);
	else if (ins == RB && b->size < 2)
		return (1);
	else if (ins == RR && (a->size < 2 || b->size < 2))
		return (1);
	else if (ins == RRA && a->size < 2)
		return (1);
	else if (ins == RRB && b->size < 2)
		return (1);
	else if (ins == RRR && (a->size < 2 || b->size < 2))
		return (1);
	ft_operation(a, b, ins);
	return (0);
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
		if (ft_exec_instruction(a, &b, ins_int))
			return (ft_free_return(b.arr));
		++index;
	}
	free(b.arr);
	return (0);
}
