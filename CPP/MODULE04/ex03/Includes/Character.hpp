/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:30 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:30 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter {

private:
	const std::string	_name;
	AMateria			*_inventory[4];

public:
	Character( void );
	Character( std::string const & name );
	Character( const Character &other );
	~Character( void );
	Character &operator=( const Character &other );

	virtual std::string const & getName( void ) const;
	virtual void equip( AMateria* m );
	virtual void unequip( int idx );
	virtual void use( int idx, ICharacter& target );
};

#endif
