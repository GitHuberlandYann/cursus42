/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) {
	std::cout << "Default constructor of Cat called" << std::endl;
	this->_type = "Cat";
	return ;
}


Cat::Cat( const Cat &other ) : Animal( other ) {
	std::cout << "Copy constructor of Cat called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::~Cat( void ) {
	std::cout << "Destructor of Cat called" << std::endl;
	return ;
}

Cat &Cat::operator=( const Cat &other ) {
	std::cout << "Copy assignment operator of Cat called" << std::endl;
	(void)other;
	this->_type = "Cat";
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	Cat::makeSound( void ) const {
	std::cout << "(cats don’t bark)" << std::endl;
}
