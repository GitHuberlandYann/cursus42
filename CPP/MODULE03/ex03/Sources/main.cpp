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

#include "DiamondTrap.hpp"
#include <iostream>

int	main( void ) {
	// ClapTrap	fighter( "<name>" );
	// ClapTrap	cofighter( "bully" );
	// ScavTrap	bystander( "guard" );
	// FragTrap	fragger( "fragman" );

	// bystander.guardGate();
	// for (int i = 0; i < 12; ++i) {
	// 	std::cout << "Day " << i << std::endl;
	// 	fragger.highFivesGuys();
	// 	int	can_attack = fighter.getEnergyPoints() && fighter.getHitPoints();
	// 	fighter.attack( "victim" );
	// 	if (can_attack) {
	// 		bystander.takeDamage( fighter.getAttackDamage() );
	// 	}
	// 	fighter.setAttackDamage( fighter.getAttackDamage() + 1 );
	// 	int	cocan_attack = cofighter.getEnergyPoints() && cofighter.getHitPoints();
	// 	cofighter.attack( "victim" );
	// 	if (cocan_attack) {
	// 		bystander.takeDamage( cofighter.getAttackDamage() );
	// 	}
	// 	cofighter.setAttackDamage( fighter.getAttackDamage() + 1 );
	// 	if (i & 1) {
	// 		bystander.beRepaired( 1 );
	// 	}
	// 	if (i == 5) {
	// 		int	guardcan_attack = bystander.getEnergyPoints() && bystander.getHitPoints();
	// 		bystander.attack( "bully ");
	// 		if (guardcan_attack) {
	// 			cofighter.takeDamage( bystander.getAttackDamage() );
	// 		}
	// 		int	fragcan_attack = fragger.getEnergyPoints() && fragger.getHitPoints();
	// 		fragger.attack( "<name>" );
	// 		if (fragcan_attack) {
	// 			fighter.takeDamage( fragger.getAttackDamage() );
	// 		}
	// 	}
	// 	fragger.highFivesGuys();
	// 	std::cout << std::endl;
	// }

	DiamondTrap	diaguy( "dio" );
	std::cout << std::endl;
	diaguy.whoAmI();
	diaguy.guardGate();
	diaguy.highFivesGuys();
	diaguy.attack( "no one" );
	diaguy.beRepaired( 4 );
	
	std::cout << std::endl;
	DiamondTrap	copycat( diaguy );
	copycat.whoAmI();
	std::cout << std::endl;

	diaguy.setAttackDamage(69);
	copycat.attack( "og dia" );
	std::cout << std::endl;

	DiamondTrap	def;
	def.whoAmI();
	std::cout << std::endl;

	return (0);
}
