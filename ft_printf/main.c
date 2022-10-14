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
	(void) argc;
	(void) argv;
	//printf("%p\n", (void *)0xdeadc0de);
	//ft_printf("%p\n", (void *)0xdeadc0de);
	printf("original : %d\n", printf("%0014.1i", (int)-2147483648));
	printf("mine : %d\n", ft_printf("%0014.1i", (int)-2147483648));
	printf("original : %d\n", printf("%42X", 1));
	printf("mine : %d\n", ft_printf("%42X", 1));
	printf("original : %d\n", printf("%42.5x", -1));
	printf("mine : %d\n", ft_printf("%42.5x", -1));
	printf("original : %d\n", printf("%01.0d", 4));
	printf("mine : %d\n", ft_printf("%01.0d", 4));
	//printf("mine : %d\n", ft_printf("%.2d", -1));
	//printf("original : %d\n", printf("%%%%%%%%%%%%%%%%%"));
	//printf("mine : %d\n", ft_printf("%%%%%%%%%%%%%%%%%"));
	printf("original : %d\n", printf("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us"));
	printf("mine : %d\n", ft_printf("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us"));
	return (0);
}
