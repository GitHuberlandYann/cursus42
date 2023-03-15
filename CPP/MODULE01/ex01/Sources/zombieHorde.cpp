/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:50:47 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 16:03:22 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		horde[i].set_name(name);
	}
	return (horde);
}