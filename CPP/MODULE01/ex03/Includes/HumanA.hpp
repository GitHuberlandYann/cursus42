/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:53:27 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 17:27:16 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {

private:
	std::string	_name;
	Weapon		&_weap;

public:
	HumanA( std::string str, Weapon &weapon );
	~HumanA( void );

	void	attack( void );
};

#endif
