/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:05:50 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 17:34:23 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {

private:
	std::string	_name;
	Weapon		*_weap;

public:
	HumanB( std::string str );
	~HumanB( void );
	
	void	attack( void );
	void	setWeapon( Weapon &weapon );
};

#endif
