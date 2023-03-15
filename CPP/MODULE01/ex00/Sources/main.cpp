/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:29:52 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 15:59:10 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void ) {
	Zombie	main = Zombie("42");
	Zombie	*newZomb;

	newZomb = newZombie("43");
	randomChump("44");
	main.announce();
	newZomb->announce();
	delete newZomb; //remove this for leak, valgrind -leaks-check=full ./brainz
	return (0);
}
