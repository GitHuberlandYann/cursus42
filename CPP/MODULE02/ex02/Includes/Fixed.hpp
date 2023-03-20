/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:32:10 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:32:10 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

private:
	int					_value;
	static const int	_binary_point = 8;

public:
	Fixed( void );
	Fixed( const int value );
	Fixed( const float value );
	Fixed( const Fixed &other );
	~Fixed( void );
	Fixed &operator=( const Fixed &other );
	int	operator>( const Fixed &other ) const;
	int	operator<( const Fixed &other ) const;
	int	operator>=( const Fixed &other ) const;
	int	operator<=( const Fixed &other ) const;
	int	operator==( const Fixed &other ) const;
	int	operator!=( const Fixed &other ) const;
	Fixed	operator+( const Fixed &other );
	Fixed	operator-( const Fixed &other );
	Fixed	operator*( const Fixed &other );
	Fixed	operator/( const Fixed &other );
	Fixed	&operator++( void );
	Fixed	operator++( int );
	Fixed	&operator--( void );
	Fixed	operator--( int );

	static Fixed		&min( Fixed &a, Fixed &b );
	static const Fixed	&min( const Fixed &a, const Fixed &b );
	static Fixed		&max( Fixed &a, Fixed &b );
	static const Fixed	&max( const Fixed &a, const Fixed &b );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream &operator<<( std::ostream &out, const Fixed &f );

#endif