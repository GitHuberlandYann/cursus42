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
