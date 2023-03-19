#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}


Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=( const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other.getRawBits();
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
