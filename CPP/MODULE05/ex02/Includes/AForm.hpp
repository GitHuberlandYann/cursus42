/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:59:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 14:59:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
class Bureaucrat;

class AForm {

private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_execute;

public:
	AForm( void );
	AForm( const std::string name, const int grade_sign, const int grade_execute );
	AForm( const AForm &other );
	virtual ~AForm( void );
	AForm &operator=( const AForm &other );

	std::string		getName( void ) const;
	bool			getSigned( void ) const;
	int				getGradeSign( void ) const;
	int				getGradeExecute( void ) const;
	void			beSigned( const Bureaucrat &b );
	virtual void	execute( Bureaucrat const & executor ) const = 0;
	

	class GradeTooHighException: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};

	class FormAlreadySignedException: public std::exception {
	
	public:
		virtual const char* what() const throw();
	};

	class FormNotSigned: public std::exception {

	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const AForm &b );

#endif
