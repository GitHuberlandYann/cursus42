/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:41:11 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/24 14:41:11 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {

private:
	std::string	_ideas[100];
	int			_curr_idea;

public:
	Brain( void );
	Brain( const Brain &other );
	~Brain( void );
	Brain &operator=( const Brain &other );

	void		setIdea( int index, const std::string idea );
	void		addIdea( const std::string idea );
	std::string	getIdea( int index );

};

#endif
