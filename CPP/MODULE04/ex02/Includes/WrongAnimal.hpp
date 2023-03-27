/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:41:11 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:41:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

protected:
	std::string	_type;

public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal &other );
	virtual ~WrongAnimal( void );
	WrongAnimal &operator=( const WrongAnimal &other );

	void	makeSound( void ) const;
	std::string		getType( void ) const;

};

#endif
