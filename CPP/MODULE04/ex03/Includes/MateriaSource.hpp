/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:45 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/27 10:22:45 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	AMateria	*_templates[4];

public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &other );
	~MateriaSource( void );
	MateriaSource &operator=( const MateriaSource &other );

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
