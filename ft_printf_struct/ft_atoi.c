#include "ft_printf.h"

int	ft_atoi(const char *str, int index, int end)
{
	int	res;

	res = 0;
	while (index < end && str[index] != '.'
		&& !(str[index] >= '1' && str[index] <= '9'))
		index ++;
	while (str[index] >= '0' && str[index] <= '9')
		res = res * 10 + str[index++] - '0';
	return (res);	
}

int	ft_atoi_precision(const char *str, int index, int end)
{
	while (str[index] != '.')
		index ++;
	return (ft_atoi(str, index + 1, end));
}
