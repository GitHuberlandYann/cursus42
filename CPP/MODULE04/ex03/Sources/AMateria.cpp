/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:23 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:23 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( void ) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

AMateria::AMateria( std::string const & type ) : _type(type) {
	return ;
}

AMateria::AMateria( const AMateria &other ) : _type(other._type) {
	// std::cout << "Copy constructor called" << std::endl;
	return ;
}

AMateria::~AMateria( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

AMateria &AMateria::operator=( const AMateria &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

std::string const & AMateria::getType() const {
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "if this line appears, I f*cked up" << std::endl;
}
