/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:41:11 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:41:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {

protected:
	std::string	_type;

public:
	Animal( void );
	Animal( const Animal &other );
	virtual ~Animal( void );
	Animal &operator=( const Animal &other );

	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;

};

#endif
