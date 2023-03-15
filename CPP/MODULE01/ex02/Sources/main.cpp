/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 16:43:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// ************************************************************************** //
// 		REF like PTR, but	-not NULL                                         //
// 							-constant                                         //
// 							-always deferenced                                //
// ************************************************************************** //
int	main( void ) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl << std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl << std::endl;

	std::string strbis = "THIS IS BRUNO";
	stringPTR = &strbis;

	std::cout << str << std::endl;
	std::cout << strbis << std::endl;
	std::cout << *stringPTR << std::endl << std::endl;

	stringREF = strbis;
	std::cout << str << std::endl;
	std::cout << strbis << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}
