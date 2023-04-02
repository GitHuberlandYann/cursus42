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
#include "Form.hpp"

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

	Form	form( "basic", 75, 1 );
	Form	form1( "bad", 750, 0 );
	std::cout << std::endl;

	worker5.signForm( form );
	worker0.signForm( form );
	worker3.signForm( form );
	worker4.signForm( form );

	std::cout << std::endl;
	const Bureaucrat	fail0( "Bobef", -56 );
	const Bureaucrat	fail1( "Bobbef", 0 );
	const Bureaucrat	fail2( "Bobbbef", 151 );
	std::cout << std::endl;

	std::cout << fail0 << std::endl;
	std::cout << fail1 << std::endl;
	std::cout << fail2 << std::endl << std::endl;
	return (0);
}
