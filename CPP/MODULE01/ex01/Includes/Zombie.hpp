/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:13:34 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/15 17:04:32 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

private:
	std::string _name;

public:
	Zombie( void );
	Zombie( std::string str );
	~Zombie( void );

	void	announce( void );
	void	set_name( std::string str );
};

#endif
