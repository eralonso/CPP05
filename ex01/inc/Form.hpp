/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:58:06 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/10 18:04:10 by eralonso         ###   ########.fr       */
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
		class GradeTooHighException: public std::exception
		{
			private:
				std::string	_msg;
			public:
			GradeTooHighException( void ): _msg( "" ) {}
			GradeTooHighException( std::string msg ): _msg( msg ) {}
			~GradeTooHighException( void ) _NOEXCEPT {}
			const char * what () const throw ()
			{
				const std::string	message = _msg + "Grade too high";
				//const char			*ret = message.c_str();
				return ( message.c_str() );
				//return ( ret );
			}
		};
		class GradeTooLowException: public std::exception
		{
			private:
				std::string	_msg;
			public:
			GradeTooLowException( void ): _msg( "" ) {}
			GradeTooLowException( std::string msg ): _msg( msg ) {}
			~GradeTooLowException( void ) _NOEXCEPT {}
			const char * what () const throw ()
			{
				const std::string	message = _msg + "Grade too low";
				//const char			*ret = message.c_str();
				return ( message.c_str() );
				//return ( ret );
			}
		};
		class FormIsSignedException: public std::exception
		{
			const char * what () const throw ()
			{
				return ( "Form is signed" );
			}
		};

};

std::ostream&	operator<<( std::ostream& out, const Form& form );

#endif
