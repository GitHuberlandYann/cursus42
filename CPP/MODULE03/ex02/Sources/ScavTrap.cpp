/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:56:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 11:20:50 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_max_hit_points = 100;
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_max_hit_points = 100;
	std::cout << "Setter constructor of ScavTrap " << this->_name << " called" << std::endl;
	return ;
}


ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap( other ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "Destructor of ScavTrap " << this->_name << " called" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	this->_max_hit_points = 100;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	ScavTrap::attack( const std::string& target ) {
	if (this->_energy_points && this->_hit_points) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " <<  this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_points;
		std::cout << this->_name << " now has " << this->_energy_points << " energy points left." << std::endl;
	} else {
		std::cout << this->_name << " can't attack, its energy point are " << this->_energy_points << ", its hit points are " << this->_hit_points << std::endl;
	}
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
