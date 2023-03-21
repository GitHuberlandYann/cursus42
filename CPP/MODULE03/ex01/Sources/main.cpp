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

#include "ScavTrap.hpp"
#include <iostream>

int	main( void ) {
	ClapTrap	fighter( "<name>" );
	ClapTrap	cofighter( "bully" );
	ScavTrap	bystander( "guard" );

	bystander.guardGate();
	for (int i = 0; i < 12; ++i) {
		std::cout << "Day " << i << std::endl;
		int	can_attack = fighter.getEnergyPoints();
		fighter.attack( "victim" );
		if (can_attack) {
			bystander.takeDamage( fighter.getAttackDamage() );
		}
		fighter.setAttackDamage( fighter.getAttackDamage() + 1 );
		int	cocan_attack = cofighter.getEnergyPoints();
		cofighter.attack( "victim" );
		if (cocan_attack) {
			bystander.takeDamage( cofighter.getAttackDamage() );
		}
		cofighter.setAttackDamage( fighter.getAttackDamage() + 1 );
		if (i & 1) {
			bystander.beRepaired( 1 );
		}
		if (i == 5) {
			int	guardcan_attack = bystander.getEnergyPoints();
			bystander.attack( "bully ");
			if (guardcan_attack) {
				cofighter.takeDamage( bystander.getAttackDamage() );
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
