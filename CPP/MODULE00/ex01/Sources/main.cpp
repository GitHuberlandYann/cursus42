#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string	str;
	PhoneBook	book;
	
	while (1) {
		std::cout << "Enter one of the following commands :  ADD, SEARCH or EXIT" << std::endl << "$> ";
		std::cin >> str;
		if (!str.compare("ADD")) {
			Contact	new_contact;
			new_contact.set_attributes();
			book.add_contact(new_contact);
		} else if (!str.compare("SEARCH")) {
			book.display_contacts();
			book.get_contact();
		} else if (!str.compare("EXIT")) {
			return (0);
		}
	}
	return (0);
}
