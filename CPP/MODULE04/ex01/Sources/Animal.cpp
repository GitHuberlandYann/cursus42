/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : _type("Default") {
	std::cout << "Default constructor of Animal called" << std::endl;
	return ;
}


Animal::Animal( const Animal &other ) : _type(other._type) {
	std::cout << "Copy constructor of Animal called" << std::endl;
	return ;
}

Animal::~Animal( void ) {
	std::cout << "Destructor of Animal called" << std::endl;
	return ;
}

Animal &Animal::operator=( const Animal &other ) {
	std::cout << "Copy assignment operator of Animal called" << std::endl;
	this->_type = other._type;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void			Animal::makeSound( void ) const {
}

std::string		Animal::getType( void ) const {
	return (this->_type);
}
