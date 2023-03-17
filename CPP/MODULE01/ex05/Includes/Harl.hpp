/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:56:36 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/17 09:56:36 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl {

private:
	void	(Harl::*_options[4])( void );
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );

public:
	Harl( void );
	~Harl( void );

	void	complain( std::string level );

};

#endif