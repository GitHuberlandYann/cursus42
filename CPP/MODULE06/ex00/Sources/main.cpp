/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:31:09 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/04 09:31:09 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main( int ac, char **av ) {
	if (ac != 2) {
		std::cout << "Usage: ./convert <string>" << std::endl;
		return (1);
	}
	std::cout << av[1] << std::endl;
	return (0);
}
