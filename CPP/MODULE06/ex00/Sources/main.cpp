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

void	test( std::string str ) {
	std::cout << "\t-----------Test with " << str << "-----------" << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;
}

int	main( int ac, char **av ) {
	if (ac != 2) {
		std::cout << "Usage: ./convert <string>" << std::endl;
		return (1);
	}
	std::string	arg = av[1];
	if (arg == "-c") {
		test( "0" );
		test( "*" );
		test( "inf" );
		test( "+inf" );
		test( "0." );
		test( "05" );
		test( "2 5" );
		test( "-846f" );
		test( "nan" );
		test( "**" );
		test( "\"" );
		test( "2147483648" );
		test( "2147483648.0f" );
		test( "2147483648.0" );
	} else {
		test( av[1] );
	}
	return (0);
}
