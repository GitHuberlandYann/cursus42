/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_cntset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:32:07 by yhuberla          #+#    #+#             */
/*   Updated: 2023/02/01 10:40:10 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr_cntset(char *str, char *targets)
{
	int	res;
	int	index;
	int	sub_index;

	if (!str)
		return (0);
	res = 0;
	index = 0;
	while (str[index])
	{
		sub_index = 0;
		while (targets[sub_index])
		{
			res += (str[index] == targets[sub_index]);
			++sub_index;
		}
		++index;
	}
	return (res);
}
