/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:59:39 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/30 14:59:39 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
class Bureaucrat;

class Form {

private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_execute;

public:
	Form( void );
	Form( const std::string name, const int grade_sign, const int grade_execute );
	Form( const Form &other );
	~Form( void );
	Form &operator=( const Form &other );

	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getGradeSign( void ) const;
	int			getGradeExecute( void ) const;
	void		beSigned( const Bureaucrat &b );
	

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
};

std::ostream &operator<<( std::ostream &out, const Form &b );

#endif
