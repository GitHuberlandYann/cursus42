#include "Harl.hpp"
#include <iostream>

int	main( int ac, char **av ) {
	if (ac != 2) {
		std::cout << "Usage: ./harlFilter <string>" << std::endl;
		return (1);
	}

	
	Harl	magne = Harl();

	magne.complain(av[1]);
	return (0);
}
