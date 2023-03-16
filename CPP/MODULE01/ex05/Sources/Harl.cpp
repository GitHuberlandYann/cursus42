#include "Harl.hpp"
#include <iostream>

Harl::Harl( void ) {
	this->_options[0] = &Harl::_debug;
	this->_options[1] = &Harl::_info;
	this->_options[2] = &Harl::_warning;
	this->_options[3] = &Harl::_error;
	return ;
}

Harl::~Harl( void ) {
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

void	Harl::_debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	Harl::complain( std::string level ) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; ++i) {
		if (!level.compare(levels[i])) {
			(this->*(_options[i]))();
			return ;
		}
	}
	std::cout << "No match found for [" << level << "]\n";
}
