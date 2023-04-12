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

int	main( void ) {
	std::vector<int> v;
	for ( int i = 1; i < 6; i++ ) {
		v.push_back(i);
	}

	try {
		int res = easyfind( v, 2 );
		std::cout << res << " is in vector" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		int res = easyfind( v, 4 );
		std::cout << res << " is in vector" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		int res = easyfind( v, 9 );
		std::cout << res << " is in vector" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		int res = easyfind( v, -8 );
		std::cout << res << " is in vector" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	
	
	std::list<int> l;
	for ( int i = 1; i < 6; i++ ) {
		l.push_back(i);
	}

	try {
		int res = easyfind( l, 2 );
		std::cout << res << " is in list" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		int res = easyfind( l, 4 );
		std::cout << res << " is in list" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		int res = easyfind( l, 9 );
		std::cout << res << " is in list" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		int res = easyfind( l, -8 );
		std::cout << res << " is in list" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
