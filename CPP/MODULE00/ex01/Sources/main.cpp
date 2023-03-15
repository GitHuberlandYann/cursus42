/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:06:22 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 11:06:22 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::getline(std::cin, str);
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
