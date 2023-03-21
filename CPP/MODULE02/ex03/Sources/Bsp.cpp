/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:32:31 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:32:31 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	ft_abs( Fixed nb ) {
	if (nb < 0) {
		return (nb * Fixed(-1));
	}
	return (nb);
}

static Fixed	area( Point const a, Point const b, Point const c ) {
	Fixed const	div(2);
	return (ft_abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / div));
}

bool			bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	total( area(a, b, c) );
	Fixed	sub_1( area(a, b, point) );
	Fixed	sub_2( area(b, c, point) );
	Fixed	sub_3( area(c, a, point) );
	// std::cout << total << " == " << sub_1 << " + " << sub_2 << " + " << sub_3 << std::endl;
	if (sub_1 == 0 || sub_2 == 0 || sub_3 == 0)
		return (0);
	return (total == (sub_1 + sub_2 + sub_3));
}
