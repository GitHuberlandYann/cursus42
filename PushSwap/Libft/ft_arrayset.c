/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:33:59 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/03 13:34:18 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_arrayset(int *tab, int value, int size)
{
	int	index;

	index = 0;
	while (index < size)
		tab[index++] = value;
}
