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
	if (index == start_index || str[index] != '.' || !str[index + 1])
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
	++index;
	if (!str[index])
		return (FLOAT);
	return (INVALID);
}

static void	convert_char( std::string str ) {
	// std::cout << "type char detected" << std::endl;
	char	tochar = str[0];
	int		toint = static_cast<int>(tochar);
	float	tofloat = static_cast<float>(tochar);
	double	todouble = static_cast<double>(tochar);

	std::cout << "char: " << tochar << std::endl;
	std::cout << "int: " << toint << std::endl;
	std::cout << "float: " << tofloat << ".0f" << std::endl;
	std::cout << "double: " << todouble << ".0" << std::endl;
}

static void	convert_int( std::string str ) {
	// std::cout << "type int detected" << std::endl;
	try {
		int		toint = stoi( str );
		char	tochar = static_cast<char>(toint);
		float	tofloat = static_cast<float>(toint);
		double	todouble = static_cast<double>(toint);

		if (isprint(tochar)) {
			std::cout << "char: " << tochar << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << toint << std::endl;
		std::cout << "float: " << tofloat << ".0f" << std::endl;
		std::cout << "double: " << todouble << ".0" << std::endl;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
}

static std::string convert_dot( int toint, float tofloat ) {
	float	compare = static_cast<float>(toint);

	if (compare == tofloat) {
		return (".0");
	}
	return ("");
}

static void	convert_float( std::string str ) {
	// std::cout << "type float detected" << std::endl;
	try {
		float	tofloat = stof( str );
		char	tochar = static_cast<char>(tofloat);
		int		toint = static_cast<float>(tofloat);
		double	todouble = static_cast<double>(tofloat);

		if (isprint(tochar)) {
			std::cout << "char: " << tochar << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << toint << std::endl;
		std::cout << "float: " << tofloat << convert_dot(toint, tofloat) << "f" << std::endl;
		std::cout << "double: " << todouble << convert_dot(toint, tofloat) << std::endl;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
}

static void	convert_double( std::string str ) {
	// std::cout << "type double detected" << std::endl;
	try {
		double		todouble = stod( str );
		char	tochar = static_cast<char>(todouble);
		int		toint = static_cast<float>(todouble);
		float	tofloat = static_cast<double>(todouble);

		if (isprint(tochar)) {
			std::cout << "char: " << tochar << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << toint << std::endl;
		std::cout << "float: " << tofloat << convert_dot(toint, tofloat) << "f" << std::endl;
		std::cout << "double: " << todouble << convert_dot(toint, tofloat) << std::endl;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
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
