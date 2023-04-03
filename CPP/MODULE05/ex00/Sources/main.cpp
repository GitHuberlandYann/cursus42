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

int	main( void ) {
	try {
		std::cout << "********** TRY 0 **********" << std::endl << std::endl;
		Bureaucrat	master( "john", 1 );
		Bureaucrat	servant( "marc", 149 );

		std::cout << std::endl;
		std::cout << master << std::endl;
		std::cout << servant << std::endl << std::endl;

		master.gradeDown();
		std::cout << master << std::endl;
		master.gradeUp();
		std::cout << master << std::endl;
		servant.gradeDown();
		servant.gradeDown();
		std::cout << servant << std::endl;
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}

	try {
		std::cout << "********** TRY 1 **********" << std::endl << std::endl;
		Bureaucrat	failup( "bob", 0 );

		std::cout << failup << std::endl;
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}

	try {
		std::cout << "********** TRY 2 **********" << std::endl << std::endl;
		Bureaucrat	faildown( "obo", 151 );

		std::cout << faildown << std::endl;
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}

	try {
		std::cout << "********** TRY 3 **********" << std::endl << std::endl;
		Bureaucrat	failup( "bbb", -56 );
		Bureaucrat	normal( "ooo", 6 );

		std::cout << failup << std::endl;
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}

	try {
		std::cout << "********** TRY 4 **********" << std::endl << std::endl;
		Bureaucrat	master( "john", 1 );
		Bureaucrat	servant( "marc", 149 );

		std::cout << std::endl;
		std::cout << master << std::endl;
		std::cout << servant << std::endl << std::endl;

		master.gradeDown();
		std::cout << master << std::endl;
		master.gradeUp();
		std::cout << master << std::endl;
		servant.gradeDown();
		std::cout << servant << std::endl;
		std::cout << "This is never read." << std::endl;
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}
	return (0);
}
