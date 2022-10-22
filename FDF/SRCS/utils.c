/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:19:29 by marvin            #+#    #+#             */
/*   Updated: 2022/10/22 15:19:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_lst_content(t_list *lst)
{
	while (lst)
	{
		ft_printf("lstc : %s", lst->content);
		lst = lst->next;
	}
}

void	ft_display_map_content(t_map *res)
{
	int	row;
	int	column;

	//ft_printf("map size : %d, row size : %d\n", res->maplen, res->rowlen);
	row = 0;
	while (row < res->maplen)
	{
		column = 0;
		while (column < res->rowlen)
		{
			ft_putchars(' ', 5 - ft_nbrlen(res->map[row][column]));
			ft_putnbr(res->map[row][column]);
			++column;
		}
		ft_putchar('\n');
		++row;
	}
}
