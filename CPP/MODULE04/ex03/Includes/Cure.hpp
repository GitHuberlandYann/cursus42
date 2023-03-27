/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:34 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:34 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{

public:
	Cure( void );
	Cure( const Cure &other );
	~Cure( void );
	Cure &operator=( const Cure &other );

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
