/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:25:33 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/04 09:25:33 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

ScalarConverter::ScalarConverter( void ) {
	std::cout << "Default constructor of ScalarConverter called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter( const ScalarConverter &other ) {
	std::cout << "Copy constructor of ScalarConverter called" << std::endl;
	*this = other;
	return ;
}

ScalarConverter::~ScalarConverter( void ) {
	std::cout << "Destructor of ScalarConverter called" << std::endl;
	return ;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) {
	std::cout << "Copy assignment operator of ScalarConverter called" << std::endl;
	(void)other;
	return (*this);
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

static int	detect_type( std::string str ) {
	if (str == "-inff" || str == "+inff" || str == "nanf"
		|| str == "-inf" || str == "+inf" || str == "nan")
		return (SPECIAL);

	int	index = (str[0] == '-');
	int	start_index = index;

	if (!str[index])
		return (CHAR);
	if (str[index] == '0' && isdigit(str[index + 1]))
		return (INVALID);
	while (isdigit(str[index]))
		++index;
	if (!str[index])
		return (INT);
	if (index == start_index && !str[index + 1])
		return (CHAR);
	if (index == start_index || str[index] != '.')
		return (INVALID);
	++index;
	start_index = index;
	while (isdigit(str[index]))
		++index;
	if (start_index == index)
		return (INVALID);
	if (!str[index])
		return (DOUBLE);
	if (str[index] != 'f')
		return (INVALID);
	if (!str[index + 1])
		return (FLOAT);
	return (INVALID);
}

static std::string convert_dot( int toint, float tofloat ) {
	float	compare = static_cast<float>(toint);

	if (compare == tofloat) {
		return (".0");
	}
	return ("");
}

static void	display_result( char tochar, int toint, float tofloat, double todouble ) {
	if (isprint(tochar)) {
		std::cout << "char: " << tochar << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	double	overflow_check = static_cast<double>(toint);
	if ((overflow_check > todouble && overflow_check - todouble >= 1)
		|| (todouble > overflow_check && todouble - overflow_check >= 1)) {
		std::cout << "int: Overflow" << std::endl;
	} else {
		std::cout << "int: " << toint << std::endl;
	}
	std::cout << "float: " << tofloat << convert_dot(toint, tofloat) << "f" << std::endl;
	std::cout << "double: " << todouble << convert_dot(toint, tofloat) << std::endl;
}

static void	convert_char( std::string str ) {
	// std::cout << "type char detected" << std::endl;
	char	tochar = str[0];
	int		toint = static_cast<int>(tochar);
	float	tofloat = static_cast<float>(tochar);
	double	todouble = static_cast<double>(tochar);

	display_result( tochar, toint, tofloat, todouble );
}

static void	convert_int( std::string str ) {
	// std::cout << "type int detected" << std::endl;
	std::istringstream	iss( str );
	int		toint;// = std::stoi( str ); <- since c++11 only
	iss >> toint;
	if (iss.fail()) {
		std::cout << "Int overflow" << std::endl;
		return ;
	}
	char	tochar = static_cast<char>(toint);
	float	tofloat = static_cast<float>(toint);
	double	todouble = static_cast<double>(toint);

	display_result( tochar, toint, tofloat, todouble );
}

static void	convert_float( std::string str ) {
	// std::cout << "type float detected" << std::endl;
	float	tofloat = strtof( str.c_str(), NULL );
	if (errno == ERANGE) {
		std::cout << "Float overflow" << std::endl;
		return ;
	}
	char	tochar = static_cast<char>(tofloat);
	int		toint = static_cast<int>(tofloat);
	double	todouble = static_cast<double>(tofloat);

	display_result( tochar, toint, tofloat, todouble );
}

static void	convert_double( std::string str ) {
	// std::cout << "type double detected" << std::endl;
	double	todouble = strtod( str.c_str(), NULL );
	if (errno == ERANGE) {
		std::cout << "Double overflow" << std::endl;
		return ;
	}
	char	tochar = static_cast<char>(todouble);
	int		toint = static_cast<int>(todouble);
	float	tofloat = static_cast<float>(todouble);

	display_result( tochar, toint, tofloat, todouble );
}

static void	convert_special( std::string str ) {
	if (str == "+inff" || str == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (str == "-inff" || str == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else if (str == "nanf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else {
		std::cout << "type special detected but not handled: " << str << std::endl;
	}
}

void	ScalarConverter::convert( std::string str ) {
	int	type = detect_type( str );
	
	switch (type) {
		case CHAR:
			convert_char( str );
			break;
		case INT:
			convert_int( str );
			break;
		case FLOAT:
			convert_float( str );
			break;
		case DOUBLE:
			convert_double( str );
			break;
		case SPECIAL:
			convert_special( str );
			break;
		default:
			std::cout << "Invalid type: " << str << std::endl;
	}
}
