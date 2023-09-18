/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:21:57 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/17 14:14:44 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_H__
# define __ROBOTOMYREQUESTFORM_H__

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>

# define RRF_SIGN_GRADE 72
# define RRF_EXEC_GRADE 45

class RobotomyRequestForm: public AForm
{
	private:
		const std::string	_target;
		void				FormExecute( void ) const;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& RRForm );
		~RobotomyRequestForm( void );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& RRForm );
		std::string				getTarget( void ) const;
};

std::ostream&	operator<<( std::ostream& out, const RobotomyRequestForm& RRForm );

#endif
