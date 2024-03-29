/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:19 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:19 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character( void ) : _name("Default") {
	// std::cout << "Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

Character::Character( std::string const & name ) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

Character::Character( const Character &other ) : ICharacter( other ), _name(other._name) {
	// std::cout << "Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i]) {
			this->_inventory[i] = other._inventory[i]->clone();
		} else {
			this->_inventory[i] = NULL;
		}
	}
	return ;
}

Character::~Character( void ) {
	// std::cout << "Destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete this->_inventory[i];
	}
	return ;
}

Character &Character::operator=( const Character &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete this->_inventory[i];
		if (other._inventory[i]) {
			this->_inventory[i] = other._inventory[i]->clone();
		} else {
			this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

std::string const & Character::getName( void ) const {
	return (this->_name);
}

void	Character::equip( AMateria* m ) {
	for ( int i = 0; i < 4; i++ ) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "inventory full" << std::endl;
}

void	Character::unequip( int idx ) {
	if (idx >= 0 && idx <= 3 && this->_inventory[idx]) {
		this->_inventory[idx] = NULL;
		std::cout << this->_name << ", inventory " << idx << " unequiped." << std::endl;
	}
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx <= 3 && this->_inventory[idx]) {
		this->_inventory[idx]->use( target );
	} else {
		std::cout << this->_name << " can't use inventory " << idx << std::endl;
	}
}
