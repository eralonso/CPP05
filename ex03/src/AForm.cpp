/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:39:22 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/19 13:43:19 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException( std::string error_msg ): \
						std::out_of_range( error_msg + "Grade Too High" ) {}

AForm::GradeTooLowException::GradeTooLowException( std::string error_msg ): \
						std::out_of_range( error_msg + "Grade Too Low" ) {}

AForm::FormIsSignedException::FormIsSignedException( std::string error_msg ): \
						std::logic_error( error_msg + "Form Is Signed" ) {}
AForm::FormIsNotSignedException::FormIsNotSignedException( std::string error_msg ): \
						std::logic_error( error_msg + "Form Is Not Signed" ) {}

AForm::AForm( void ): _name( "Unnamed Form" ), _isSigned( false ), _signGrade( MIN_GRADE ), _execGrade( MIN_GRADE ) {}

AForm::AForm( std::string name, unsigned int signGrade, unsigned int execGrade ): _name( name ), _isSigned( false ), _signGrade( signGrade ), _execGrade( execGrade )
{
	checkValidGrade( signGrade, MIN_GRADE, MAX_GRADE, "Sign " );
	checkValidGrade( execGrade, MIN_GRADE, MAX_GRADE, "Exec " );
}

AForm::AForm( const AForm& form ): _name( form._name ), _isSigned( form._isSigned ), _signGrade( form._signGrade ), _execGrade( form._execGrade ) {}

AForm::~AForm( void ) {}

AForm&	AForm::operator=( const AForm& form )
{
	_isSigned = form._isSigned;
	return ( *this );
}

std::string	AForm::getName( void ) const
{
	return ( _name );
}

unsigned int	AForm::getSignGrade( void ) const
{
	return ( _signGrade );
}

unsigned int	AForm::getExecGrade( void ) const
{
	return ( _execGrade );
}

bool	AForm::getIsSigned( void ) const
{
	return ( _isSigned );
}

void	AForm::checkValidGrade( unsigned int grade, unsigned int min, unsigned int max, std::string msg ) const
{
	if ( grade > min )
		throw AForm::GradeTooLowException( msg );
	else if ( grade < max )
		throw AForm::GradeTooHighException( msg );
}

void	AForm::beSigned( const Bureaucrat& bureaucrat )
{
	checkValidGrade( bureaucrat.getGrade(), _signGrade, MAX_GRADE, "Sign " );
	if ( _isSigned == true )
		throw AForm::FormIsSignedException( "" );
	_isSigned = true;
}

void	AForm::execute( const Bureaucrat& executor ) const
{
	if ( executor.getGrade() > _execGrade )
		throw AForm::GradeTooLowException( "Exec " );
	if ( _isSigned == false )
		throw AForm::FormIsNotSignedException( "" );
	FormExecute();
}

std::ostream&	operator<<( std::ostream& out, const AForm& form )
{
	out << "Form name: " << form.getName() << ", Form sign grade: " \
		<< form.getSignGrade() << ", Form exec grade: " \
		<< form.getExecGrade() << ", Form is signed: " \
		<< (form.getIsSigned() ? "true" : "false");
	return ( out );
}

std::ostream&	operator<<( std::ostream& out, const AForm* form )
{
	if ( form != NULL )
	{
		out << "Form name: " << form->getName() << ", Form sign grade: " \
			<< form->getSignGrade() << ", Form exec grade: " \
			<< form->getExecGrade() << ", Form is signed: " \
			<< (form->getIsSigned() ? "true" : "false");	
	}
	else
		out << "Empty form";
	return ( out );
}
