/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:17:13 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/04 09:17:13 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <ctype.h>
# include <sstream>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define SPECIAL 4
# define INVALID 5

class ScalarConverter {

private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter &other );
	~ScalarConverter( void );
	ScalarConverter &operator=( const ScalarConverter &other );

public:
	static void	convert( std::string str );

};

#endif
