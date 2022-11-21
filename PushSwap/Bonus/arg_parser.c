/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:52:45 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 15:52:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	*ft_free_return(int *tab, char **split)
{
	int	index;

	free(tab);
	if (split)
	{
		index = 0;
		while (split[index])
			free(split[index++]);
		free(split);
	}
	return (0);
}

static int	ft_check_arg(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
		{
			if ((str[index] != '-' && str[index] != '+') || index > 0
				|| !str[index + 1])
				return (1);
		}
		++index;
	}
	return (index == 0);
}

static int	ft_duplicate(int *tab, int value, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (tab[index] == value)
			return (1);
		++index;
	}
	return (0);
}

static int	*ft_parse_split(char *str, int *ac)
{
	int		index;
	long	buf;
	char	**av;
	int		*res;

	av = ft_split(str, ' ');
	if (!av)
		return (NULL);
	*ac = ft_arraylen(av) + 1;
	res = malloc(sizeof(*res) * (*ac - 1));
	if (!res)
		return (NULL);
	index = 0;
	while (index < *ac - 1)
	{
		if (ft_check_arg(av[index]))
			return (ft_free_return(res, av));
		buf = ft_atoi(av[index]);
		if (buf > INT_MAX || buf < INT_MIN || ft_duplicate(res, buf, index))
			return (ft_free_return(res, av));
		res[index++] = buf;
	}
	ft_free_return(NULL, av);
	return (res);
}

int	*ft_parse_args(int *ac, char **av)
{
	int		index;
	int		*res;
	long	buf;

	if (*ac == 2 && ft_check_arg(av[1]))
		return (ft_parse_split(av[1], ac));
	res = malloc(sizeof(*res) * (*ac - 1));
	if (!res)
		return (NULL);
	index = 1;
	while (index < *ac)
	{
		if (ft_check_arg(av[index]))
			return (ft_free_return(res, NULL));
		buf = ft_atoi(av[index]);
		if (buf > INT_MAX || buf < INT_MIN || ft_duplicate(res, buf, index - 1))
			return (ft_free_return(res, NULL));
		res[index - 1] = buf;
		++index;
	}
	return (res);
}
