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
	Bureaucrat	master( "john", 1 );
	Bureaucrat	middle( "bob", 73 );
	Bureaucrat	servant( "marc", 150 );
	AForm		*shruform = new ShrubberyCreationForm( "tree" );
	AForm		*roboform = new RobotomyRequestForm( "franken" );
	AForm		*presiform = new PresidentialPardonForm( "bob" );

	std::cout << std::endl;
	std::cout << master << std::endl;
	std::cout << middle << std::endl;
	std::cout << servant << std::endl;
	std::cout << *shruform << std::endl;
	std::cout << *roboform << std::endl;
	std::cout << *presiform << std::endl << std::endl;

	try {
		std::cout << "********** TRY 0 **********" << std::endl << std::endl;

		servant.signForm( *shruform );
		servant.signForm( *roboform );
		servant.signForm( *presiform );
		middle.signForm( *shruform );
		middle.signForm( *roboform );
		middle.gradeUp();
		middle.signForm( *roboform );
		middle.signForm( *presiform );
		master.signForm( *shruform );
		master.signForm( *roboform );
		master.signForm( *presiform );

		std::cout << std::endl;

		servant.executeForm( *shruform );
		servant.executeForm( *roboform );
		servant.executeForm( *presiform );
		middle.executeForm( *shruform );
		middle.executeForm( *roboform );
		middle.executeForm( *presiform );
		master.executeForm( *shruform );
		master.executeForm( *roboform );
		master.executeForm( *presiform );

		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}

	delete shruform;
	delete roboform;
	delete presiform;
	return (0);
}
