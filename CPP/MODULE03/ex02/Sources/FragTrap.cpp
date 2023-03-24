/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:56:29 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 11:17:07 by yhuberla         ###   ########.fr       */
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

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " requests a positive high five." << std::endl;
}
