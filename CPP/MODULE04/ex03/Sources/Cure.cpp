/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:14 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:14 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure( void ) : AMateria("cure") {
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Cure::Cure( const Cure &other ) : AMateria("cure") {
	// std::cout << "Copy constructor called" << std::endl;
	(void)other;
	return ;
}

Cure::~Cure( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Cure &Cure::operator=( const Cure &other ) {
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

AMateria* Cure::clone() const {
	Cure *res = new Cure( *this );
	return (res);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
