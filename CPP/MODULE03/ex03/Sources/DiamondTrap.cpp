/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:56:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:15:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) : _name("Default") {
	ClapTrap::_name = "Default_clap_name";
	std::cout << "Default constructor of DiamondTrap called" << std::endl;
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_attack_damage = 30;
	this->_energy_points = 50;
	return ;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_trap" ) {
	this->_name = name;
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_attack_damage = 30;
	this->_energy_points = 50;
	std::cout << "Setter constructor of DiamondTrap " << this->_name << " called" << std::endl;
	std::cout << "\tName : " << this->_name << std::endl;
	std::cout << "\tClapTrap name : " << ClapTrap::_name << std::endl;
	std::cout << "\tHit points : " << this->_hit_points << std::endl;
	std::cout << "\tEnergy points : " << this->_energy_points << std::endl;
	std::cout << "\tAttack damage : " << this->_attack_damage << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap( other ), FragTrap( other ), ScavTrap( other ) {
	std::cout << "Copy constructor of dia called" << std::endl;
	*this = other;
	return ;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "Destructor of DiamondTrap " << this->_name << " called" << std::endl;
	return ;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other ) {
	std::cout << "Copy assignment operator of DiamondTrap called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	this->_max_hit_points = other._max_hit_points;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void DiamondTrap::whoAmI( void ) {
	std::cout << "My name is " << this->_name << ", but you can call me by my ClapTrap name " << ClapTrap::_name << "!" << std::endl;
}
