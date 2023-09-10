/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:59:27 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/10 17:43:02 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ): _name( "Unnamed Form" ), _isSigned( false ), _signGrade( MIN_GRADE ), _execGrade( MIN_GRADE ) {}

Form::Form( std::string name, unsigned int signGrade, unsigned int execGrade ): _name( name ), _isSigned( false ), _signGrade( signGrade ), _execGrade( execGrade )
{
	checkValidGrade( signGrade, MIN_GRADE, MAX_GRADE, "Sign " );
	checkValidGrade( execGrade, MIN_GRADE, MAX_GRADE, "Exec " );
}

Form::Form( const Form& form ): _name( form._name ), _isSigned( form._isSigned ), _signGrade( form._signGrade ), _execGrade( form._execGrade ) {}

Form::~Form( void ) {}

Form&	Form::operator=( const Form& form )
{
	_isSigned = form._isSigned;
	return ( *this );
}

std::string	Form::getName( void ) const
{
	return ( _name );
}

unsigned int	Form::getSignGrade( void ) const
{
	return ( _signGrade );
}

unsigned int	Form::getExecGrade( void ) const
{
	return ( _execGrade );
}

bool	Form::getIsSigned( void ) const
{
	return ( _isSigned );
}

void	Form::checkValidGrade( unsigned int grade, unsigned int min, unsigned int max, std::string msg ) const
{
	if ( grade > min )
		throw Form::GradeTooLowException( msg );
	else if ( grade < max )
		throw Form::GradeTooHighException( msg );
}

void	Form::beSigned( const Bureaucrat& bureaucrat )
{
	if ( _isSigned == true )
		throw Form::FormIsSignedException();
	checkValidGrade( bureaucrat.getGrade(), MIN_GRADE, _signGrade, "" );
	_isSigned = true;
}

std::ostream&	operator<<( std::ostream& out, const Form& form )
{
	out << "form name: " << form.getName() << ", form sign grade: " \
		<< form.getSignGrade() << ", form exec grade: " \
		<< form.getExecGrade() << ", form is signed: " << form.getIsSigned();
	return ( out );
}

