/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:31:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:31:44 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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