#include "Point.hpp"
// #include <iostream>

Point::Point( void ) : _x(0), _y(0) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Point::Point( const float a, const float b ) : _x(a), _y(b) {
	// std::cout << "Setter constructor called" << std::endl;
	return ;
}

Point::Point( const Point &other ) : _x(other._x), _y(other._y) {
	// std::cout << "Copy constructor called" << std::endl;
	return ;
}

Point::~Point( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Point &Point::operator=( const Point &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	// this->_x = other.getX();
	// this->_y = other.getY();
	(void)other;
	return (*this); //this cant be good
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

Fixed	Point::getX( void ) const {
	return (this->_x);
}

Fixed	Point::getY( void ) const {
	return (this->_y);
}
