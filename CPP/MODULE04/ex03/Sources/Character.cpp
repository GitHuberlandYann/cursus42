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
		this->_inventory[i] = other._inventory[i]->clone();
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
		this->_inventory[i] = other._inventory[i]->clone();
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
	}
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx <= 3 && this->_inventory[idx]) {
		this->_inventory[idx]->use( target );
	}
}
