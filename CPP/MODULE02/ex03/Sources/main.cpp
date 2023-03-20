#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

static void	test_case( Point const a, Point const b, Point const c, Point const point) {
	std::cout << "Point " << point.getX() << ", " << point.getY()
		<< " in triangle : " << bsp(a, b, c, point) << std::endl;
}

int main( void ) {
	Point const	a( 0.0, 0.0 );
	Point const	b( 3.0, 0.0 );
	Point const	c( 1.5, 3.0 );

	std::cout << "a : " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "b : " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "c : " << c.getX() << ", " << c.getY() << std::endl;
	
	test_case(a, b, c, Point( 0.5, 0.5 ));
	test_case(a, b, c, Point( 1.5, 1.5 ));
	test_case(a, b, c, Point( 0.5, -0.5 ));
	test_case(a, b, c, Point( 1.5, 0.0 ));
	test_case(a, b, c, Point( 1.5, 2.9 )); //problem here ?
	test_case(a, b, c, Point( 1.5, 2.5));
	test_case(a, b, c, Point( 1.5, 3.1 ));
	test_case(a, b, c, a);
	return (0);
}
