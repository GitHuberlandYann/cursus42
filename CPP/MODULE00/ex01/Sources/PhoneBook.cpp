/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:06:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 11:06:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nb_contacts(0), _curr_index(0) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                    Main                                    //
// ************************************************************************** //

void	PhoneBook::add_contact(Contact contact) {
	this->_contacts[this->_curr_index] = contact;
	++this->_curr_index;
	if (this->_nb_contacts < 8) {
		++this->_nb_contacts;
	}
	if (this->_curr_index == 8)
		this->_curr_index = 0;
	return ;
}

void	PhoneBook::display_contacts(void) {
	for (int i = 0; i < this->_nb_contacts; ++i) {
		std::cout << "         " << i << "|";
		this->_contacts[i].display_columns();
	}
}

void	PhoneBook::get_contact(void) {
	if (this->_nb_contacts == 0) {
		std::cout << "No contacts yet, use ADD to record your first one" << std::endl;
	} else {
		int			target;
		std::string	str;
		std::cout << "Input contact's index : ";
		std::getline(std::cin, str);
		if (str.size() != 1 || !isdigit(str[0])) {
			return (get_contact());
		}
		target = std::stoi(str);
		if (target >= this->_nb_contacts) {
			return (get_contact());
		} else {
			this->_contacts[target].display_fields();
		}
	}
}
