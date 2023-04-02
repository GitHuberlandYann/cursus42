/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:01:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm( "Robotomy", 72, 45 ), _target("Default") {
	std::cout << "Default constructor of RobotomyRequestForm Default called" << std::endl;
	std::srand(std::time(0));
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm( "Robotomy", 72, 45 ), _target(target) {
	std::cout << "Setter constructor of RobotomyRequestForm called" << std::endl;
	std::srand(std::time(0));
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : AForm( "Robotomy", 72, 45 ), _target(other._target) {
	std::cout << "Copy constructor of RobotomyRequestForm called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "Destructor of RobotomyRequestForm called" << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
	std::cout << "Copy assignment operator of RobotomyRequestForm called" << std::endl;
	(void)other;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void	RobotomyRequestForm::activate( void ) {
	std::cout << "dzzzz dzzzz" << std::endl;
	int dice_roll =  std::rand()/((RAND_MAX + 1u)/2);

	if (dice_roll) {
		std::cout << this->_target << " has been robotomized." << std::endl;
	} else {
		std::cout << "Robotomy on " << this->_target << " failed." << std::endl;
	}
}
