/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:01:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

Form::Form( void ) : _name("Default"), _signed(false), _grade_sign(150), _grade_execute(150) {
	std::cout << "Default constructor of Form Default called" << std::endl;
	return ;
}

Form::Form( const std::string name, const int grade_sign, const int grade_execute )
		: _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute) {
	std::cout << "Full setter constructor of Form " << name << " called" << std::endl;
	try {
		if (grade_sign < 1) {
			throw Form::GradeTooHighException();
		} else if (grade_sign > 150) {
			throw Form::GradeTooLowException();
		} 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		if (grade_execute < 1) {
			throw Form::GradeTooHighException();
		} else if (grade_execute > 150) {
			throw Form::GradeTooLowException();
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

Form::Form( const Form &other )
	: _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_execute(other._grade_execute) {
	std::cout << "Copy constructor of Form " << this->_name << " called" << std::endl;
	return ;
}

Form::~Form( void ) {
	std::cout << "Destructor of Form " << this->_name << " called" << std::endl;
	return ;
}

Form &Form::operator=( const Form &other ) {
	std::cout << "Copy assignment operator of Form " << this->_name << " called" << std::endl;
	this->_signed = other._signed;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, const Form &b )
{
	out << "Form " << b.getName();
	if (b.getSigned()) {
		std::cout << " is signed";
	} else {
		std::cout << " is not signed";
	}
	std::cout << ", it needs grade " << b.getGradeSign() << " to be signed and grade " << b.getGradeExecute() << " to be executed." << std::endl;
	return (out);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

std::string	Form::getName( void ) const {
	return (this->_name);
}

bool		Form::getSigned( void ) const {
	return (this->_signed);
}

int			Form::getGradeSign( void ) const {
	return (this->_grade_sign);
}

int			Form::getGradeExecute( void ) const {
	return (this->_grade_execute);
}

void		Form::beSigned( const Bureaucrat &b ) {
	try {
		if (this->_signed) {
			std::cout << "Form " << this->_name << " has already been signed." << std::endl;
		} else if (b.getGrade() > this->_grade_sign) {
			throw Form::GradeTooLowException();
		} else {
			this->_signed = true;
			b.signForm(*this);
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
