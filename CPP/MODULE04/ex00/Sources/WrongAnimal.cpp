/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) : _type("Default") {
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
	return ;
}


WrongAnimal::WrongAnimal( const WrongAnimal &other ) : _type(other._type) {
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "Destructor of WrongAnimal called" << std::endl;
	return ;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other ) {
	std::cout << "Copy assignment operator of WrongAnimal called" << std::endl;
	this->_type = other._type;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void			WrongAnimal::makeSound( void ) const {
	std::cout << "*random animal noise, but definetely not a cat noise*" << std::endl;
}

std::string		WrongAnimal::getType( void ) const {
	return (this->_type);
}
