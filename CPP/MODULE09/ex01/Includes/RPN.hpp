/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:08:54 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 13:08:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <string>
# include <stack>

void RPN( std::string str );

class InvalidInputException: public std::exception {
	
	public:
		virtual const char* what() const throw();
};

class DivByZeroException: public std::exception {
	
	public:
		virtual const char* what() const throw();
};

class BadStackSizeException: public std::exception {
	
	public:
		virtual const char* what() const throw();
};

#endif
