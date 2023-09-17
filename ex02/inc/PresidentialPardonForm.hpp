/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:21:57 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/17 14:14:51 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_H__
# define __PRESIDENTIALPARDONFORM_H__

# include "AForm.hpp"
# include <fstream>

# define PPF_SIGN_GRADE 25
# define PPF_EXEC_GRADE 5

class PresidentialPardonForm: public AForm
{
	private:
		const std::string	_target;
		void				FormExecute( void ) const;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& PPForm );
		~PresidentialPardonForm( void );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& PPForm );
		std::string				getTarget( void ) const;
};

std::ostream&	operator<<( std::ostream& out, const PresidentialPardonForm& PPForm );

#endif
