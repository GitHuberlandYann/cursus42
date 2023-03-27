/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:51:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:51:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main( void ) {
	const Animal	*(animals[4]) = {new Dog(), new Cat(), new Cat(), new Dog()};

	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " is a " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	return (0);
}
