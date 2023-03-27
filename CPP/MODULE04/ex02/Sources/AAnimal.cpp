/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal( void ) : _type("Default") {
	std::cout << "Default constructor of AAnimal called" << std::endl;
	return ;
}


AAnimal::AAnimal( const AAnimal &other ) : _type(other._type) {
	std::cout << "Copy constructor of AAnimal called" << std::endl;
	return ;
}

AAnimal::~AAnimal( void ) {
	std::cout << "Destructor of AAnimal called" << std::endl;
	return ;
}

AAnimal &AAnimal::operator=( const AAnimal &other ) {
	std::cout << "Copy assignment operator of AAnimal called" << std::endl;
	this->_type = other._type;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void			AAnimal::makeSound( void ) const {
}

std::string		AAnimal::getType( void ) const {
	return (this->_type);
}
