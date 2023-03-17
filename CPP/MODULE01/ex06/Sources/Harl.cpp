/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:56:53 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/17 09:56:53 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl( void ) {
	return ;
}

Harl::~Harl( void ) {
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

void	Harl::_debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::_info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::_error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

static int	level_value( std::string level ) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; ++i) {
		if (!level.compare(levels[i])) {
			return (i);
		}
	}
	return (4);
}

void	Harl::complain( std::string level ) {
	switch (level_value(level))
	{
	case 0:
		this->_debug();
		this->_info();
		this->_warning();
		this->_error();
		break ;
	case 1:
		this->_info();
		this->_warning();
		this->_error();
		break ;
	case 2:
		this->_warning();
		this->_error();
		break ;
	case 3:
		this->_error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}
