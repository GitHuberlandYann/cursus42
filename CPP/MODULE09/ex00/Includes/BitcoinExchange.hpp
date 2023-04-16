#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <exception>

class BitcoinExchange {

private:
	std::map<std::string, float> _database;

public:
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange &other );
	~BitcoinExchange( void );
	BitcoinExchange &operator=( const BitcoinExchange &other );

	void display_database( void );

	class FailedOpenFileException: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};
};

#endif
