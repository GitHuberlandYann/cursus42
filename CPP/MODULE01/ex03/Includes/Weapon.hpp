/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:58:49 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 17:15:54 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {

private:
	std::string	_type;

public:
	Weapon( std::string str );
	~Weapon( void );

	std::string const	&getType( void );
	void				setType( std::string str );
};

#endif
