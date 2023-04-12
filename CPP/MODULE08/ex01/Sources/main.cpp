/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:27:32 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/12 12:27:32 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int	main( void ) {
	std::cout << "\t---------TEST 1---------" << std::endl;
	{
	Span sp = Span(5);

	try {
		sp.shortestSpan();
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(6);
	try {
		sp.longestSpan();
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(3);
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		sp.addNumber(110);
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}

	std::cout << sp;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	}

	std::cout << std::endl << "\t---------TEST 2---------" << std::endl;
	{
	Span sp = Span(3);
	sp.addNumber(9);
	Span copy = Span(sp);
	copy.addNumber(3);
	Span copybis(20);
	copybis = copy;
	copybis.addNumber(-48);
	try {
		copybis.addNumber(20);
	}
	catch ( std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp << copy << copybis;
	}
	
	std::cout << std::endl << "\t---------TEST 3---------" << std::endl;
	{
	std::list<int> v;
	v.push_back(9);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);

	Span sp = Span(9);
	sp.addNumber( 20 );
	try {
		sp.addBunchOfNumbers( v.begin(), v.end() );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sp;
	}

	std::cout << std::endl << "\t---------TEST 4---------" << std::endl;
	{
	
	}
	return (0);
}
