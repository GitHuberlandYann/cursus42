/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:01:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << "Default constructor of Intern Default called" << std::endl;
	return ;
}

Intern::Intern( const Intern &other ) {
	std::cout << "Copy constructor of Intern  called" << std::endl;
	(void) other;
	return ;
}

Intern::~Intern( void ) {
	std::cout << "Destructor of Intern  called" << std::endl;
	return ;
}

Intern &Intern::operator=( const Intern &other ) {
	std::cout << "Copy assignment operator of Intern  called" << std::endl;
	(void)other;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

AForm	*Intern::makeForm( std::string name, std::string target ) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	res = -1;

	for (int i = 0; i < 3; i++) {
		if (forms[i] == name) {
			res = i;
		}
	}

	switch (res) {
		case 0:
			return (new ShrubberyCreationForm(target));
			break ;
		case 1:
			return (new RobotomyRequestForm(target));
			break ;
		case 2:
			return (new PresidentialPardonForm(target));
			break ;
		default:
			std::cout << "Intern couldn't create form " << name << std::endl;
			return (0);
	}
}
