/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) {
	std::cout << "Default constructor of Dog called" << std::endl;
	this->_type = "Dog";
	return ;
}


Dog::Dog( const Dog &other ) : Animal( other ) {
	std::cout << "Copy constructor of Dog called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::~Dog( void ) {
	std::cout << "Destructor of Dog called" << std::endl;
	return ;
}

Dog &Dog::operator=( const Dog &other ) {
	std::cout << "Copy assignment operator of Dog called" << std::endl;
	(void)other;
	this->_type = "Dog";
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	Dog::makeSound( void ) const {
	std::cout << "*distinguished bark*" << std::endl;
}
