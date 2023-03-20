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

ClapTrap::ClapTrap( void ) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
}


ClapTrap::ClapTrap( const ClapTrap &other ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

ClapTrap::~ClapTrap( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //