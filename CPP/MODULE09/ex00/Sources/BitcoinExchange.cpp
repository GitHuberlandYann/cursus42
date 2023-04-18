/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:20:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 09:20:44 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

static int date_line( std::string str, char end ) {
	int index = 0;

	int year = atoi(str.c_str());
	for (; index < 4; index++) {
		if (!isdigit(str[index]))
			return (1);
	}
	if (str[index] != '-')
		return (1);
	++index;
	if (str[index] != '0' && str[index] != '1')
		return (1);
	if (str[index] == '1' && str[index + 1] < '0' && str[index + 1] > '2')
		return (1);
	if (!isdigit(str[index + 1]) || (str[index] == '0' && str[index + 1] == '0'))
		return (1);
	if (str[index + 2] != '-')
		return (1);
	int month = atoi(&str[index]);
	index += 3;
	if (str[index] < '0' && str[index] > '3')
		return (1);
	if (str[index] == '3' && str[index + 1] < '0' && str[index + 1] > '2')
		return (1);
	if (!isdigit(str[index + 1]) || (str[index] == '0' && str[index + 1] == '0'))
		return (1);
	if (str[index + 2] != end)
		return (1);
	int day = atoi(&str[index]);
	int limits[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (!(year % 4)) {
		limits[1] = 29;
		if (!(year % 100) && (year % 400))
			limits[1] = 28;
	}
	return (day > limits[month - 1]);
}

static int value_line( std::string str, int index ) {
	if (str[index] == '0' && isdigit(str[index + 1]))
		return (1);
	if (!isdigit(str[index]))
		return (1);
	while (isdigit(str[index]))
		++index;
	if (!str[index])
		return (0);
	if (str[index] == '.')
		++index;
	if (!isdigit(str[index]))
		return (1);
	while (isdigit(str[index]))
		++index;
	for (; str[index]; index++) {
		if (!isspace(str[index]))
			return (1);
	}
	return (0);
}

BitcoinExchange::BitcoinExchange( void ) {
	std::cout << "Default constructor of BitcoinExchange called" << std::endl;
	std::ifstream indata( "data.csv" );
	if (!indata.is_open()) {
		throw BitcoinExchange::FailedOpenFileException();
	}
	std::string line;
	while (!indata.eof()) {
		std::getline( indata, line );
		if (!date_line(line, ',')) {
			int index = 0;
			for (; line[index] != ','; index++);
			line[index] = '\0';
			++index;
			if (!value_line(line, index)) {
				std::string key = line.substr( 0, index - 1 );
				float value = strtof( &line.c_str()[index], NULL );
				this->_database.insert( std::pair<std::string, float>(key, value) );
			}
		}
	}
	indata.close();
	if (!this->_database.size()) {
		throw BitcoinExchange::EmptyDataBaseException();
	}
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	std::cout << "Destructor of BitcoinExchange called" << std::endl;
	return ;
}

// ************************************************************************** //
//                                  Private                                   //
// ************************************************************************** //

// ************************************************************************** //
//                                   Public                                   //
// ************************************************************************** //

void BitcoinExchange::display_database( void ) {
	std::cout << "data.csv contains:\n";
	std::map<std::string,float>::iterator it = this->_database.begin();
	for ( it = this->_database.begin(); it != this->_database.end(); ++it )
		std::cout << it->first << " => " << it->second << '\n';
}

static int correct_value( std::string str, int index ) {
	if (str[index] != '|' || str[index + 1] != ' ') {
		str[index - 1] = ' ';
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	index += 2;
	int nb = atoi(&str[index]);
	if (!isdigit(str[index])) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (str[index] == '0' && isdigit(str[index + 1])) {
		std::cerr << "Error: number can't be zero-padded." << std::endl;
		return (1);
	}
	int cnt = 0;
	while (isdigit(str[index + cnt]))
		++cnt;
	if (cnt > 4 || nb > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	index += cnt;
	if (!str[index])
		return (0);
	if (str[index] == '.')
		++index;
	if (!isdigit(str[index])) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	while (isdigit(str[index]))
		++index;
	for (; str[index]; index++) {
		if (!isspace(str[index])) {
			std::cerr << "Error: not a positive number." << std::endl;
			return (1);
		}
	}
	return (0);
}

void BitcoinExchange::read_file( char *filename ) {
	std::ifstream infile( filename );
	if (!infile.is_open()) {
		throw BitcoinExchange::FailedOpenFileException();
	}
	std::string line;
	bool first_line = true;
	while (!infile.eof()) {
		std::getline( infile, line );
		// std::cout << "debug | " << line << std::endl;
		if (!date_line(line, ' ')) {
			// std::cout << "-> accepted !" << std::endl;
			int index = 0;
			for (; line[index] != ' '; index++);
			line[index] = '\0';
			++index;
			if (!correct_value(line, index)) {
				// std::cout << "-> and float !" << std::endl;
				std::string key = line.substr( 0, index - 1 );
				float value = strtof( &line.c_str()[index + 2], NULL );
				std::map<std::string, float>::iterator it = this->_database.lower_bound( key );
				if (it == this->_database.end() || (it->first != key && it != this->_database.begin())) {
					--it;
					std::cout << key << " => " << value << " = " << value * it->second << std::endl;
					// std::cout << "found " << it->first << " and " << it->second << std::endl;
				} else if (it->first == key) {
					std::cout << key << " => " << value << " = " << value * it->second << std::endl;	
				} else {
					std::cerr << "Error: Date out of bounds => " << key << std::endl;
				}
			}
		} else if (!first_line && line != "") {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
		first_line = false;
	}
	infile.close();
}

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* BitcoinExchange::FailedOpenFileException::what() const throw() {
	return ("[BitcoinExchange::FailedOpenFileException] Error: could not open file.");
}

const char* BitcoinExchange::EmptyDataBaseException::what() const throw() {
	return ("[BitcoinExchange::EmptyDataBaseException] Error: database is empty.");
}
