/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enigma.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:58:06 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/27 17:19:15 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issort(int *tab, int sizea)
{
	int	index;

	index = 0;
	while (index < sizea - 1)
	{
		if (tab[index] > tab[index + 1])
			return (0);
		++index;
	}
	return (1);
}

static void	ft_pushstack(int *dst, int *src, int *sizedst, int *sizesrc)
{
	int	index;

	index = *sizedst;
	//ft_printf("sizedst : %d, sizesrc : %d\n", *sizedst, *sizesrc);
	while (index > 0)
	{
		//ft_printf("index : %d\n", index);
		dst[index] = dst[index - 1];
		--index;
	}
	dst[0] = src[0];
	while (index < *sizesrc - 1)
	{
		//ft_printf("index bis : %d\n", index + 1);
		src[index] = src[index + 1];
		++index;
	}
	++(*sizedst);
	--(*sizesrc);
}

static void	ft_swap(int *tab, char *txt)
{
	int	save;

	ft_putstr(txt);
	save = tab[1];
	tab[1] = tab[0];
	tab[0] = save;
}

void	ft_compute(int *a, int *b, int *sizea, int *sizeb)
{
	if (ft_issort(a, *sizea) && *sizeb == 0)
		return ;
	if (*sizea > 1)
	{
		if (a[0] > a[1])
			ft_swap(a, "sa\n");
		else if (*sizeb > 1)
		{
			if (b[0] > b[1])
				ft_swap(b, "sb\n");
			else
				ft_putstr("Error in enigmab\n");
		} //	else if (*sizeb == 1 && b[0] > a[0])	rrrrraaaa;
		else if (*sizeb == 1)
		{
			ft_putstr("pa\n");
			ft_pushstack(a, b, sizea, sizeb);
		}
		else
		{
			ft_putstr("pb\n");
			ft_pushstack(b, a, sizeb, sizea);
		}
	}
	else if (*sizeb > 1)
	{
		if (b[0] > b[1])
			ft_swap(b, "sb\n");
		else
			ft_putstr("Error in enigmb\n");
	}
	else if (*sizeb == 1)
	{
		ft_putstr("pb\n");
		ft_pushstack(a, b, sizea, sizeb);
	}
	else
		ft_putstr("How did you get here\n");
	ft_compute(a, b, sizea, sizeb);
}
