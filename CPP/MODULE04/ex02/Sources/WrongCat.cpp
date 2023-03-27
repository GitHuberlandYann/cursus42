/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) {
	std::cout << "Default constructor of WrongCat called" << std::endl;
	this->_type = "WrongCat";
	return ;
}


WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal( other ) {
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	this->_type = other._type;
	return ;
}

WrongCat::~WrongCat( void ) {
	std::cout << "Destructor of WrongCat called" << std::endl;
	return ;
}

WrongCat &WrongCat::operator=( const WrongCat &other ) {
	std::cout << "Copy assignment operator of WrongCat called" << std::endl;
	this->_type = other._type;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	WrongCat::makeSound( void ) const {
	std::cout << "(Wrongcats don’t bark)" << std::endl;
}
