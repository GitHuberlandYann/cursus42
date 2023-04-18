/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:20:51 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 09:20:51 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map> // map <=> sorted keys
# include <string>
# include <exception>

class BitcoinExchange {

private:
	std::map<std::string, float> _database;

	BitcoinExchange( const BitcoinExchange &other );
	BitcoinExchange &operator=( const BitcoinExchange &other );

public:
	BitcoinExchange( void );
	~BitcoinExchange( void );

	void display_database( void );
	void read_file( char *filename );

	class FailedOpenFileException: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};

	class EmptyDataBaseException: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};
};

#endif
