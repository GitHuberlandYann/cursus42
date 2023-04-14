/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:27:50 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/12 11:27:50 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
// #include <iterator>
#include <exception>

class NotFindException : public std::exception {
public:
	virtual const char* what() const throw() {
		return ("[NotFindException] Element not found.");
	}
};

template <typename T>
int easyfind( T const & container, int const nb ) {
	typename T::const_iterator finding = std::find( container.begin(), container.end(), nb);

	if (finding == end(container)) {
		throw NotFindException();
	}
	return (*finding);
}

#endif
