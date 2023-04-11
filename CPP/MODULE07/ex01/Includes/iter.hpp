/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:24:03 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/11 09:24:03 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Function>
void iter( T array[], int lenght, Function fun ) {
	for (int i = 0; i < lenght; i++) {
		fun(array[i]);
	}
}

#endif
