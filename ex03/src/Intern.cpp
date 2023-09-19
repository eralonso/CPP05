/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:13:19 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/19 13:48:11 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& intern )
{
	( void ) intern;
}

Intern::~Intern( void ) {}

Intern&	Intern::operator=( const Intern& intern )
{
	( void )intern;
	return ( *this );
}

AForm	*Intern::createShrubberyCreationForm( const std::string& target ) const
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return ( new ShrubberyCreationForm( target ) );
}

AForm	*Intern::createRobotomyRequestForm( const std::string& target ) const
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return ( new RobotomyRequestForm( target ) );
}

AForm	*Intern::createPresidentialPardonForm( const std::string& target ) const
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return ( new PresidentialPardonForm( target ) );
}

AForm	*Intern::handleInvalidForm( const std::string& formName ) const
{
	std::cerr << "\"" << formName << "\" form doesn't exist" << std::endl;
	return ( NULL );
}

AForm	*Intern::makeForm( const std::string& formName, const std::string& target ) const
{
	unsigned int	i;
	std::string		parameter[ 4 ] = { target, target, target, formName };
	std::string		forms[ 3 ] = { "shrubbery creation", \
									"robotomy request", \
									"presidential pardon" };
	AForm			*(Intern::*createForm[ 4 ])( const std::string& ) const = { \
										&Intern::createShrubberyCreationForm, \
										&Intern::createRobotomyRequestForm, \
										&Intern::createPresidentialPardonForm, \
										&Intern::handleInvalidForm };
	
	for ( i = 0; i < 3 && formName.compare( forms[ i ] ); i++ )
		;
	return ( (this->*createForm[ i ])( parameter[ i ] ) );
}
