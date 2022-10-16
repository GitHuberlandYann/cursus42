#include "ft_printf.h"

int	ft_max(int len, int prec)
{
	if (len > prec)
		return (len);
	return (prec);
}

int	ft_min(int len, int prec)
{
	if (len < prec && prec != -1)
		return (len);
	return (prec);
}

int	ft_count_front_spaces(t_parse *current)
{
    int	res;

	res = current->width;
	if (current->type == 'd')
	{
		res -= current->space && (current->int_copy >= 0);
		res -= current->plus && (current->int_copy >= 0);
		current->precision += (current->int_copy < 0);
	}
	else if (current->type == 'x' || current->type == 'X')
		res -= 2 * (current->hashtag && current->int_copy);
	if (current->type != 's')
		res -= ft_max(current->arglen, current->precision);
	else
		res -= ft_min(current->arglen, current->precision);
	return (res);
}

int	ft_count_zeros(t_parse *current)
{
	int	res;

	if (current->type == 's')
		return (0);
	res = current->zero;
	if (current->precision != -1)
		res += current->precision;
	res -= current->arglen;
	return (res);
}

int	ft_count_back_spaces(t_parse *current)
{
	int	res;

	res = current->minus;
	if (current->type == 'd')
	{
		res -= current->space && (current->int_copy >= 0);
		res -= current->plus && (current->int_copy >= 0);
		current->precision += (current->int_copy < 0);
	}
	else if (current->type == 'x' || current->type == 'X')
		res -= 2 * (current->hashtag && current->int_copy);
	if (current->type != 's')
		res -= ft_max(current->arglen, current->precision);
	else
		res -= ft_min(current->arglen, current->precision);
	if (current->type == 'd')
		res += (current->int_copy < 0);
	return (res);
}
