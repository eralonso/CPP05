/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:58:06 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/15 19:01:01 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
# define __FORM_H__

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
		void				checkValidGrade( unsigned int grade, unsigned int min, \
							unsigned int max, std::string msg ) const;
	public:
		Form( void );
		Form( std::string name, unsigned int _signGrade, unsigned int _execGrade );
		Form( const Form& form );
		~Form( void );
		Form&			operator=( const Form& form );
		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		unsigned int	getSignGrade( void ) const;
		unsigned int	getExecGrade( void ) const;
		void			beSigned( const Bureaucrat& bureaucrat );
		class GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException( std::string error_msg );
		};
		class GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException( std::string error_msg );
		};
		class FormIsSignedException: public std::logic_error
		{
			public:
				FormIsSignedException( std::string error_msg );
		};

};

std::ostream&	operator<<( std::ostream& out, const Form& form );

#endif
