/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:20:02 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/19 17:54:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm( "ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE ), \
														_target( "Unnamed Target" ) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm( "ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE ), \
														_target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& SCForm ): AForm( "ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE ), \
																					_target( SCForm._target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& SCForm )
{
	AForm::operator=( SCForm );
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return ( _target );
}

void	ShrubberyCreationForm::FormExecute( void ) const
{
	std::ofstream	out;

	out.open( _target + "_shrubbery" );
	if ( out.is_open() == false )
	{
		std::cerr << "Error trying to open file " << _target + "_shrubbery"  << std::endl;
		return ;
	}
	out << "\
              _{\\ _{\\{\\/}/}/}__\n\
             {/{/\\}{/{/\\}(\\}{/\\} _\n\
            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n\
         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n\
        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n\
       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n\
      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n\
      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n\
     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n\
      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n\
       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n\
      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n\
       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n\
         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n\
          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n\
            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n\
             {/{\\{\\{\\/}/}{\\{\\}/}\n\
              {){/ {\\/}{\\/} \\}\\}\n\
              (_)  \\.-'.-/\n\
          __...--- |'-.-'| --...__\n\
   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n\
 -\"    ' .  . '    |.'-._| '  . .  '   jro\n\
 .  '-  '    .--'  | '-.'|    .  '  . '\n\
          ' ..     |'-_.-|\n\
  .  '  .       _.-|-._ -|-._  .  '  .\n\
              .'   |'- .-|   '.\n\
  ..-'   ' .  '.   `-._.-�   .'  '  - .\n\
   .-' '        '-._______.-'     '  .\n\
        .      ~,\n\
    .       .   |\\   .    ' '-.\n\
    ___________/  \\____________\n\
   /  Why is it, when you want \\\n\
  |  something, it is so damn   |\n\
  |    much work to get it?     |\n\
   \\___________________________/\n\
  " << std::endl;
  out.close();
}

std::ostream&	operator<<( std::ostream& out, const ShrubberyCreationForm& SCForm )
{
	out << "Name: " << SCForm.getName() << " && Target: " << SCForm.getTarget() \
		<< " && Sign grade: " << SCForm.getSignGrade() << " && Exec grade: " \
		<< SCForm.getExecGrade() << " && Is Signed: " << ( SCForm.getIsSigned() ? "true" : "false");
	return ( out );
}
