/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:20:48 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 09:20:48 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main( int ac, char **av ) {
	if (ac != 2) {
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return (1);
	}

	try {
		BitcoinExchange wallet;

		// wallet.display_database();
		wallet.read_file( av[1] );
	}
	catch ( std::exception &e ) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
