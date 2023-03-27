/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
	const std::string	_type;

public:
	AMateria( void );
	AMateria( std::string const & type );
	AMateria( const AMateria &other );
	virtual ~AMateria( void );
	AMateria &operator=( const AMateria &other );

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
