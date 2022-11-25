/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:30:51 by lolemmen          #+#    #+#             */
/*   Updated: 2022/05/02 11:28:33 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fb_printf_bonus.h"
#include "limits.h"
#include "stdlib.h"
#include <stdio.h>

#define PRINT ft_printf

int	main(void)
{
	char c = 'b';
	char *str = "Bonjour";
	void *voider = "Bonjour";
	void *nullpointer = NULL;
	char *nullstr = NULL;
	unsigned int nbr = 123;

	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("1 : %-05%\n"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("1 : %-05%\n"));/*
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("2 : %15%\n"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("2 : %15%\n"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("3 : %-10.5x\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("3 : %-10.5x\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("4 : %-10.5X\n", 42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("4 : %-10.5X\n", 42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("5 : %-10.5u\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("5 : %-10.5u\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("6 : %-10.5i\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("6 : %-10.5i\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("7 : % 10.5d\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("7 : % 10.5d\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("8 : %-+10.5d\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("8 : %-+10.5d\n", -42));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("9 : %15p\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("9 : %15p\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("10 : %-15.5s\n", str));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("10 : %-15.5s\n", str));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("11 : %-15c\n", c));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("11 : %-15c\n", c));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("NULL char : %c\n", '\0'));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("NULL char : %c\n", '\0'));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("NULL str : %s\n", nullstr));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("NULL str : %s\n", nullstr));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("NULL nb : %d\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("NULL nb : %d\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("NULL pointer : {%4.p}\n", nullpointer));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("NULL pointer : {%4.p}\n", nullpointer));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("NULL hexa : %x\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("NULL hexa : %x\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("NULL HEXA : %X\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("NULL HEXA : %X\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("NULL uint : %u\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("NULL uint : %u\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("MIX : %c, %s, %d, %i, %x, %X, %p, %u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("MIX : %c, %s, %d, %i, %x, %X, %p, %u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("MIX with flags : %-12c, %5s, % d, %+i, %#x, %#12X, %20p, %.5u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("MIX with flags : %-12c, %5s, % d, %+i, %#x, %#12X, %20p, %.5u\n", c, str, -42, 42, 1234, -1234, voider, -1234));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.d}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.d}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.x}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.x}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.s}\n", "42"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.s}\n", "42"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%4.s}\n", "42"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%4.s}\n", "42"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.p}\n", (void *)0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.p}\n", (void *)0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.d}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.d}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.0d}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.0d}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.0x}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.0x}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.0u}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.0u}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("null dot : {%.u}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("null dot : {%.u}\n", 0));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%146.146s}\n" ,NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%146.146s}\n" ,NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("% # + 0-114.174%\n"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("% # + 0-114.174%\n"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("% # + -151.315%\n"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("% # + -151.315%\n"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("%-91.78X\n%-85.50X\n%-195.180i\n" ,597874775u,2208405511u,1625226049));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("%-91.78X\n%-85.50X\n%-195.180i\n" ,597874775u,2208405511u,1625226049));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("%--87.18d%180p%-130.84u" ,213284615,(void*)12365356750099397136lu,3648680271u));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("%--87.18d%180p%-130.84u" ,213284615,(void*)12365356750099397136lu,3648680271u));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%3.1s}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%3.1s}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("%.s\n", "hello"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("%.s\n", "hello"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%4.3s}\n{%-7.4s}\n", "hello", "world"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%4.3s}\n{%-7.4s}\n", "hello", "world"));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("%0093.u\n", nbr));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("%0093.u\n", nbr));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%0025.d}\n" ,1910242786));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%0025.d}\n" ,1910242786));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%00169.d}\n" ,-513924419));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%00169.d}\n" ,-513924419));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%015p}\n", 1234));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%015p}\n", 1234));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%021s}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%021s}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%--187p}\n" ,(void*)5092148362367175078lu));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%--187p}\n" ,(void*)5092148362367175078lu));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%015p}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%015p}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%-15.5d}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%-15.5d}\n", NULL));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", ft_printf("{%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d}\n", -42, 615, 0, 64, -464, +6464, -6412156, 3215644));
	printf("\t\t\t^^^^^^^^^^^^^^^^^^%d^^^^^^^^^^^^^^^^^\n\n", printf("{%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d}\n", -42, 615, 0, 64, -464, +6464, -6412156, 3215644));
	
	int		a = -4;
	int		b = 0;
	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	PRINT(" --- Return : %d\n", PRINT("Simple input test"));
	PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	PRINT(" --- Return : %d\n", PRINT("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
	PRINT(" --- Return : %d\n", PRINT("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); //T4
	PRINT(" --- Return : %d\n", PRINT("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
	PRINT(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
	PRINT(" --- Return : %d\n", PRINT("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
	PRINT(" --- Return : %d\n", PRINT("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8
	PRINT(" --- Return : %d\n", PRINT("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d)); //T9
	PRINT(" --- Return : %d\n", PRINT("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d)); //T10
	PRINT(" --- Return : %d\n", PRINT("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d)); //T11
	PRINT(" --- Return : %d\n", PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	PRINT(" --- Return : %d\n", PRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d)); //T13
	PRINT(" --- Return : %d\n", PRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d)); //T14
	PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T15
	PRINT(" --- Return : %d\n", PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	PRINT(" --- Return : %d\n", PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
	PRINT(" --- Return : %d\n", PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
	PRINT(" --- Return : %d\n", PRINT("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T19
	PRINT(" --- Return : %d\n", PRINT("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c, e, d)); //T20
	PRINT(" --- Return : %d\n", PRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c, e, d)); //T21
	PRINT(" --- Return : %d\n", PRINT("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c, e, d)); //T22
	PRINT(" --- Return : %d\n", PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
	PRINT(" --- Return : %d\n", PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
	PRINT(" --- Return : %d\n", PRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c, e, d)); //T25
	PRINT(" --- Return : %d\n", PRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T26
	PRINT(" --- Return : %d\n", PRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c, e, d)); //T27
	PRINT(" --- Return : %d\n", PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T28
	PRINT(" --- Return : %d\n", PRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c, e, d)); //T29
	PRINT(" --- Return : %d\n", PRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
	PRINT(" --- Return : %d\n", PRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
	PRINT(" --- Return : %d\n", PRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
	PRINT(" --- Return : %d\n", PRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33
	PRINT(" --- Return : %d\n", PRINT("%12.12i, %12.12d", -42, 42)); //T179
	PRINT(" --- Return : %d\n", PRINT("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
	PRINT(" --- Return : %d\n", PRINT("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
	PRINT(" --- Return : %d\n", PRINT("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
	PRINT(" --- Return : %d\n", PRINT("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
	PRINT(" --- Return : %d\n", PRINT("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
	PRINT(" --- Return : %d\n", PRINT("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
	PRINT(" --- Return : %d\n", PRINT("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r)); //T186
	PRINT(" --- Return : %d\n", PRINT("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r)); //T186
	PRINT(" --- Return : %d\n", PRINT("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r)); //T186
	PRINT(" --- Return : %d\n", PRINT("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
	PRINT(" --- Return : %d\n", PRINT("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
	// ^ Theoriquement un comportement indefini mais testé par la moulinette
    PRINT(" --- Return : %d\n", PRINT("(null)"));
	PRINT(" --- Return : %d\n", PRINT(""));

	#define PRINT printf
	PRINT(" --- Return : %d\n", PRINT("Simple input test"));
	PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	PRINT(" --- Return : %d\n", PRINT("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
	PRINT(" --- Return : %d\n", PRINT("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); //T4
	PRINT(" --- Return : %d\n", PRINT("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
	PRINT(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
	PRINT(" --- Return : %d\n", PRINT("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
	PRINT(" --- Return : %d\n", PRINT("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8
	PRINT(" --- Return : %d\n", PRINT("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d)); //T9
	PRINT(" --- Return : %d\n", PRINT("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d)); //T10
	PRINT(" --- Return : %d\n", PRINT("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d)); //T11
	PRINT(" --- Return : %d\n", PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	PRINT(" --- Return : %d\n", PRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d)); //T13
	PRINT(" --- Return : %d\n", PRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d)); //T14
	PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T15
	PRINT(" --- Return : %d\n", PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	PRINT(" --- Return : %d\n", PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
	PRINT(" --- Return : %d\n", PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
	PRINT(" --- Return : %d\n", PRINT("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T19
	PRINT(" --- Return : %d\n", PRINT("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c, e, d)); //T20
	PRINT(" --- Return : %d\n", PRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c, e, d)); //T21
	PRINT(" --- Return : %d\n", PRINT("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c, e, d)); //T22
	PRINT(" --- Return : %d\n", PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
	PRINT(" --- Return : %d\n", PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
	PRINT(" --- Return : %d\n", PRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c, e, d)); //T25
	PRINT(" --- Return : %d\n", PRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T26
	PRINT(" --- Return : %d\n", PRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c, e, d)); //T27
	PRINT(" --- Return : %d\n", PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T28
	PRINT(" --- Return : %d\n", PRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c, e, d)); //T29
	PRINT(" --- Return : %d\n", PRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
	PRINT(" --- Return : %d\n", PRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
	PRINT(" --- Return : %d\n", PRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
	PRINT(" --- Return : %d\n", PRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33
	PRINT(" --- Return : %d\n", PRINT("%12.12i, %12.12d", -42, 42)); //T179
	PRINT(" --- Return : %d\n", PRINT("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
	PRINT(" --- Return : %d\n", PRINT("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
	PRINT(" --- Return : %d\n", PRINT("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
	PRINT(" --- Return : %d\n", PRINT("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
	PRINT(" --- Return : %d\n", PRINT("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
	PRINT(" --- Return : %d\n", PRINT("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
	PRINT(" --- Return : %d\n", PRINT("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r)); //T186
	PRINT(" --- Return : %d\n", PRINT("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r)); //T186
	PRINT(" --- Return : %d\n", PRINT("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r)); //T186
	PRINT(" --- Return : %d\n", PRINT("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
	PRINT(" --- Return : %d\n", PRINT("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
	// ^ Theoriquement un comportement indefini mais testé par la moulinette
    PRINT(" --- Return : %d\n", PRINT("(null)"));
	PRINT(" --- Return : %d\n", PRINT(""));*/
	return (0);
}