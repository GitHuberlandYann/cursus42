/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:36 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:36 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice &other );
	~Ice( void );
	Ice &operator=( const Ice &other );

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
