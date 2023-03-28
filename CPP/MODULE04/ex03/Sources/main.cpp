/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:08 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:08 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int	main( void ) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(0, *bob);
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	IMateriaSource*	source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	ICharacter*	man = new Character("man");
	AMateria*	temp;
	temp = source->createMateria("icing cake");
	man->equip(temp);
	temp = source->createMateria("cure");
	man->equip(temp);

	ICharacter*	bobby = new Character("bobby");
	man->use(0, *bobby);
	man->use(1, *bobby);

	man->unequip(0);
	man->use(0, *bobby);

	delete temp;
	delete bobby;
	delete man;
	delete source;
	return (0);
}
