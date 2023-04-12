/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:28:08 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/12 12:28:08 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span( unsigned int N ) : _N(N) {
	std::cout << "Setter constructor of Span called" << std::endl;
	return ;
}

Span::Span( const Span &other ) : _N(other._N), _list(other._list) {
	std::cout << "Copy constructor of Span called" << std::endl;
	return ;
}

Span::~Span( void ) {
	std::cout << "Destructor of Span called" << std::endl;
	return ;
}

Span &Span::operator=( const Span &other ) {
	std::cout << "Copy assignment operator of Span called" << std::endl;
	this->_N = other._N;
	this->_list = other._list;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, const Span &s )
{
	if (!s.size())
		return (out);
	std::list<int>::const_iterator it = s.begin();
	std::list<int>::const_iterator ite = s.end();

	std::cout << "List: " << *it;
	++it;
	for (; it != ite; it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	return (out);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

size_t Span::size( void ) const {
	return (this->_list.size());
}

std::list<int>::const_iterator Span::begin( void ) const {
	return (this->_list.begin());
}

std::list<int>::const_iterator Span::end( void ) const {
	return (this->_list.end());
}

void	Span::addNumber( int nb ) {
	if (this->_list.size() == this->_N) {
		throw Span::SpanFullException();
	}
	this->_list.push_back( nb );
}

void	Span::addBunchOfNumbers( std::list<int>::iterator it, std::list<int>::iterator ite ) {
	std::list<int>::iterator loop = it;
	unsigned int len = 0;
	for (; loop != ite; loop++) {
		++len;
	}
	if (this->_list.size() + len < this->_list.size() || this->_list.size() + len > this->_N) {
		throw Span::SpanFullException();
	}

	this->_list.insert(this->_list.end(), it, ite);
}

unsigned int Span::shortestSpan( void ) {
	if (this->_list.size() <= 1) {
		throw Span::SpanMissingNumbers();
	}

	std::list<int>::iterator it = this->_list.begin();
	std::list<int>::iterator ite = this->_list.end();
	unsigned int minspan = UINT_MAX;
	for (; it != ite; it++) {
		std::list<int>::iterator itbis = it;
		++itbis;
		for (; itbis != ite; itbis++) {
			unsigned int dist = abs(*it - *itbis);
			if (dist < minspan) {
				minspan = dist;
			}
		}
	}
	return (minspan);
}

unsigned int Span::longestSpan( void ) {
	if (this->_list.size() <= 1) {
		throw Span::SpanMissingNumbers();
	}

	std::list<int>::iterator min = std::min_element(this->_list.begin(), this->_list.end());
	std::list<int>::iterator max = std::max_element(this->_list.begin(), this->_list.end());
	return (*max - *min);
}

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* Span::SpanFullException::what() const throw() {
			return ("[Span::SpanFullException] Span is full.");
		}

const char* Span::SpanMissingNumbers::what() const throw() {
	return ("[Span::SpanMissingNumbers] Not enough numbers stored.");
}
