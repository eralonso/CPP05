
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:31:21 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/11 10:35:12 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <string>
# include <iostream>

# define MIN_GRADE 150
# define MAX_GRADE 1
# define MID_GRADE ((MAX_GRADE - MIN_GRADE) / 2 + MIN_GRADE)

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
