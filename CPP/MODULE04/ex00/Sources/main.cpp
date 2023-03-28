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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	k->makeSound();

	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
	delete k;
	std::cout << std::endl;

	const Animal	*lucy = new Animal();
	const Animal	*og = new Dog(*(Dog *)lucy);
	const Animal	*cpy = new Dog(*(Dog *)og);
	const Animal	*cpyter = new Animal(*og);
	const Animal	*cpydog = new Animal(*(Dog *)og);
	const Animal	*cpycat = new Animal(*(Cat *)og);
	const Animal	*catcpy = new Cat(*(Cat *)og);
	// const Animal	*catfail = new Cat(*og); //this doesn't work

	std::cout << std::endl;
	std::cout << lucy->getType() << " lucy -> ";
	lucy->makeSound();
	std::cout << og->getType() << " og -> ";
	og->makeSound();
	std::cout  << cpy->getType() << " cpy -> ";
	cpy->makeSound();
	std::cout  << cpyter->getType() << " cpyter -> ";
	cpyter->makeSound();
	std::cout  << cpydog->getType() << " cpydog -> ";
	cpydog->makeSound();
	std::cout  << cpycat->getType() << " cpycat -> ";
	cpycat->makeSound();
	std::cout  << catcpy->getType() << " catcpy -> ";
	catcpy->makeSound();
	std::cout << std::endl;
	
	delete lucy;
	delete og;
	delete cpy;
	delete cpyter;
	delete cpydog;
	delete cpycat;
	delete catcpy;
	return (0);
}
