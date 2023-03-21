/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:32:33 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:32:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int value ) {
	// std::cout << "Int constructor called" << std::endl;
	this->_value = (value << Fixed::_binary_point);
	return ;
}

Fixed::Fixed( const float value ) {
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_binary_point));
	return ;
}


Fixed::Fixed( const Fixed &other ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed::~Fixed( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=( const Fixed &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other.getRawBits();
	return (*this);
}

int	Fixed::operator>( const Fixed &other ) const {
	return (this->_value > other.getRawBits());
}

int	Fixed::operator<( const Fixed &other ) const {
	return (this->_value < other.getRawBits());
}

int	Fixed::operator>=( const Fixed &other ) const {
	return (this->_value >= other.getRawBits());
}

int	Fixed::operator<=( const Fixed &other ) const {
	return (this->_value <= other.getRawBits());
}

int	Fixed::operator==( const Fixed &other ) const {
	return (this->_value == other.getRawBits());
}

int	Fixed::operator!=( const Fixed &other ) const {
	return (this->_value != other.getRawBits());
}

Fixed	Fixed::operator+( const Fixed &other ) {
	Fixed	result;

	result.setRawBits(this->_value + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( const Fixed &other ) {
	Fixed	result;

	result.setRawBits(this->_value - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*( const Fixed &other ) {
	Fixed	result;
	result.setRawBits(((long)this->_value * (long)other._value) >> this->_binary_point);
	return (result);
}

Fixed	Fixed::operator/( const Fixed &other ) {
	if (!other._value) {
		return (Fixed( -8388610 ));
	}
	Fixed	result;
	result.setRawBits(((long)this->_value << this->_binary_point) / (long)other._value);
	return (result);
}

Fixed &Fixed::operator++( void ) {
	++this->_value;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed old = *this;
	this->operator++();
	return (old);
}

Fixed &Fixed::operator--( void ) {
	--this->_value;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	Fixed old = *this;
	this->operator--();
	return (old);
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

Fixed	&Fixed::min( Fixed &a, Fixed &b ) {
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b ) {
	if (a <= b)
		return (a);
	return (b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b ) {
	if (a >= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b ) {
	if (a >= b)
		return (a);
	return (b);
}
