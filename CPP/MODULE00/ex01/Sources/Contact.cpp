#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::set_attributes(void) {
	std::cout << "    $> contact's first name : ";
	std::cin >> this->_first_name;
	std::cout << "    $> contact's last name : ";
	std::cin >> this->_last_name;
	std::cout << "    $> contact's nickname : ";
	std::cin >> this->_nickname;
	std::cout << "    $> contact's phone number : ";
	std::cin >> this->_phone_number;
	std::cout << "    $> contact's darkest secret : ";
	std::cin >> this->_darkest_secret;
}

void	Contact::display_columns(void) {
	for (size_t i = 0; i < 10 - this->_first_name.size(); ++i) {
		std::cout << " ";
	}
	std::cout << this->_first_name << "|";
	for (size_t i = 0; i < 10 - this->_last_name.size(); ++i) {
		std::cout << " ";
	}
	std::cout << this->_last_name << "|";
	for (size_t i = 0; i < 10 - this->_nickname.size(); ++i) {
		std::cout << " ";
	}
	std::cout << this->_nickname << std::endl;
}

void	Contact::display_fields(void) {
	std::cout << "  First name     : " << this->_first_name << std::endl;
	std::cout << "  Last name      : " << this->_last_name << std::endl;
	std::cout << "  Nickname       : " << this->_nickname << std::endl;
	std::cout << "  Phone number   : " << this->_phone_number << std::endl;
	std::cout << "  Darkest secret : " << this->_darkest_secret << std::endl;
	return ;
}
