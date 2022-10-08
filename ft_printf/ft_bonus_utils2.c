#include "ft_printf.h"

void	ft_printf_many_char(char c, int size, int *res)
{
	int	index;

	index = 0;
	while (index < size)
	{
		ft_printf_char(c, res);
		index ++;
	}
}

char	ft_get_type(const char *str, int index)
{
	while (str[index] && str[index] != 'c' && str[index] != 's'
		&& str[index] != 'p' && str[index] != 'd' && str[index] != 'i'
		&& str[index] != 'u' && str[index] != 'x' && str[index] != 'X'
		&& str[index] != '%')
		index ++;
	if (str[index])
		return (str[index]);
	return ('%'); // not supposed to happen
}

int	ft_len_arg(char c, int *spaces, va_list ap_cpy)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len = ft_nbrlen(va_arg(ap_cpy, int));
	else if (c == 'c')
		len = 1;
	else if (c == 's')
	{
		len = ft_strlen(va_arg(ap_cpy, char *));
		if (!len)
			(*spaces) -= 6;
	}
	else if (c == 'p')
	{
		if (va_arg(ap_cpy, void *) != (void *)0)
			(*spaces) -= 14;
		else
			(*spaces) -= 3;
	}
	else if (c == 'u')
		len = ft_unbrlen(va_arg(ap_cpy, unsigned int), 10);
	else if (c == 'x' || c == 'X')
		len = ft_unbrlen(va_arg(ap_cpy, unsigned int), 16);
	return (len);
}

int	ft_atoi_dotzero(const char *str, int index)
{
	int	res;

	index ++;
	res = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index ++;
	}
	return (res);
}
