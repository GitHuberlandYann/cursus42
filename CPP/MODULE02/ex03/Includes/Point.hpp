#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point( void );
	Point( const float a, const float b );
	Point( const Point &other );
	~Point( void );
	Point &operator=( const Point &other );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

};

#endif
