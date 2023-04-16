#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

static int date_line( std::string str, char end ) {
	int index = 0;
	
	if (str[index] == '0')
		return (1);
	int year = atoi(str.c_str());
	while (isdigit(str[index]))
		++index;
	if (!index || index > 9 || str[index] != '-')
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
	// std::cout << "got here " << (int)str[index] << std::endl;
	if (isspace(str[index]))
		return (0);
	return (str[index]);
}

BitcoinExchange::BitcoinExchange( void ) {
	std::cout << "Default constructor of BitcoinExchange called" << std::endl;
	std::ifstream indata( "testfile.csv" );
	if (!indata.is_open()) {
		throw BitcoinExchange::FailedOpenFileException();
	}
	std::string line;
	while (!indata.eof()) {
		std::getline( indata, line );
		std::cout << "debug | " << line << std::endl;
		if (!date_line(line, ',')) {
			// std::cout << "-> accepted !" << std::endl;
			int index = 0;
			for (; line[index] != ','; index++);
			line[index] = '\0';
			++index;
			if (!value_line(line, index)) {
				// std::cout << "-> and float !" << std::endl;
				std::string key = line.substr( 0, index - 1 );
				float value = strtof( &line.c_str()[index], NULL );
				this->_database.insert( std::pair<std::string, float>(key, value) );
			}
		}
	}
	indata.close();
	return ;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) {
	std::cout << "Copy constructor of BitcoinExchange called" << std::endl;
	(void)other;
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	std::cout << "Destructor of BitcoinExchange called" << std::endl;
	return ;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other ) {
	std::cout << "Copy assignment operator of BitcoinExchange called" << std::endl;
	(void)other;
	return (*this);
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

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* BitcoinExchange::FailedOpenFileException::what() const throw() {
	return ("[BitcoinExchange::FailedOpenFileException] Failed to open file.");
}
