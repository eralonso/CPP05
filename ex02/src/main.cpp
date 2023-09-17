/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:53:21 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/17 18:38:50 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>

#define GET_NAME 0
#define GET_SIGN_GRADE 1
#define GET_EXEC_GRADE 2
#define GET_IS_SIGNED 3

// Utils
// Bureaucrat	testConstructorBureaucratGrade( unsigned int grade, int& catched )
// {
// 	Bureaucrat	Joan( "Juan", MIN_GRADE );

// 	catched = 0;
// 	try
// 	{
// 		Bureaucrat	Juan( "Juan", grade );
// 		return ( Juan );
// 	}
// 	catch ( std::exception& e )
// 	{
// 		std::cout << "\tcatch: " << e.what() << std::endl;
// 		catched = 1;
// 	}
// 	return ( Joan );
// }

// Form	testConstructorFormGrade( unsigned int signGrade, unsigned int execGrade, int& catched )
// {
// 	Form	Default( "Unnamed Form", MIN_GRADE, MIN_GRADE );

// 	catched = 0;
// 	try
// 	{
// 		Form	form( "Juan's Form", signGrade, execGrade );
// 		return ( form );
// 	}
// 	catch ( std::out_of_range& e )
// 	{
// 		std::cout << "\tcatch: " << e.what() << std::endl;
// 		catched = 1;
// 	}
// 	return ( Default );
// }

// void	doFormConstructorTest( unsigned int testNumber, std::string testName, \
// 								unsigned int signGrade, unsigned int execGrade )
// {
// 	int	catched;

// 	std::cout << "Test " << testNumber << ": " << testName << " in constructor: Form\t" \
// 		<< "Juan( \"Juan's Form\", " << signGrade <<  ", "<< execGrade << " )"  << std::endl;
// 	testConstructorFormGrade( signGrade, execGrade, catched );
// 	std::cout << "End of test\n"  << std::endl;
// }

// void	doFormGetterTest( unsigned int testNumber, std::string testName, \
// 								Form form, unsigned int mode )
// {
// 	std::cout << "Test " << testNumber << ": " << testName << " in constructor: Form\t" \
// 		<< "form( \"" << form.getName() << "\", " << form.getSignGrade() <<  ", " \
// 		<< form.getExecGrade() << " )"  << std::endl;
// 	switch ( mode )
// 	{
// 		case GET_NAME:
// 			std::cout << "form.getName() = " << form.getName() << std::endl;
// 			break;
// 		case GET_SIGN_GRADE:
// 			std::cout << "form.getSignGrade() = " << form.getSignGrade() << std::endl;
// 			break;
// 		case GET_EXEC_GRADE:
// 			std::cout << "form.getExecGrade() = " << form.getExecGrade() << std::endl;
// 			break;
// 		case GET_IS_SIGNED:
// 			std::cout << "form.getIsSigned() = " << (form.getIsSigned() ? "true" : "false") << std::endl;
// 			break;
// 		default:
// 			std::cout << "Invalid getter mode" << std::endl;
// 			break;
// 	}
// 	std::cout << "End of test\n"  << std::endl;
// }

// void	doBureaucratSignFormTest( unsigned int testNumber, std::string testName, \
// 								Bureaucrat& Juan, Form& form )
// {
// 	std::cout << "Test " << testNumber << ": " << testName << " in signForm method: Form\t" \
// 		<< "form( \"" << form.getName() << "\", " << form.getSignGrade() \
// 		<<  ", "<< form.getExecGrade() << ")" << " && Bureaucrat\tJuan( \" " \
// 		<< Juan.getName() << "\", " << Juan.getGrade() << " )" << " )"  << std::endl;
// 	std::cout << "\tform stats -> " << form << std::endl;
// 	std::cout << "\t";
// 	Juan.signForm( form );
// 	std::cout << "\tform stats -> " << form << std::endl;
// 	std::cout << "End of test\n"  << std::endl;
// }

// // TESTS
// void	testsFormConstructor( void )
// {
// 	//Constructor Tests
	
// 	//	signGrade: Out of range Grades in Form constructor

// 	doFormConstructorTest( 1, "too low signGrade", MIN_GRADE + 1, MID_GRADE );
// 	doFormConstructorTest( 2, "too high signGrade", MAX_GRADE - 1, MID_GRADE );
	
// 	//	execGrade: Out of range Grades in Form constructor

// 	doFormConstructorTest( 3, "too low execGrade", MID_GRADE, MIN_GRADE + 1 );
// 	doFormConstructorTest( 4, "too high execGrade", MID_GRADE, MAX_GRADE - 1 );
	
// 	//	Both: Out of range Grades in Form constructor

// 	doFormConstructorTest( 5, "too low both signGrade and execGrade", \
// 							MIN_GRADE + 1, MIN_GRADE + 1 );
// 	doFormConstructorTest( 6, "too high both signGrade and execGrade", \
// 							MAX_GRADE - 1, MAX_GRADE - 1 );
// 	doFormConstructorTest( 7, "too high signGrade and too low execGrade", \
// 							MAX_GRADE - 1, MIN_GRADE + 1  );
// 	doFormConstructorTest( 8, "too low signGrade and too high execGrade", \
// 							MIN_GRADE + 1, MAX_GRADE - 1  );
// }

// void	testsFormGetters( void )
// {
// 	Form	form( "Juan's Form", MID_GRADE, MIN_GRADE );
// 	Bureaucrat	Juan( "Juan", MID_GRADE );

// 	//Getters Tests
	
// 	//	getName()

// 	doFormGetterTest( 1, "getName()", form, GET_NAME );

// 	//	getsignGrade()

// 	doFormGetterTest( 2, "getSignGrade()", form, GET_SIGN_GRADE );

// 	//	getExecGrade()

// 	doFormGetterTest( 3, "getExecGrade()", form, GET_EXEC_GRADE );

// 	//	getIsSigned(): Before singed

// 	doFormGetterTest( 4, "getIsSigned() [ Before Sign a Form ]", form, GET_IS_SIGNED );

// 	//	getIsSigned(): After singed

// 	Juan.signForm( form );
// 	doFormGetterTest( 5, "getIsSigned() [ After Sign a Form ]", form, GET_IS_SIGNED );
// }


// void	testsBureaucratSignForm( void )
// {
// 	Form		formMinGrade( "Juan's form", MIN_GRADE, MIN_GRADE );
// 	Form		formMidGrade( "Juan's form", MID_GRADE, MID_GRADE );
// 	Form		formMaxGrade( "Juan's form", MAX_GRADE, MAX_GRADE );
// 	Bureaucrat	JuanMinGrade( "Juan", MIN_GRADE );
// 	Bureaucrat	JuanMidGrade( "Juan", MID_GRADE );
// 	Bureaucrat	JuanMaxGrade( "Juan", MAX_GRADE );

// 	//Method Tests
	
// 	//	Invalid Grade to signForm

// 	doBureaucratSignFormTest( 1, "too low signGrade", JuanMinGrade, formMidGrade );

// 	// Limits Grade to signForm and equal grade
// 	doBureaucratSignFormTest( 4, "signGrade equals to Bureaucrat Grade [ MIN GRADE ]", \
// 								JuanMinGrade, formMinGrade );
// 	doBureaucratSignFormTest( 2, "signGrade equals to Bureaucrat Grade [ MID GRADE ]", \
// 								JuanMidGrade, formMidGrade );
// 	doBureaucratSignFormTest( 3, "signGrade equals to Bureaucrat Grade [ MAX GRADE ]", \
// 								JuanMaxGrade, formMaxGrade );

// 	// Form already signed and their priorities
// 	doBureaucratSignFormTest( 5, "form is already signed and valid grade", \
// 								JuanMidGrade, formMidGrade );
// 	doBureaucratSignFormTest( 6, "form is already signed and invalid grade", \
// 								JuanMinGrade, formMidGrade );
// }

void	doCheckFormGradeTest( unsigned int& testNumber, AForm* form, unsigned int signExpectedValue, unsigned int execExpectedValue )
{
	std::cout << "Test " << testNumber++ << ": Check sign grade in " << form->getName() << " class: " \
				<< form->getName() << "\tform" << std::endl;
	std::cout << "\tExpected value: " << signExpectedValue << " | Resultant value: " << form->getSignGrade() << std::endl;
	std::cout << "End of test\n" << std::endl;
	std::cout << "Test " << testNumber++ << ": Check exec grade in " << form->getName() << " class: " \
				<< form->getName() << "\tform" << std::endl;
	std::cout << "\tExpected value: " << execExpectedValue << " | Resultant value: " << form->getExecGrade() << std::endl;
	std::cout << "End of test\n" << std::endl;
}

void	doExecuteFormTest( unsigned int& testNumber, std::string testName, Bureaucrat Juan, AForm* form )
{
	std::cout << "Test " << testNumber++ << ": " << testName << " in executeForm method with \"" << form->getName() << "\" form: " \
				<< "Bureaucrat\tJuan( \"" << Juan.getName() << "\", " << Juan.getGrade() << " ) && " << form->getName() << "\tform( \"" \
				<< static_cast<ShrubberyCreationForm *>(form)->getTarget() << "\" )" << std::endl;
	std::cout << "[ BEFORE ] form stats -> " << *static_cast<ShrubberyCreationForm *>(form) << std::endl;
	std::cout << "\t";
	Juan.executeForm( *form );
	std::cout << "[ AFTER ] form stats -> " << *static_cast<ShrubberyCreationForm *>(form) << std::endl;
	std::cout << "End of test\n" << std::endl;
}

void	testsSCFGrades( void )
{
	AForm			*SCForm = new ShrubberyCreationForm;
	AForm			*RRForm = new RobotomyRequestForm;
	AForm			*PPForm = new PresidentialPardonForm;
	unsigned int	testNumber;

	testNumber = 0;

	//Check correct grades for ShrubberyCreationForm

	doCheckFormGradeTest( testNumber, SCForm, SCF_SIGN_GRADE, SCF_EXEC_GRADE );

	//Check correct grades for RobotomyRequestForm

	doCheckFormGradeTest( testNumber, RRForm, RRF_SIGN_GRADE, RRF_EXEC_GRADE );

	//Check correct grades for PresidentialPardonForm

	doCheckFormGradeTest( testNumber, PPForm, PPF_SIGN_GRADE, PPF_EXEC_GRADE );

	//Clean all dynamic allocated memory
	delete SCForm;
	delete RRForm;
	delete PPForm;
}

void	testsBureaucratExecuteForm( void )
{
	AForm			*SCForm = new ShrubberyCreationForm( "testSCF" );
	AForm			*RRForm = new RobotomyRequestForm( "testRRF" );
	AForm			*PPForm = new PresidentialPardonForm( "testPPF" );
	Bureaucrat		JuanMin( "Mini Juan", MIN_GRADE );
	Bureaucrat		JuanMid( "Medium Juan", MID_GRADE );
	Bureaucrat		JuanMax( "Maximun Juan", MAX_GRADE );
	unsigned int	testNumber;

	testNumber = 0;

	//Check correct grades for ShrubberyCreationForm

	doExecuteFormTest( testNumber, "form isn't signed and too low grade to execute", JuanMin, SCForm );
	doExecuteFormTest( testNumber, "form isn't signed and valid grade to execute", JuanMid, SCForm );
	JuanMid.signForm( *SCForm );
	doExecuteFormTest( testNumber, "form signed but too low grade to execute", JuanMin, SCForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute", JuanMid, SCForm );

	//Check correct grades for RobotomyRequestForm

	doExecuteFormTest( testNumber, "form isn't signed and too low grade to execute", JuanMid, RRForm );
	doExecuteFormTest( testNumber, "form isn't signed and valid grade", JuanMax, RRForm );
	JuanMax.signForm( *RRForm );
	doExecuteFormTest( testNumber, "form signed but too low grade to execute", JuanMin, RRForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute", JuanMax, RRForm );

	//Check correct grades for PresidentialPardonForm

	doExecuteFormTest( testNumber, "form isn't signed and too low grade to execute", JuanMid, PPForm );
	doExecuteFormTest( testNumber, "form isn't signed and valid grade to execute", JuanMax, PPForm );
	JuanMax.signForm( *PPForm );
	doExecuteFormTest( testNumber, "form signed but too low grade to execute", JuanMid, PPForm );
	doExecuteFormTest( testNumber, "form signed and valid grade to execute", JuanMax, PPForm );

	//Clean all dynamic allocated memory
	delete SCForm;
	delete RRForm;
	delete PPForm;
}

bool	executionQuestion( std::string testsName )
{
	std::string	answer;

	std::cout << "Do you want to execute the \"" << testsName << "\" tests [ y / n ]: ";
	std::getline( std::cin, answer );
	if ( answer.compare( "Y" ) == 0 || answer.compare( "y" ) == 0 )
	{
		std::cout << std::endl;
		return ( true );
	}
	return ( false );
}

int	main( void )
{
	std::cout << std::unitbuf;
	if ( executionQuestion( "[ ShruberryCreationForm / RobotomyRequestForm / PresidentialPardonForm ] sign and exec grades" ) == true )
		testsSCFGrades();
	std::cout << std::endl;

	if ( executionQuestion( "Bureaucrat executeForm && [ ShruberryCreationForm / RobotomyRequestForm / PresidentialPardonForm ] execute methods" ) == true )
		testsBureaucratExecuteForm();
	std::cout << std::endl;

	return ( 0 );
}
