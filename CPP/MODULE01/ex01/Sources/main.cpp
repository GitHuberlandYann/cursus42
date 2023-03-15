/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:29:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 16:05:07 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main( void ) {
	Zombie	main = Zombie("42");
	Zombie	*zombHorde;

	zombHorde = zombieHorde(4, "44");

	main.announce();
	for (int i = 0; i < 4; ++i) {
		zombHorde[i].announce();
	}
	delete [] zombHorde;
	return (0);
}
