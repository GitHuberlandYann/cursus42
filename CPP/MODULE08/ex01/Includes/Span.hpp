/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:28:21 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/12 12:28:21 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <list>
# include <sstream>

class Span {

private:
	unsigned int _N;
	std::list<int> _list;

public:
	Span( unsigned int N );
	Span( const Span &other );
	~Span( void );
	Span &operator=( const Span &other );

	size_t size( void ) const;
	std::list<int>::const_iterator begin( void ) const;
	std::list<int>::const_iterator end( void ) const;
	void	addNumber( int nb );
	void	addBunchOfNumbers( std::list<int>::iterator it, std::list<int>::iterator ite );
	unsigned int shortestSpan( void );
	unsigned int longestSpan( void );

	class SpanFullException: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};
	
	class SpanMissingNumbers: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const Span &s );

#endif
