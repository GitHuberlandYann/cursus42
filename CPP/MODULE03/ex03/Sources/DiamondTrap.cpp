/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:56:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/21 13:31:59 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
	ClapTrap::_name = "Default_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	this->_max_hit_points = this->_hit_points;
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), ScavTrap( name ), FragTrap( name ) {
	this->_name = name;
	ClapTrap::_name = name + "_clap_trap";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	this->_max_hit_points = this->_hit_points;
	std::cout << "Setter constructor of DiamondTrap " << this->_name << " called" << std::endl;
	return ;
}


DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap( other ), ScavTrap( other ), FragTrap( other ) {
	std::cout << "Copy constructor of dia called" << std::endl;
	*this = other;
	return ;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "Destructor of DiamondTrap " << this->_name << " called" << std::endl;
	return ;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other ) {
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

void DiamondTrap::whoAmI( void ) {
	std::cout << "My name is " << this->_name << ", but you can call me by my ClapTrap name " << ClapTrap::_name << "!" << std::endl;
}
