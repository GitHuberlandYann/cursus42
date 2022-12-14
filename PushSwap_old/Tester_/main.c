/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:59:19 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 09:59:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	ft_free_arr(t_parse *gnl)
{
	int	index;

	index = 0;
	if (gnl->arr)
	{
		while (gnl->arr[index])
			free(gnl->arr[index++]);
		free(gnl->arr);
	}
	free(gnl);
}

static int	ft_test_small(void)
{
	int		test_nb;
	int		total;
	t_stack	a;
	t_parse	*gnl;

	test_nb = 0;
	total = 0;
	while (!ft_load_test_small(&a, test_nb))
	{
		ft_printf("Test %d\n", test_nb);
		ft_printf("\tarr size %d\t", a.size);
		ft_display_stack(a);
		close(1);
		open("Tester_/output_test", O_WRONLY);
		ft_test_case_small(&a);
		ft_putchar('\n');
		close(1);
		open("Tester_/output_test", O_RDONLY);
		gnl = ft_read_output();
		close(1);
		open("/dev/tty", O_WRONLY);
		ft_printf("\twc : %d\n\t", gnl->wc);
		total += gnl->wc;
		ft_stack_sorted(&a) ? ft_putstr("SORTED\n") : ft_putstr("NOT SORTED\n");
		free(a.arr);
		ft_free_arr(gnl);
		++test_nb;
	}
	ft_printf("Total operations : %d\n", total);
	return (0);
}

static int	ft_test_big(void)
{
	int		test_nb;
	int		total;
	int		section;
	t_stack a;
	t_parse	*gnl;

	test_nb = 1;
	total = 0;
	section = 20;
	ft_printf("Test %d\n", test_nb);
	while (!ft_load_test_big(&a, test_nb))
	{
		ft_printf("\tarr size %d, section size %d\n", a.size, section);
		close(1);
		open("Tester_/output_test", O_WRONLY);
		ft_test_case(&a, section);
		ft_putchar('\n');
		close(1);
		open("Tester_/output_test", O_RDONLY);
		gnl = ft_read_output();
		close(1);
		open("/dev/tty", O_WRONLY);
		ft_printf("\twc : %d\n\t", gnl->wc);
		total += gnl->wc;
		ft_stack_sorted(&a) ? ft_putstr("SORTED\n") : ft_putstr("NOT SORTED\n");
		free(a.arr);
		ft_free_arr(gnl);
		if (section < 60 && section < a.size)
			section += 5;
		else
		{
			section = 20;
			++test_nb;
			ft_printf("\nTest %d\n", test_nb);
		}
	}
	ft_printf("Total operations : %d\n", total);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "big"))
			return (ft_test_big());
		else if (!ft_strcmp(av[1], "small"))
			return (ft_test_small());
		else
			ft_putstr("Arguments supported are 'big' and 'small'.\n");
	}
	else
		ft_putstr("Program needs 1 argument.\n");
	return (0);
}
