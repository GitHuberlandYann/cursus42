/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:06:43 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 11:06:43 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

static void	Contact::_display_column(std::string str) {
	if (str.size() > 10) {
		for (size_t i = 0; i < 9; ++i) {
			std::cout << str[i];
		}
		std::cout << '.';
	} else {
		for (size_t i = 0; i < 10 - str.size(); ++i) {
			std::cout << ' ';
		}
		std::cout << str;
	}
}

// ************************************************************************** //
//                                    Main                                    //
// ************************************************************************** //

void	Contact::set_attributes(void) {
	std::cout << "    $> contact's first name : ";
	std::getline(std::cin, this->_first_name);
	std::cout << "    $> contact's last name : ";
	std::getline(std::cin, this->_last_name);
	std::cout << "    $> contact's nickname : ";
	std::getline(std::cin, this->_nickname);
	std::cout << "    $> contact's phone number : ";
	std::getline(std::cin, this->_phone_number);
	std::cout << "    $> contact's darkest secret : ";
	std::getline(std::cin, this->_darkest_secret);
}

void	Contact::display_columns(void) {
	_display_column(this->_first_name);
	std::cout << '|';
	_display_column(this->_last_name);
	std::cout << '|';
	_display_column(this->_nickname);
	std::cout << std::endl;
}

void	Contact::display_fields(void) {
	std::cout << "  First name     : " << this->_first_name << std::endl;
	std::cout << "  Last name      : " << this->_last_name << std::endl;
	std::cout << "  Nickname       : " << this->_nickname << std::endl;
	std::cout << "  Phone number   : " << this->_phone_number << std::endl;
	std::cout << "  Darkest secret : " << this->_darkest_secret << std::endl;
}
