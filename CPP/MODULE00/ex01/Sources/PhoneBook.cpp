#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nb_contacts(0), _curr_index(0) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

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
		int	target;
		std::cout << "Input contact's index : ";
		std::cin >> target;
		if (target < 0 || target >= this->_nb_contacts) {
			std::cout << "Wrong index, aborting search" << std::endl;
		} else {
			this->_contacts[target].display_fields();
		}
	}
}
