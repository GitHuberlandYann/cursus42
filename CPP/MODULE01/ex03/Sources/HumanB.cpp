/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:14:06 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 17:34:35 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string str ) : _name(str), _weap(NULL) {
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	HumanB::attack( void ) {
	if (this->_weap) {
		std::cout << this->_name << " attacks with their "
			<< this->_weap->getType() << std::endl;
	} else {
		std::cout << this->_name << " attacks with their .. fists ?"
			<< std::endl;
	}
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->_weap = &weapon;
}
