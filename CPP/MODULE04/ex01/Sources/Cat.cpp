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
	this->_brain = new Brain();
	return ;
}


Cat::Cat( const Cat &other ) : Animal( other ) {
	std::cout << "Copy constructor of Cat called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain(*(other._brain));
	return ;
}

Cat::~Cat( void ) {
	std::cout << "Destructor of Cat called" << std::endl;
	delete this->_brain;
	return ;
}

Cat &Cat::operator=( const Cat &other ) {
	std::cout << "Copy assignment operator of Cat called" << std::endl;
	this->_type = "Cat";
	*this->_brain = *other._brain;
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

Brain	*Cat::getBrain( void ) const {
	return (this->_brain);
}
