/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:54:35 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:03:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

private:
	std::string	_name;

public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &other );
	~DiamondTrap( void );
	DiamondTrap &operator=( const DiamondTrap &other );

	using	ScavTrap::attack;

	void whoAmI( void );

};

#endif
