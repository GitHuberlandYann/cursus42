/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:56:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/21 11:34:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap() {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	this->_max_hit_points = 100;
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	this->_max_hit_points = 100;
	std::cout << "Setter constructor of FragTrap " << this->_name << " called" << std::endl;
	return ;
}


FragTrap::FragTrap( const FragTrap &other ) : ClapTrap( other ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

FragTrap::~FragTrap( void ) {
	std::cout << "Destructor of FragTrap " << this->_name << " called" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=( const FragTrap &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other.getName();
	this->_hit_points = other.getHitPoints();
	this->_energy_points = other.getEnergyPoints();
	this->_attack_damage = other.getAttackDamage();
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	FragTrap::attack( const std::string& target ) {
	if (this->_energy_points && this->_hit_points) {
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " <<  this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_points;
		std::cout << this->_name << " now has " << this->_energy_points << " energy points left." << std::endl;
	} else {
		std::cout << this->_name << " can't attack, its energy point are " << this->_energy_points << ", its hit points are " << this->_hit_points << std::endl;
	}
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " requests a positive high five." << std::endl;
}
