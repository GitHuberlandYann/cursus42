/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:23:24 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/11 09:23:24 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base {
public:
	virtual ~Base( void ) {}
};

class A: public Base {};

class B: public Base {};

class C: public Base {};

Base * generate(void) {
	int dice_roll =  std::rand() % 3;
	Base* result  = 0;
	// std::cout << dice_roll << ": ";
	if (!dice_roll) {
		result = new A();
	} else if (dice_roll == 1) {
		result = new B();
	} else if (dice_roll == 2) {
		result = new C();
	} else {
		std::cout << "sir we got a problem here" << std::endl;
	}
	return (result);
}

void identify(Base* p) {
	// std::cout << "ptr id: ";
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if (a) {
		std::cout << "A" << std::endl;
	} else if (b) {
		std::cout << "B" << std::endl;
	} else if (c) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Identification failed" << std::endl;
	}
}

void identify(Base& p) {
	// std::cout << "ref id: ";
	try {
		A& a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &e) {
	}
	try {
		B& b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception &e) {
	}
	try {
		C& c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch (std::exception &e) {
	}
	std::cout << "Identification failed" << std::endl;
}

int	main( void ) {
	std::srand(std::time(0));
	Base* first = generate();
	identify(first);
	identify(*first);
	delete first;
	Base* second = generate();
	identify(second);
	identify(*second);
	delete second;
	Base* third = generate();
	identify(third);
	identify(*third);
	delete third;
	return (0);
}