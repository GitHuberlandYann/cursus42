#include "Ice.hpp"
#include <iostream>

Ice::Ice( void ) : AMateria("ice") {
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Ice::Ice( const Ice &other ) : AMateria("ice") {
	// std::cout << "Copy constructor called" << std::endl;
	(void)other;
	return ;
}

Ice::~Ice( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Ice &Ice::operator=( const Ice &other ) {
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

AMateria* Ice::clone() const {
	Ice *res = new Ice( *this );
	return (res);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
