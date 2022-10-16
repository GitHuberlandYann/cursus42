#include "ft_printf.h"

int	main(void)
{
	printf("original : %d\n", printf("%.10x", 5));
    printf("mine : %d\n", ft_printf("%.10x", 5));
    return (0);
}