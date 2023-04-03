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
#include "Form.hpp"
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
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
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
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	--this->_grade;
	displayGradeChange( this->_name, this->_grade + 1, this->_grade );
}

void		Bureaucrat::gradeDown( void ) {
	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	++this->_grade;
	displayGradeChange( this->_name, this->_grade - 1, this->_grade );
}

void		Bureaucrat::signForm( Form &f ) const {
	try {
		f.beSigned( *this );
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("[Bureaucrat::GradeTooHighException] You can't go above the highest grade : 1.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("[Bureaucrat::GradeTooLowException] You can't go above the lowest grade : 150.");
}
