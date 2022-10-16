#include "ft_printf.h"

void	ft_reset_parsing(t_parse *current)
{
	current->type = '\0';
	current->arglen = 0;
	current->int_copy = 0;
	current->space = 0;
	current->hashtag = 0;
	current->plus = 0;
	current->width = 0;
	current->minus = 0;
	current->zero = 0;
	current->precision = -1;
}

void	ft_parse_bonus2(const char *str, int start, int end, t_parse *current)
{
	while (start < end)
	{
		if (str[start] == ' ')
			current->space = 1;
		else if (str[start] == '#')
			current->hashtag = 1;
		else if (str[start] == '+')
			current->plus = 1;
		start ++;
	}
	if (current->plus)
		current->space = 0;
}

int	ft_check_minus(const char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] == '-')
			return (1);
		start ++;
	}
	return (0);
}

int	ft_check_zero(const char *str, int start, int end)
{
	while (start < end && str[start] != '.'
		&& !(str[start] >= '1' && str[start] <= '9'))
	{
		if (str[start] == '0')
			return (1);
    	start ++;
	}
	return (0);
}

int	ft_check_precision(const char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] == '.')
			return (1);
		start ++;
	}
	return (0);
}