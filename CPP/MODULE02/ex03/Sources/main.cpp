#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point const	a( 0.0, 0.0 );
	Point const	b( 3.0, 0.0 );
	Point const	c( 3.0, 1.5 );
	Point const	point( -10000.5, -0.5 );

	std::cout << "a : " << a.getX() << "," << a.getY() << std::endl;
	std::cout << "b : " << b.getX() << "," << b.getY() << std::endl;
	std::cout << "c : " << c.getX() << "," << c.getY() << std::endl;
	std::cout << "point : " << point.getX() << "," << point.getY() << std::endl;

	if (bsp(a, b, c, point)) {
		std::cout << "Point is in triangle" << std::endl;
	} else {
		std::cout << "Point is not in triangle" << std::endl;
	}
	return (0);
}
