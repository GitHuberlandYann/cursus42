/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:30:10 by marvin            #+#    #+#             */
/*   Updated: 2022/11/19 13:30:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	ft_fill_tab(int *tab, int nb, ...)
{
	int		index;
	va_list	ap;

	va_start(ap, nb);
	index = 0;
	while (index < nb)
		tab[index++] = va_arg(ap, int);
	va_end(ap);
}

static void	ft_set_hexa(t_hexa *hex)
{
	ft_fill_tab(hex->color_tab[0], 13, 0x3366, 0x336699, 0x3366cc, 0x3399, 0x99, 0xcc, 0x66, 0, 0, 0, 0, 0, 0);
	ft_fill_tab(hex->color_tab[1], 13, 0x6666, 0x6699, 0x99cc, 0x66cc, 0x33cc, 0xff, 0x3333ff, 0x333399, 0, 0, 0, 0, 0);
	ft_fill_tab(hex->color_tab[2], 13, 0x669999, 0x9999, 0x33cccc, 0xccff, 0x99ff, 0x66ff, 0x3366ff, 0x3333cc, 0x666699, 0, 0, 0, 0);
	ft_fill_tab(hex->color_tab[3], 13, 0x339966, 0xcc99, 0xffcc, 0xffff, 0x33ccff, 0x3399ff, 0x6699ff, 0x6666ff, 0x6600ff, 0x6600cc, 0, 0, 0);
	ft_fill_tab(hex->color_tab[4], 13, 0x339933, 0xcc66, 0xff99, 0x66ffcc, 0x66ffff, 0x66ccff, 0x99ccff, 0x9999ff, 0x9966ff, 0x9933ff, 0x9900ff, 0, 0);
	ft_fill_tab(hex->color_tab[5], 13, 0x6600, 0xcc00, 0xff00, 0x66ff99, 0x99ffcc, 0xccffff, 0xccccff, 0xcc99ff, 0xcc66ff, 0xcc33ff, 0xcc00ff, 0x9900cc, 0);
	ft_fill_tab(hex->color_tab[6], 13, 0x3300, 0x9933, 0x33cc33, 0x66ff66, 0x99ff99, 0xccffcc, 0xffffff, 0xffccff, 0xff99ff, 0xff66ff, 0xff00ff, 0xcc00cc, 0x660066);
	ft_fill_tab(hex->color_tab[7], 13, 0x336600, 0x9900, 0x66ff33, 0x99ff66, 0xccff99, 0xffffcc, 0xffcccc, 0xff99cc, 0xff66cc, 0xff33cc, 0xcc0099, 0x993399, 0);
	ft_fill_tab(hex->color_tab[8], 13, 0x333300, 0x669900, 0x99ff33, 0xccff66, 0xffff99, 0xffcc99, 0xff9999, 0xff6699, 0xff3399, 0xcc3399, 0x990099, 0, 0);
	ft_fill_tab(hex->color_tab[9], 13, 0x666633, 0x99cc00, 0xccff33, 0xffff66, 0xffcc66, 0xff9966, 0xff6666, 0xff0066, 0xcc6699, 0x993366, 0, 0, 0);
	ft_fill_tab(hex->color_tab[10], 13, 0x999966, 0xcccc00, 0xffff00, 0xffcc00, 0xff9933, 0xff6600, 0xff5050, 0xcc0066, 0x660033, 0, 0, 0, 0);
	ft_fill_tab(hex->color_tab[11], 13, 0x996633, 0xcc9900, 0xff9900, 0xcc6600, 0xff3300, 0xff0000, 0xcc0000, 0x990033, 0, 0, 0, 0, 0);
	ft_fill_tab(hex->color_tab[12], 13, 0x663300, 0x996600, 0xcc3300, 0x993300, 0x990000, 0x800000, 0x993333, 0, 0, 0, 0, 0, 0);
	hex->hexa_r = (float) (300 - 100) / (float) (13 * sqrt(3));
}

static void	ft_display_hexa(t_hexa *hex)
{
	int	index;
	int	sub_index;

	index = 0;
	while (index < 13)
	{
		sub_index = 0;
		while (sub_index < 13)
		{
			printf("%#x ", hex->color_tab[index][sub_index]);
			++sub_index;
		}
		printf("\n");
		++index;
	}
}

int	main(void)
{
	t_hexa	hex;

	ft_set_hexa(&hex);
	ft_display_hexa(&hex);
	printf("%f\n", hex.hexa_r);
	return (0);
}
