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

static void	ft_do_test(t_stack *a, int nb);

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

static void	ft_fill_arr(t_stack *a, int nb, ...)
{
	int		index;
	va_list	ap;

	a->size = 0;
	a->arr = malloc(sizeof(*a->arr) * nb);
	if (!a->arr)
		return ;
	a->size = nb;
	va_start(ap, nb);
	index = 0;
	while (index < nb)
		a->arr[index++] = va_arg(ap, int);
	va_end(ap);
}

static void	ft_test_case(t_stack *a)
{
	t_stack b;

	b.arr = malloc(sizeof(*b.arr) * a->size);
	if (!b.arr)
		return ;
	b.size = 0;
	ft_sort_section_selection(a, &b, 20);
	free(b.arr);
}

int	main(void)
{
	int		nb;
	t_stack a;
	t_parse	*gnl;

	nb = 1;
	while (nb < 11)
	{
		ft_do_test(&a, nb);
		ft_printf("Test %d, arr size %d\n", nb, a.size);
		//ft_display_stack(a);
		close(1);
		open("Tester_/output_test", O_WRONLY);
		ft_test_case(&a);
		ft_putchar('\n');
		close(1);
		open("Tester_/output_test", O_RDONLY);
		gnl = ft_read_output();
		close(1);
		open("/dev/tty", O_WRONLY);
		//ft_display_stack(a);
		ft_printf("wc : %d\n", gnl->wc);
		ft_stack_sorted(&a) ? ft_putstr("SORTED\n") : ft_putstr("NOT SORTED\n");
		free(a.arr);
		ft_free_arr(gnl);
		++nb;
	}
	return (0);
}

static void	ft_do_test(t_stack *a, int nb)
{
	if (nb == 0)
		ft_fill_arr(a, 2, 2, 1);
	else if (nb == 1)
		ft_fill_arr(a, 3, 2, 1, 0);
	else if (nb == 2)
		ft_fill_arr(a, 4, 3, 2, 0, 1);
	else if (nb == 3)
		ft_fill_arr(a, 5, 4, 2, 3, 0, 1);
	else if (nb == 4)
		ft_fill_arr(a, 10, 1, 6, 0, 2, 7, 4, 8, 3, 9, 5);
	else if (nb == 5)
		ft_fill_arr(a, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	else if (nb == 6)
		ft_fill_arr(a, 20, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 18);
	else if (nb == 7)
		ft_fill_arr(a, 20, 5, 12, 3, 19, 1, 4, 16, 2, 7, 18, 15, 11, 10, 0, 9, 6, 17, 8, 14, 13);
	else if (nb == 8)
		ft_fill_arr(a, 100, 48, 83, 2, 13, 36, 17, 45, 15, 30, 1, 33, 44, 7, 25, 56, 27, 24, 32,
					96, 46, 43, 85, 66, 67, 31, 82, 57, 5, 21, 59, 9, 71, 76, 72, 3, 70, 87, 16,
					22, 93, 14, 61, 0, 8, 12, 55, 69, 28, 54, 47, 77, 94, 98, 18, 53, 88, 37, 40,
					23, 39, 81, 20, 6, 64, 10, 79, 19, 11, 38, 58, 42, 29, 34, 41, 52, 49, 4, 80,
					68, 62, 86, 90, 51, 26, 35, 92, 89, 74, 78, 95, 60, 73, 50, 91, 84, 63, 99, 97, 65, 75);
	else if (nb == 9)
		ft_fill_arr(a, 100, 23, 43, 96, 22, 55, 37, 65, 57, 88, 36, 87, 64, 34, 69, 49, 40, 42, 31,
					68, 29, 82, 74, 21, 81, 26, 16, 63, 61, 10, 73, 89, 78, 70, 53, 84, 99, 20, 91,
					3, 39, 75, 54, 86, 92, 93, 2, 97, 38, 24, 67, 35, 56, 85, 41, 4, 58, 12, 90, 62,
					45, 72, 19, 7, 94, 33, 25, 52, 77, 6, 48, 51, 76, 17, 8, 30, 98, 66, 95, 44, 60,
					13, 50, 14, 11, 83, 5, 71, 47, 28, 80, 59, 79, 15, 1, 0, 27, 32, 18, 9, 46);
	else if (nb == 10)
		ft_fill_arr(a, 200, 34, 64, 6, 80, 88, 79, 63, 3, 14, 58, 55, 67, 15, 56, 98, 20, 86, 52, 69,
					81, 17, 97, 16, 40, 65, 96, 89, 24, 99, 105, 74, 144, 117, 73, 2, 43, 118, 1, 29,
					12, 51, 124, 133, 109, 84, 30, 57, 139, 111, 121, 106, 155, 161, 192, 62, 162, 11,
					182, 154, 199, 33, 61, 35, 13, 188, 181, 184, 9, 49, 28, 95, 71, 175, 100, 136, 143,
					177, 45, 116, 101, 37, 26, 170, 110, 168, 172, 158, 4, 47, 114, 78, 156, 127, 31, 38,
					77, 171, 134, 146, 41, 94, 112, 102, 18, 66, 25, 53, 152, 191, 85, 194, 141, 92, 59,
					169, 120, 179, 193, 131, 48, 91, 8, 68, 60, 176, 129, 148, 173, 44, 183, 189, 83, 75,
					195, 159, 186, 119, 0, 167, 90, 142, 151, 125, 165, 87, 149, 39, 5, 50, 113, 32, 23,
					54, 163, 19, 27, 185, 42, 70, 76, 150, 36, 82, 46, 198, 72, 115, 22, 160, 153, 135,
					7, 123, 187, 126, 10, 196, 157, 197, 21, 128, 174, 104, 108, 190, 140, 107, 103, 132,
					147, 145, 180, 122, 164, 178, 138, 137, 130, 93, 166);

}