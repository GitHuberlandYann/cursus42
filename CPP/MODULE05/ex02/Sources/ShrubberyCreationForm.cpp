/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:01:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm( "Shrubbery", 145, 137 ), _target("Default") {
	std::cout << "Default constructor of ShrubberyCreationForm Default called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : AForm( "Shrubbery", 145, 137 ), _target(target) {
	std::cout << "Setter constructor of ShrubberyCreationForm called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : AForm( "Shrubbery", 145, 137 ), _target(other._target) {
	std::cout << "Copy constructor of ShrubberyCreationForm called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "Destructor of ShrubberyCreationForm called" << std::endl;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
	std::cout << "Copy assignment operator of ShrubberyCreationForm called" << std::endl;
	(void)other;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	if (!this->getSigned()) {
		throw AForm::FormNotSigned();
	} else if (executor.getGrade() > this->getGradeExecute()) {
		throw AForm::GradeTooLowException();
	}

	std::string 	filename = this->_target + "_shrubbery";
	const char		*fname = filename.c_str();
	std::ofstream	outfile(fname);

	if (!outfile.is_open()) {
		std::cout << "Failed to create " << fname << std::endl;
		return ;
	}
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;
	outfile.close();
}
