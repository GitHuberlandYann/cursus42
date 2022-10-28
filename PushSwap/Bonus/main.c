/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:47:47 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 15:47:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_free_arr(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

static int	ft_error(int *tab, char **arr)
{
	free(tab);
	if (arr)
		ft_free_arr(arr);
	write(2, "Error\n", 6);
	return (1);
}

static int	ft_stack_sorted(t_stack stack)
{
	int	index;

	index = 0;
	while (index < stack.size - 1)
	{
		if (stack.arr[index] > stack.arr[index + 1])
			return (0);
		++index;
	}
	return (1);
}

// static void	deletethis_display(char **arr)
// {
// 	int	index;

// 	index = 0;
// 	while (arr[index])
// 		ft_putstr(arr[index++]);
// }

int	main(int ac, char **av)
{
	t_stack stack;
	char	**instructions;

	if (ac > 1)
	{
		stack.arr = ft_parse_args(ac, av);
		if (!stack.arr)
			return (ft_error(0, 0));
		stack.size = ac - 1;
		instructions = ft_read_input();
		if (!instructions)
			return (ft_error(stack.arr, 0));
		// deletethis_display(instructions);
		if (ft_exec_instructions(&stack, instructions))
			return (ft_error(stack.arr, instructions));
		//ft_printf("a.size : %d, ac : %d, a.arr[0] : %d\n", stack.size, ac, stack.arr[0]);
		if (stack.size == ac - 1 && ft_stack_sorted(stack))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		free(stack.arr);
		ft_free_arr(instructions);
	}
	else
		return (ft_error(0, 0));
	return (0);
}
