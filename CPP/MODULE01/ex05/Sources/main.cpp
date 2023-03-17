/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:56:43 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/17 09:56:43 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void ) {
	Harl	magne = Harl();

	magne.complain("DEBUG");
	magne.complain("INFO");
	magne.complain("WARNING");
	magne.complain("ERROR");
	magne.complain("Random sh*t");
	return (0);
}
