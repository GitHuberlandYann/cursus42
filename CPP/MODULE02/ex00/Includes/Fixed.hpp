#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

private:
	int					_value;
	static const int	_binary_point = 8;

public:
	Fixed( void );
	Fixed( const Fixed &other );
	~Fixed( void );
	Fixed &operator=( const Fixed &other );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif