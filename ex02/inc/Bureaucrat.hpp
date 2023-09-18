/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:31:21 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/18 12:44:49 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <string>
# include <iostream>
# include "AForm.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1
# define MID_GRADE ((MAX_GRADE - MIN_GRADE) / 2 + MIN_GRADE)

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, unsigned int grade );
		Bureaucrat( const Bureaucrat& bureaucrat );
		~Bureaucrat( void );
		Bureaucrat&		operator=( const Bureaucrat& bureaucrat );
		std::string		getName( void ) const;
		unsigned int	getGrade( void ) const;
		void			incrementGrade( void );
		void			decrementGrade( void );
		void			signForm( AForm& form ) const;
		void			executeForm( const AForm& form ) const;
		class GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException( std::string error_msg );
		};
		class GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException( std::string error_msg );
		};
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif
