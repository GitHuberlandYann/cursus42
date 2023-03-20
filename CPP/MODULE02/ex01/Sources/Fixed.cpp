/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:32:00 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:32:00 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int value ) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = (value << Fixed::_binary_point);
	return ;
}

Fixed::Fixed( const float value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_binary_point));
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

std::ostream &operator<<( std::ostream &out, const Fixed &f )
{
	out << f.toFloat();
	return (out);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

int		Fixed::getRawBits( void ) const {
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)(this->_value) / (1 << Fixed::_binary_point));
}

int		Fixed::toInt( void ) const {
	return (this->_value >> Fixed::_binary_point);
}
