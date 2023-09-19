/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:04:15 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/19 13:03:03 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
# define __INTERN_H__

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm	*createShrubberyCreationForm( const std::string& target ) const;
		AForm	*createRobotomyRequestForm( const std::string& target ) const;
		AForm	*createPresidentialPardonForm( const std::string& target ) const;
		AForm	*handleInvalidForm( const std::string& formName ) const;
	public:
		Intern( void );
		Intern( const Intern& intern );
		~Intern( void );
		Intern&	operator=( const Intern& intern );
		AForm	*makeForm( const std::string& formName, const std::string& target ) const;
};

#endif
