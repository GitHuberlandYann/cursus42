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
#include "Intern.hpp"

int	main( void ) {
	Intern	someRandomIntern;
	AForm*	rrf;
	AForm*	scf;
	AForm*	pdf;
	AForm*	errorf;

	std::cout << std::endl;

	try {
		std::cout << "********** TRY 0 **********" << std::endl << std::endl;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Blender");
		pdf = someRandomIntern.makeForm("presidential pardon", "Blunder");
		errorf = someRandomIntern.makeForm("error in request", "Bender");
		
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}
	Bureaucrat	lowRank("dylan", 144);
	Bureaucrat	highRank("marcel", 4);
	std::cout << std::endl;
	std::cout << lowRank << std::endl;
	std::cout << highRank << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *pdf << std::endl << std::endl;

	lowRank.executeForm( *rrf );
	highRank.executeForm( *rrf );
	lowRank.signForm( *rrf );
	highRank.signForm( *rrf );
	lowRank.executeForm( *rrf );
	highRank.executeForm( *rrf );

	lowRank.signForm( *scf );
	highRank.signForm( *pdf );

	std::cout << std::endl;
	delete rrf;
	delete scf;
	delete pdf;
	delete errorf;
	return (0);
}
