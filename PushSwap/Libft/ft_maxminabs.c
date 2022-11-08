/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxminabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:38:29 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/08 16:38:29 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
