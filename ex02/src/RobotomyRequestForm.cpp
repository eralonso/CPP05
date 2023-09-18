/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:20:02 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/18 12:08:20 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm( "RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE ), \
														_target( "Unnamed Target" ) {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm( "RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE ), \
														_target( target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& RRForm ): AForm( "RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE ), \
																					_target( RRForm._target ) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& RRForm )
{
	AForm::operator=( RRForm );
	return (*this);
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return ( _target );
}

void	RobotomyRequestForm::FormExecute( void ) const
{
	std::cout << "Some drilling noise [ bbbbbzzzzzzzzzzzzzzzzzzb ] ... -> " \
				<< (rand() % 2 == 0 ? _target + " has been robotomized successfully" : \
				"robotomy failed with " + _target ) << std::endl;
}

std::ostream&	operator<<( std::ostream& out, const RobotomyRequestForm& RRForm )
{
	out << "Name: " << RRForm.getName() << " && Target: " << RRForm.getTarget() \
		<< " && Sign grade: " << RRForm.getSignGrade() << " && Exec grade: " \
		<< RRForm.getExecGrade() << " && Is Signed: " << ( RRForm.getIsSigned() ? "true" : "false");
	return ( out );
}
