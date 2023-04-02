/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:59:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 14:59:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
class AForm;

class Bureaucrat {

private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat( void );
	Bureaucrat( const std::string name );
	Bureaucrat( const std::string name, const int grade );
	Bureaucrat( const Bureaucrat &other );
	~Bureaucrat( void );
	Bureaucrat &operator=( const Bureaucrat &other );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		gradeUp( void );
	void		gradeDown( void );
	void		signForm( AForm &f ) const;
	void		executeForm( AForm const & form );

	class GradeTooHighException: public std::exception {
	
	public:
		virtual const char* what() const throw()
		{
			return ("You can't go above the highest grade : 1.");
		}
	};

	class GradeTooLowException: public std::exception {
	
	public:
		virtual const char* what() const throw()
		{
			return ("You can't go bellow the lowest grade : 150.");
		}
	};
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &b );

#endif
