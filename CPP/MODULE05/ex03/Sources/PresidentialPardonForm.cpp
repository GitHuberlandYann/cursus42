/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:01:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "PresidentialPardon", 25, 5 ), _target("Default") {
	std::cout << "Default constructor of PresidentialPardonForm Default called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : AForm( "PresidentialPardon", 25, 5 ), _target(target) {
	std::cout << "Setter constructor of PresidentialPardonForm called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) : AForm( "PresidentialPardon", 25, 5 ), _target(other._target) {
	std::cout << "Copy constructor of PresidentialPardonForm called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "Destructor of PresidentialPardonForm called" << std::endl;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	std::cout << "Copy assignment operator of PresidentialPardonForm called" << std::endl;
	(void)other;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	if (!this->_signed) {
		throw AForm::FormNotSigned();
	} else if (executor.getGrade() > this->_grade_execute) {
		throw AForm::GradeTooLowException();
	}

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebox." << std::endl;
}
