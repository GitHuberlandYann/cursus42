/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:27:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/12 11:27:44 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <list>

template <typename T>
void	test( T const & container, int const nb, std::string str ) {
	std::cout << "Test with " << nb << ":\t\t";
	try {
		int res = easyfind( container, nb );
		std::cout << res << " is in " << str << std::endl;
	}
	catch ( std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main( void ) {
	std::cout << "\t-------TEST WITH VECTOR-------" << std::endl << "\t\t";
	std::vector<int> v;
	for ( int i = 1; i < 6; i++ ) {
		v.push_back(i);
		std::cout << i << " ";
	}
	std::cout << std::endl;

	test( v, 2, "vector" );
	test( v, 4, "vector" );
	test( v, 9, "vector" );
	test( v, -8, "vector" );
	
	std::cout << std::endl << "\t-------TEST WITH LIST-------" << std::endl << "\t\t";
	std::list<int> l;
	for ( int i = 1; i < 6; i++ ) {
		l.push_back(i);
		std::cout << i << " ";
	}
	std::cout << std::endl;

	test( l, 2, "list" );
	test( l, 4, "list" );
	test( l, 9, "list" );
	test( l, -8, "list" );
	return (0);
}
