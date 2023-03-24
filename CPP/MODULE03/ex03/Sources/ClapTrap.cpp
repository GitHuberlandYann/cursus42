/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:31:35 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:31:35 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap( void ) : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0), _max_hit_points(10) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0), _max_hit_points(10) {
	std::cout << "Setter constructor of " << this->_name << " called" << std::endl;
	return ;
}


ClapTrap::ClapTrap( const ClapTrap &other ) {
	std::cout << "Copy constructor of clap called" << std::endl;
	*this = other;
	return ;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "Destructor of " << this->_name << " called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	ClapTrap::attack( const std::string& target ) {
	if (this->_energy_points && this->_hit_points) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " <<  this->_attack_damage << " points of damage!" << std::endl;
		--this->_energy_points;
		std::cout << this->_name << " now has " << this->_energy_points << " energy points left." << std::endl;
	} else {
		std::cout << this->_name << " can't attack, its energy point are " << this->_energy_points << ", its hit points are " << this->_hit_points << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	std::cout << "ClapTrap " << this->_name << " got attacked with " <<  amount << " points of damage!" << std::endl;
	this->_hit_points -= amount;
	if (this->_hit_points < 0) {
		this->_hit_points = 0;
	}
	std::cout << this->_name << " now has " << this->_hit_points << " hit points left." << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_hit_points == this->_max_hit_points) {
		std::cout << this->_name << " doesn't need to repair itself, it has " << this->_max_hit_points << " hit points." << std::endl;
	} else if (this->_energy_points && this->_hit_points) {
		std::cout << this->_name << " repairs itself of " << amount << " hit points." << std::endl;
		this->_hit_points += amount;
		if (this->_hit_points > this->_max_hit_points) {
			this->_hit_points = this->_max_hit_points;
		}
		--this->_energy_points;
		std::cout << this->_name << " now has " << this->_hit_points << " hit points and " << this->_energy_points << " energy points left." << std::endl;
	} else {
		std::cout << this->_name << " can't repair itself, its energy point are " << this->_energy_points << ", its hit points are " << this->_hit_points << std::endl;
	}
}

std::string	ClapTrap::getName( void ) const {
	return (this->_name);
}
int			ClapTrap::getHitPoints( void ) const {
	return (this->_hit_points);
}

int			ClapTrap::getEnergyPoints( void ) const {
	return (this->_energy_points);
}

int			ClapTrap::getAttackDamage( void ) const {
	return (this->_attack_damage);
}

void		ClapTrap::setAttackDamage( int amount ) {
	if (this->_energy_points && this->_hit_points) {
		std::cout << "Attack damage of " << this->_name << " has gone from " << this->_attack_damage << " to " << amount << std::endl;
		this->_attack_damage = amount;
	} else {
		std::cout << this->_name << " can't change its attack damage" << std::endl;
	}
}
