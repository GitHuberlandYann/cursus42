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

static float	ft_abs( float nb ) {
	if (nb < 0)
		return (-nb);
	return (nb);
}

static float	area( Point const a, Point const b, Point const c ) {
	Fixed const	div(2);
	return (ft_abs(((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / div).toFloat()));
}

bool			bsp( Point const a, Point const b, Point const c, Point const point) {
	float	total = area(a, b, c);
	float	sub_1 = area(a, b, point);
	float	sub_2 = area(b, c, point);
	float	sub_3 = area(c, a, point);
	// std::cout << total << " == " << sub_1 << " + " << sub_2 << " + " << sub_3 << std::endl;
	if (!sub_1 || !sub_2 || !sub_3)
		return (0);
	return (total == (sub_1 + sub_2 + sub_3));
}
