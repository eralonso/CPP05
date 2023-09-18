/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:13:19 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/18 14:51:32 by eralonso         ###   ########.fr       */
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

AForm	*Intern::makeForm( const std::string& formName, const std::string& target )
{
	AForm	*(*createForm[ 3 ])( const std::string& formName, const std::string& target );

	createForm[ 0 ]	= &createShruberryCreationForm;
	createForm[ 1 ]	= &createRobotomyRequestForm;
	createForm[ 2 ]	= &createPresidentialPardonForm;
}
