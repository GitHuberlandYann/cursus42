#include "tmp.hpp"
#include <iostream>

Tmp::Tmp( void ) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}


Tmp::Tmp( const Tmp &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Tmp::~Tmp( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Tmp &Tmp::operator=( const Tmp &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //