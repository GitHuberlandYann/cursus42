/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:30:05 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:30:05 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main( void ) {
	ClapTrap	fighter( "<name>" );
	ClapTrap	bystander( "victim" );

	for (int i = 0; i < 12; ++i) {
		int	can_attack = fighter.getEnergyPoints();
		fighter.attack( "victim" );
		if (can_attack) {
			bystander.takeDamage( fighter.getAttackDamage() );
		}
		fighter.setAttackDamage( fighter.getAttackDamage() + 1 );
		if (i & 1) {
			bystander.beRepaired( 1 );
		}
		std::cout << std::endl;
	}
	return (0);
}
