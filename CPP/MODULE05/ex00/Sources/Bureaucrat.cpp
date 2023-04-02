/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:01:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) {
	std::cout << "Default constructor of Bureaucrat Default called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const std::string name ) : _name(name), _grade(150) {
	std::cout << "Setter constructor of Bureaucrat " << name << " called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const std::string name, const int grade ) : _name(name), _grade(150) {
	std::cout << "Full setter constructor of Bureaucrat " << name << " called" << std::endl;
	try {
		if (grade < 1) {
			throw Bureaucrat::GradeTooHighException();
		} else if (grade > 150) {
			throw Bureaucrat::GradeTooLowException();
		} else {
			this->_grade = grade;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name), _grade(other._grade) {
	std::cout << "Copy constructor of Bureaucrat " << this->_name << " called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Destructor of Bureaucrat " << this->_name << " called" << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other ) {
	std::cout << "Copy assignment operator of Bureaucrat " << this->_name << " called" << std::endl;
	this->_grade = other._grade;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &b )
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}

int			Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

static void	displayGradeChange( std::string name, int prev, int now ) {
	std::cout << name << "'s grade went from " << prev << " to " << now << "." << std::endl;
}

void		Bureaucrat::gradeUp( void ) {
	try {
		if (this->_grade - 1 < 1) {
			throw Bureaucrat::GradeTooHighException();
		} else {
			--this->_grade;
			displayGradeChange( this->_name, this->_grade + 1, this->_grade );
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void		Bureaucrat::gradeDown( void ) {
	try {
		if (this->_grade + 1 > 150) {
			throw Bureaucrat::GradeTooLowException();
		} else {
			++this->_grade;
			displayGradeChange( this->_name, this->_grade - 1, this->_grade );
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
