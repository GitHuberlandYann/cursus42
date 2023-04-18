/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:48:56 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 13:48:56 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMP_HPP
# define TMP_HPP

# include <iostream>
# include <exception>
# include <deque>
# include <vector>
# include <sstream>
# include <ctime>

# define K_LIMIT 5

void parse_inputs( char **args );
void merge_insert_vector( char **args );
void merge_insert_deque( char **args );

class InvalidInputException: public std::exception {
	
	public:
		virtual const char* what() const throw();
};

#endif
