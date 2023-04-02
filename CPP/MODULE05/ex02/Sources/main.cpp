/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:52:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 15:52:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void ) {
	Bureaucrat	worker0;
	Bureaucrat	worker1( "tom" );
	Bureaucrat	worker2( worker1 );
	Bureaucrat	worker3( "Bob", 56 );
	Bureaucrat	worker4( "obb", 1 );
	Bureaucrat	worker5( "bbo", 150 );

	std::cout << std::endl;
	std::cout << worker0 << std::endl;
	std::cout << worker1 << std::endl;
	std::cout << worker2 << std::endl;
	std::cout << worker3 << std::endl;
	std::cout << worker4 << std::endl;
	std::cout << worker5 << std::endl << std::endl;

	worker3.gradeUp();
	std::cout << worker3 << std::endl;
	worker3.gradeUp();
	std::cout << worker3 << std::endl;
	worker3.gradeDown();
	std::cout << worker3 << std::endl;
	worker4.gradeUp();
	worker5.gradeDown();
	std::cout << std::endl;

	AForm	*form = new ShrubberyCreationForm( "random" );
	std::cout << std::endl;

	worker5.signForm( *form );
	form->execute( worker5 );
	form->execute( worker4 );
	worker0.signForm( *form );
	worker3.signForm( *form );
	worker4.signForm( *form );
	form->execute( worker5 );
	form->execute( worker4 );

	std::cout << std::endl;
	
	AForm	*roboform = new RobotomyRequestForm( "random" );
	std::cout << std::endl;

	worker5.signForm( *roboform );
	roboform->execute( worker5 );
	roboform->execute( worker4 );
	worker0.signForm( *roboform );
	worker3.signForm( *roboform );
	worker4.signForm( *roboform );
	roboform->execute( worker5 );
	for (int i = 0; i < 10; i++) {
		roboform->execute( worker4 );
	}

	std::cout << std::endl;
	
	AForm	*pardon = new PresidentialPardonForm( "civilian" );
	std::cout << std::endl;

	worker5.signForm( *pardon );
	pardon->execute( worker5 );
	pardon->execute( worker4 );
	worker0.signForm( *pardon );
	worker3.signForm( *pardon );
	worker4.signForm( *pardon );
	pardon->execute( worker5 );
	pardon->execute( worker4 );

	std::cout << std::endl;
	worker3.executeForm( *form );
	worker3.executeForm( *roboform );
	worker3.executeForm( *pardon );
	worker5.executeForm( *form );
	worker5.executeForm( *roboform );
	worker5.executeForm( *pardon );
	worker4.executeForm( *form );
	worker4.executeForm( *roboform );
	worker4.executeForm( *pardon );

	std::cout << std::endl;
	delete form;
	delete roboform;
	delete pardon;
	std::cout << std::endl;
	// const Bureaucrat	fail0( "Bobef", -56 );
	// const Bureaucrat	fail1( "Bobbef", 0 );
	// const Bureaucrat	fail2( "Bobbbef", 151 );
	// std::cout << std::endl;

	// std::cout << fail0 << std::endl;
	// std::cout << fail1 << std::endl;
	// std::cout << fail2 << std::endl << std::endl;
	return (0);
}
