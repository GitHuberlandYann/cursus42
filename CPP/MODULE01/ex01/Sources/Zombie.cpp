/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:16:59 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 17:04:55 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string str ) : _name(str) {
	std::cout << this->_name << " awakens from the deads" << std::endl;
	return ;
}

Zombie::Zombie( void ) : _name("Default") {
	std::cout << this->_name << " awakens from the deads" << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " goes back to its eternal slumber" << std::endl;
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string str ) {
	std::cout << this->_name << " changed his name to " << str << std::endl;
	this->_name = str;
}
