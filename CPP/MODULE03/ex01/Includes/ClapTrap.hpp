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

# include <string>

class ClapTrap {

private:
	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap &other );
	~ClapTrap( void );
	ClapTrap &operator=( const ClapTrap &other );

	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	std::string	getName( void ) const ;
	int			getHitPoints( void ) const;
	int			getEnergyPoints( void ) const;
	int			getAttackDamage( void ) const;
	void		setAttackDamage( int amount );

};

#endif