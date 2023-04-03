/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:59:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 14:59:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm  {

private:
	const std::string _target;

public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm &other );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &other );

	virtual void	execute( Bureaucrat const & executor ) const;
};

#endif
