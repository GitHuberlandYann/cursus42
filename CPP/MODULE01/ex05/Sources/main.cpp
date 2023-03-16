#include "Harl.hpp"

int	main( void ) {
	Harl	magne = Harl();

	magne.complain("DEBUG");
	magne.complain("INFO");
	magne.complain("WARNING");
	magne.complain("ERROR");
	magne.complain("Random sh*t");
	return (0);
}
