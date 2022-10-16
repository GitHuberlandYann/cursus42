#include "ft_printf.h"

int	main(void)
{
	printf("original : %d\n", printf("%-10.6d", 100));
    printf("mine : %d\n", ft_printf("%-10.6d", 100));
	printf("original : %d\n", printf("%010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("mine : %d\n", ft_printf("%010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d, %010.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("original : %d\n", printf("%-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("mine : %d\n", ft_printf("%-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d, %-10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("original : %d\n", printf("%+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("mine : %d\n", ft_printf("%+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d, %+10.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));

    return (0);
}