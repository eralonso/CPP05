/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:21:57 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/17 14:15:17 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_H__
# define __SHRUBBERYCREATIONFORM_H__

# include "AForm.hpp"
# include <fstream>

# define SCF_SIGN_GRADE 145
# define SCF_EXEC_GRADE 137

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string	_target;
		void				FormExecute( void ) const;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& SCForm );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& SCForm );
		std::string				getTarget( void ) const;
};

std::ostream&	operator<<( std::ostream& out, const ShrubberyCreationForm& SCForm );

#endif
