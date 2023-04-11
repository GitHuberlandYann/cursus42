/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:23:33 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/11 09:23:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
