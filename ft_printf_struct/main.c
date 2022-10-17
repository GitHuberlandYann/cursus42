/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:34:15 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/17 13:34:15 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("original : %d\n", printf("^.^/%0#48x^.^/", -1351230320));
	printf("mine : %d\n", ft_printf("^.^/%0#48x^.^/", -1351230320));
	printf("original : %d\n", printf("\x01\x02\x07\v\x08\f\r\n"));
    printf("mine : %d\n", ft_printf("\x01\x02\x07\v\x08\f\r\n"));
	/*printf("original : %d\n", printf("%010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("mine : %d\n", ft_printf("%010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("original : %d\n", printf("%-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("mine : %d\n", ft_printf("%-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("original : %d\n", printf("%+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("mine : %d\n", ft_printf("%+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));*/
	

	return (0);
}