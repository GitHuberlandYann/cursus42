/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:25:33 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/04 09:25:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter( void ) {
	std::cout << "Default constructor of ScalarConverter called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter( const ScalarConverter &other ) {
	std::cout << "Copy constructor of ScalarConverter called" << std::endl;
	*this = other;
	return ;
}

ScalarConverter::~ScalarConverter( void ) {
	std::cout << "Destructor of ScalarConverter called" << std::endl;
	return ;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) {
	std::cout << "Copy assignment operator of ScalarConverter called" << std::endl;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	ScalarConverter::convert( std::string str ) {

}
