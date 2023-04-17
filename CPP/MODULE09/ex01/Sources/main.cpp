/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:09:31 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 13:09:31 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main( int ac, char **av ) {
	if (ac != 2) {
		std::cout << "Usage: ./RPN <string>" << std::endl;
		return (1);
	}
	try {
		std::string str = av[1];
		RPN( str );
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
