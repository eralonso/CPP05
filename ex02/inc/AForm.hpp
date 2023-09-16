/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:35:22 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/16 13:37:33 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_H__
# define __AFORM_H__

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
		void				checkValidGrade( unsigned int grade, unsigned int min, \
							unsigned int max, std::string msg ) const;
	public:
		AForm( void );
		AForm( std::string name, unsigned int _signGrade, unsigned int _execGrade );
		AForm( const Form& form );
		~AForm( void );
		AForm&			operator=( const AForm& form );
		void			execute( const Bureaucrat& executor ) const;
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

std::ostream&	operator<<( std::ostream& out, const AForm& form );

#endif
