/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:54:35 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/21 11:32:25 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap &other );
	~FragTrap( void );
	FragTrap &operator=( const FragTrap &other );

	void attack( const std::string& target );
	void highFivesGuys( void );

};

#endif
