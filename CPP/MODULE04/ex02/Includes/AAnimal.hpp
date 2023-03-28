/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:41:11 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:41:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "Brain.hpp"

class AAnimal {

protected:
	std::string	_type;

public:
	AAnimal( void );
	AAnimal( const AAnimal &other );
	virtual ~AAnimal( void );
	AAnimal &operator=( const AAnimal &other );

	virtual void	makeSound( void ) const = 0;
	std::string		getType( void ) const;
	virtual	Brain	*getBrain( void ) const = 0;

};

#endif
