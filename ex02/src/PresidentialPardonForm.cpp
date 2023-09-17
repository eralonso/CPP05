/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:20:02 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/17 18:24:38 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm( "PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE ), \
														_target( "Unnamed Target" ) {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm( "PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE ), \
														_target( target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& PPForm ): AForm( "PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE ), \
																					_target( PPForm._target ) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& PPForm )
{
	AForm::operator=( PPForm );
	return (*this);
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return ( _target );
}

void	PresidentialPardonForm::FormExecute( void ) const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream&	operator<<( std::ostream& out, const PresidentialPardonForm& PPForm )
{
	out << "Name: " << PPForm.getName() << " && Target: " << PPForm.getTarget() \
		<< " && Sign grade: " << PPForm.getSignGrade() << " && Exec grade: " \
		<< PPForm.getExecGrade() << " && Is Signed: " << ( PPForm.getIsSigned() ? "true" : "false");
	return ( out );
}
