/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:16:28 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/12 15:16:28 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T> {

private:

public:
	MutantStack<T>( void ) : std::stack<T>() {}
	MutantStack<T>( const MutantStack &other ) : std::stack<T>(other) {}
	~MutantStack<T>( void ) {}
	MutantStack &operator=( const MutantStack &other ) {(void) other; return (*this);}

	typedef typename std::deque<T>::iterator iterator;
	iterator begin( void ) {return (this->c.begin());}
	iterator end( void ) {return (this->c.end());}
};

#endif
