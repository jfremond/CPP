/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:56:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/25 00:43:47 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	// {
	// 	std::cout << YELLOW << "========== DEFAULT SHRUBBERYFORM ===========" << RESET << std::endl;
	// 	ShrubberyCreationForm DSF;
	// 	std::cout << DSF << std::endl;
	// 	std::cout << std::endl;
		
	// 	std::cout << YELLOW << "========== NAMED SHRUBBERYFORM ==========" << RESET << std::endl;
	// 	ShrubberyCreationForm SF76("SF76");
	// 	std::cout << SF76 << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO SIGN FORM =========" << RESET << std::endl;
	// 	try
	// 	{
	// 		ShrubberyCreationForm	SF86("SF86");
	// 		Bureaucrat				bob("Bob", 146);

	// 		SF86.beSigned(bob);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO EXECUTE FORM ==========" << RESET << std::endl;
	// 	try
	// 	{
	// 		ShrubberyCreationForm	SF27("SF27");
	// 		Bureaucrat				bob("Bob", 138);

	// 		SF27.beSigned(bob);
	// 		bob.signForm(SF27);
	// 		// SF27.execute(bob);
	// 		bob.executeForm(SF27);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== ATTEMPTING TO EXECTUTE A FORM NOT SIGNED =========" << RESET << std::endl;
	// 	try
	// 	{
	// 		ShrubberyCreationForm	SF72("SF72");
	// 		Bureaucrat				john("John", 110);
			
	// 		john.executeForm(SF72);
	// 		// SF72.execute(john);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;
	
	// 	std::cout << YELLOW << "========== ALL GOOD HERE ==========" << RESET << std::endl;
	// 	try
	// 	{
	// 		ShrubberyCreationForm	SF66("SF66");
	// 		Bureaucrat				jack("Jack", 110);
		
	// 		SF66.beSigned(jack);
	// 		jack.signForm(SF66);
	// 		jack.executeForm(SF66);
	// 		// SF66.execute(jack);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << YELLOW << "========== DEFAULT ROBOTOMYFORM ===========" << RESET << std::endl;
	// 	RobotomyRequestForm RRF;
	// 	std::cout << RRF << std::endl;
	// 	std::cout << std::endl;
		
	// 	std::cout << YELLOW << "========== NAMED ROBOTOMYFORM ==========" << RESET << std::endl;
	// 	RobotomyRequestForm RF76("RF76");
	// 	std::cout << RF76 << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO SIGN FORM =========" << RESET << std::endl;
	// 	try
	// 	{
	// 		RobotomyRequestForm	RF86("RF86");
	// 		Bureaucrat			bob("Bob", 73);

	// 		RF86.beSigned(bob);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO EXECUTE FORM ==========" << RESET << std::endl;
	// 	try
	// 	{
	// 		RobotomyRequestForm	RF27("RF27");
	// 		Bureaucrat			bob("Bob", 46);

	// 		RF27.beSigned(bob);
	// 		bob.signForm(RF27);
	// 		// RF27.execute(bob);
	// 		bob.executeForm(RF27);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== ATTEMPTING TO EXECTUTE A FORM NOT SIGNED =========" << RESET << std::endl;
	// 	try
	// 	{
	// 		RobotomyRequestForm	RF72("RF72");
	// 		Bureaucrat			john("John", 40);
			
	// 		john.executeForm(RF72);
	// 		// RF72.execute(john);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;
	
	// 	std::cout << YELLOW << "========== ALL GOOD HERE ==========" << RESET << std::endl;
	// 	try
	// 	{
	// 		RobotomyRequestForm	RF66("RF66");
	// 		Bureaucrat			jack("Jack", 40);
		
	// 		RF66.beSigned(jack);
	// 		jack.signForm(RF66);
	// 		RF66.execute(jack);
	// 		RF66.execute(jack);
	// 		RF66.execute(jack);
	// 		RF66.execute(jack);
	// 		RF66.execute(jack);
	// 		RF66.execute(jack);
	// 		// jack.executeForm(RF66);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << YELLOW << "========== DEFAULT PRESIDENTIALPARDONFORM ===========" << RESET << std::endl;
	// 	PresidentialPardonForm PPF;
	// 	std::cout << PPF << std::endl;
	// 	std::cout << std::endl;
		
	// 	std::cout << YELLOW << "========== NAMED PRESIDENTIALPARDONFORM ==========" << RESET << std::endl;
	// 	PresidentialPardonForm PP76("PP76");
	// 	std::cout << PP76 << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO SIGN FORM =========" << RESET << std::endl;
	// 	try
	// 	{
	// 		PresidentialPardonForm	PP86("PP86");
	// 		Bureaucrat				bob("Bob", 26);

	// 		PP86.beSigned(bob);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO EXECUTE FORM ==========" << RESET << std::endl;
	// 	try
	// 	{
	// 		PresidentialPardonForm	PP27("PP27");
	// 		Bureaucrat				bob("Bob", 6);

	// 		PP27.beSigned(bob);
	// 		bob.signForm(PP27);
	// 		// PP27.execute(bob);
	// 		bob.executeForm(PP27);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << YELLOW << "========== ATTEMPTING TO EXECTUTE A FORM NOT SIGNED =========" << RESET << std::endl;
	// 	try
	// 	{
	// 		PresidentialPardonForm	PP72("PP72");
	// 		Bureaucrat				john("John", 3);
			
	// 		john.executeForm(PP72);
	// 		// PP72.execute(john);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;
	
	// 	std::cout << YELLOW << "========== ALL GOOD HERE ==========" << RESET << std::endl;
	// 	try
	// 	{
	// 		PresidentialPardonForm	PP66("PP66");
	// 		Bureaucrat				jack("Jack", 3);
		
	// 		PP66.beSigned(jack);
	// 		jack.signForm(PP66);
	// 		PP66.execute(jack);
	// 		PP66.execute(jack);
	// 		PP66.execute(jack);
	// 		PP66.execute(jack);
	// 		PP66.execute(jack);
	// 		PP66.execute(jack);
	// 		// jack.executeForm(PP66);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << '\n';
	// 	}
	// 	std::cout << std::endl;
	// }
	try
	{
		Intern	intern;
		Form	*wrong;
		
		wrong = intern.makeForm("shrubbery creation", "pouet");
		Bureaucrat	test("test", 1);

		test.signForm(*wrong);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
