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
	//printf("original : %d\n", printf(" % s", "test"));
	//printf("mine : %d\n", ft_printf(" % s", "test"));
	//printf("mine : %d\n", ft_printf("%.2d", -1));
	//printf("original : %d\n", printf("%%%%%%%%%%%%%%%%%"));
	//printf("mine : %d\n", ft_printf("%%%%%%%%%%%%%%%%%"));
	printf("original : %d\n", printf("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us"));
	printf("mine : %d\n", ft_printf("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us"));
	/*printf("string : %d\n", printf("%.10s", "Hi there"));
	printf("decimal : %d\n", printf("%.12d", 32));
	printf("int : %d\n", printf("%.12i", 32));
	printf("unsigned : %d\n", printf("%.12u", 32));
	printf("hexa low : %d\n", printf("%.12x", 32));
	printf("hexa up : %d\n", printf("%.12X", 32));
	printf("\nmine original : %d\n", printf("%.3s", "Hi there"));
	printf("mine string : %d\n", printf("%.10s", "Hi there"));
	printf("mine decimal : %d\n", printf("%.12d", 32));
	printf("mine int : %d\n", printf("%.12i", 32));
	printf("mine unsigned : %d\n", printf("%.12u", 32));
	printf("mine hexa low : %d\n", printf("%.12x", 32));
	printf("mine hexa up : %d\n", printf("%.12X", 32));*/
	//printf("cmp : %d\n", printf("%c\n", '0') == ft_printf("%c\n", '0'));
	return (0);
}
