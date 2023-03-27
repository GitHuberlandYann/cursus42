/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource( void ) {
	// std::cout << "Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_templates[i] = NULL;
	}
	return ;
}

MateriaSource::MateriaSource( const MateriaSource &other ) : IMateriaSource( other ) {
	// std::cout << "Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_templates[i] = other._templates[i]->clone();
	}
	return ;
}

MateriaSource::~MateriaSource( void ) {
	// std::cout << "Destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete this->_templates[i];
	}
	return ;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete this->_templates[i];
		this->_templates[i] = other._templates[i]->clone();
	}
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void		MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_templates[i]) {
			this->_templates[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_templates[i] && this->_templates[i]->getType() == type) {
			AMateria *res = this->_templates[i]->clone();
			return (res);
		}
	}
	return (NULL);
}
