/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:31:32 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/20 09:31:32 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap {

private:

public:
	ClapTrap( void );
	ClapTrap( const ClapTrap &other );
	~ClapTrap( void );
	ClapTrap &operator=( const ClapTrap &other );

};

#endif