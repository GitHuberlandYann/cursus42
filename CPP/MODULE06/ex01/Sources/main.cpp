#include "Serializer.hpp"
#include <iostream>

int	main( void ) {
	Data original = { "john", 18 };
	uintptr_t tmp = Serializer::serialize( &original );
	Data* copy = Serializer::deserialize( tmp );

	std::cout << original.name << " - " << copy->name << std::endl;
	std::cout << original.value << " - " << copy->value << std::endl;

	return (0);
}
