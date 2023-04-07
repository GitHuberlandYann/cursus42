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
	std::string	arg = av[1];
	if (arg == "-c") {
		ScalarConverter::convert( "0" );
		std::cout << std::endl;
		ScalarConverter::convert( "*" );
		std::cout << std::endl;
		ScalarConverter::convert( "inf" );
		std::cout << std::endl;
		ScalarConverter::convert( "+inf" );
		std::cout << std::endl;
		ScalarConverter::convert( "0." );
		std::cout << std::endl;
		ScalarConverter::convert( "05" );
		std::cout << std::endl;
		ScalarConverter::convert( "-846f" );
		std::cout << std::endl;
		ScalarConverter::convert( "nan" );
		std::cout << std::endl;
		ScalarConverter::convert( "**" );
		std::cout << std::endl;
		ScalarConverter::convert( "\"" );
		std::cout << std::endl;
	} else {
		ScalarConverter::convert( av[1] );
	}
	return (0);
}
