/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:41:37 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/17 13:59:42 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string error_msg ): \
						std::out_of_range( error_msg + "Grade Too High" ) {}

Bureaucrat::GradeTooLowException::GradeTooLowException( std::string error_msg ): \
						std::out_of_range( error_msg + "Grade Too Low" ) {}

Bureaucrat::Bureaucrat( void ): _name( "Unnamed" ), _grade( MIN_GRADE ) {}

Bureaucrat::Bureaucrat( std::string name, unsigned int grade ): _name( name )
{
	if ( grade > MIN_GRADE )
		throw Bureaucrat::GradeTooLowException( "" );
	else if ( grade < MAX_GRADE )
		throw Bureaucrat::GradeTooHighException( "" );
	_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& bureaucrat ): _name( bureaucrat._name ), _grade( bureaucrat._grade ) {}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& bureaucrat )
{
	_grade = bureaucrat._grade;
	return ( *this );
}

std::string	Bureaucrat::getName( void ) const
{
	return ( _name );
}

unsigned int	Bureaucrat::getGrade( void ) const
{
	return ( _grade );
}

void	Bureaucrat::incrementGrade( void )
{
	if ( _grade - 1 < MAX_GRADE )
		throw Bureaucrat::GradeTooHighException( "" );
	_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if ( _grade + 1 > MIN_GRADE )
		throw Bureaucrat::GradeTooLowException( "" );
	_grade++;
}

void	Bureaucrat::signForm( AForm& form ) const
{
	try
	{
		form.beSigned( *this );
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch ( std::exception& e )
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( const AForm& form ) const
{
	try
	{
		form.execute( *this );
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch ( std::logic_error& e )
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ( out );
}

