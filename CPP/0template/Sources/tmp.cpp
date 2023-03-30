#include "tmp.hpp"
#include <iostream>

Tmp::Tmp( void ) {
	std::cout << "Default constructor of Tmp called" << std::endl;
	return ;
}

Tmp::Tmp( const Tmp &other ) {
	std::cout << "Copy constructor of Tmp called" << std::endl;
	*this = other;
	return ;
}

Tmp::~Tmp( void ) {
	std::cout << "Destructor of Tmp called" << std::endl;
	return ;
}

Tmp &Tmp::operator=( const Tmp &other ) {
	std::cout << "Copy assignment operator of Tmp called" << std::endl;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //
