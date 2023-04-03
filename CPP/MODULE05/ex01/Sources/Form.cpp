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
	if (grade_sign < 1) {
		throw Form::GradeTooHighException();
	} else if (grade_sign > 150) {
		throw Form::GradeTooLowException();
	} else if (grade_execute < 1) {
		throw Form::GradeTooHighException();
	} else if (grade_execute > 150) {
		throw Form::GradeTooLowException();
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
	std::cout << ", it needs grade " << b.getGradeSign() << " to be signed and grade " << b.getGradeExecute() << " to be executed.";
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
	if (this->_signed) {
		throw Form::FormAlreadySignedException();
	} else if (b.getGrade() > this->_grade_sign) {
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* Form::GradeTooHighException::what() const throw() {
	return ("[Form::GradeTooHighException] Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("[Form::GradeTooLowException] Grade is too low.");
}

const char* Form::FormAlreadySignedException::what() const throw() {
	return ("[Form::FormAlreadySignedException] Form is already signed.");
}
