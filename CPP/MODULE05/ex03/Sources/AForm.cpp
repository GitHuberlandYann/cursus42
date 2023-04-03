/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:01:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <stdexcept>

AForm::AForm( void ) : _name("Default"), _signed(false), _grade_sign(150), _grade_execute(150) {
	std::cout << "Default constructor of AForm Default called" << std::endl;
	return ;
}

AForm::AForm( const std::string name, const int grade_sign, const int grade_execute )
		: _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute) {
	std::cout << "Full setter constructor of AForm " << name << " called" << std::endl;
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

AForm::AForm( const AForm &other )
	: _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_execute(other._grade_execute) {
	std::cout << "Copy constructor of AForm " << this->_name << " called" << std::endl;
	return ;
}

AForm::~AForm( void ) {
	std::cout << "Destructor of AForm " << this->_name << " called" << std::endl;
	return ;
}

AForm &AForm::operator=( const AForm &other ) {
	std::cout << "Copy assignment operator of AForm " << this->_name << " called" << std::endl;
	this->_signed = other._signed;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, const AForm &b )
{
	out << "AForm " << b.getName();
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

std::string	AForm::getName( void ) const {
	return (this->_name);
}

bool		AForm::getSigned( void ) const {
	return (this->_signed);
}

int			AForm::getGradeSign( void ) const {
	return (this->_grade_sign);
}

int			AForm::getGradeExecute( void ) const {
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

const char* Form::FormNotSigned::what() const throw() {
	return ("[Form::FormNotSigned] Form must first be signed before being executed.");
}
