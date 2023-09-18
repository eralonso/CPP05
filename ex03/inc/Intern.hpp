/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:04:15 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/18 14:48:29 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
# define __INTERN_H__

# include "AForm.hpp"
# include "ShruberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm	*createShruberryCreationForm( const std::string& formName, const std::string& target );
		AForm	*createRobotomyRequestForm( const std::string& formName, const std::string& target );
		AForm	*createPresidentialPardonForm( const std::string& formName, const std::string& target );
	public:
		Intern( void );
		Intern( const Intern& intern );
		~Intern( void );
		Intern&	operator=( const Intern& intern );
		AForm	*makeForm( const std::string& formName, const std::string& target ) const;
};

#endif
