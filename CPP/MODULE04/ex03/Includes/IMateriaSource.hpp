/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:42 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:42 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class AMateria;

class IMateriaSource
{
public:
	IMateriaSource( void ) {}
	IMateriaSource( const IMateriaSource &other ) {(void)other;}
	IMateriaSource &operator=( const IMateriaSource &other ) {(void)other;return *this;}
	virtual ~IMateriaSource() {}
	
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
