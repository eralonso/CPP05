/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:31:21 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/09 19:37:23 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT__
# define __BUREAUCRAT__

# include <string>
# include <iostream>

# define MIN_GRADE 150
# define MAX_GRADE 1

class Bureaucrat
{
	private:
		std::string		_name;
		unsigned int	_grade;
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
		class GradeTooHighException: public std::exception
		{
			const char * what () const throw()
			{
				return ( "Grade too high" );
			}
		};
		class GradeTooLowException: public std::exception
		{
			const char * what () const throw()
			{
				return ( "Grade too low" );
			}
		};
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif
