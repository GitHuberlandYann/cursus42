/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:40:05 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/06 14:40:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_tester(int ac, ...)
{
	va_list ap;

	va_start(ap, ac);
	printf("%s, ", va_arg(ap, char *));
	for (int i = 0; i < ac - 1; i ++)
		printf("%d, ", va_arg(ap, int));
	printf("\n");
	va_end(ap);
}
#include <limits.h>
int	main(int argc, char **argv)
{
	int		a = 14;

	(void) argc;
	(void) argv;
	printf("original : %d\n", printf("%3c", 'd'));
	printf("mine : %d\n", ft_printf("%3c", 'd'));
	printf("cmp : %d\n", printf("%c\n", '0') == ft_printf("%c\n", '0'));
	printf("\nthe number is %1d", a);
	printf("\nthe number is %2d", a);
	printf("\nthe number is %6d", a);
	printf("\nthe number is %7d", a);
	return (0);
}
