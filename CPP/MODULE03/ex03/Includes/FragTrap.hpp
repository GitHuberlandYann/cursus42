/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:54:35 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 11:11:27 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap &other );
	~FragTrap( void );
	FragTrap &operator=( const FragTrap &other );

	void highFivesGuys( void );

};

#endif
