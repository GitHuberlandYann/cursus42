/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:49:24 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 13:49:24 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int ac, char **av ) {
	if (ac == 1) {
		std::cout << "Usage: ./PmergeMe <int+>" << std::endl;
		return (1);
	}
	try {
		parse_inputs( av );
		std::cout << "Before: ";
		for (int index = 1; av[index]; index++) {
			std::cout << av[index] << ' ';
		}
		std::cout << std::endl;
		merge_insert_vector( av );
		merge_insert_deque( av );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
