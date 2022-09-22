/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:56:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/22 19:12:38 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << YELLOW << "========== DEFAULT SHRUBBERYFORM ===========" << RESET << std::endl;
	ShrubberyCreationForm DSF;
	std::cout << DSF << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << "========== NAMED SHRUBBERYFORM ==========" << RESET << std::endl;
	ShrubberyCreationForm SF76("SF76");
	std::cout << SF76 << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO SIGN FORM =========" << RESET << std::endl;
	try
	{
		ShrubberyCreationForm	SF86("SF86");
		Bureaucrat				bob("Bob", 146);

		SF86.beSigned(bob);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << YELLOW << "========== BUREAUCRAT GRADE TOO LOW TO EXECUTE FORM ==========" << RESET << std::endl;
	try
	{
		ShrubberyCreationForm	SF27("SF27");
		Bureaucrat				bob("Bob", 138);

		SF27.beSigned(bob);
		bob.signForm(SF27);
		// SF27.execute(bob);
		bob.executeForm(SF27);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << YELLOW << "========== ATTEMPTING TO EXECTUTE A FORM NOT SIGNED =========" << RESET << std::endl;
	try
	{
		ShrubberyCreationForm	SF72("SF72");
		Bureaucrat				john("John", 110);
		
		john.executeForm(SF72);
		// SF72.execute(john);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	
	std::cout << YELLOW << "========== ALL GOOD HERE ==========" << RESET << std::endl;
	try
	{
		ShrubberyCreationForm	SF66("SF66");
		Bureaucrat				jack("Jack", 110);
		
		SF66.beSigned(jack);
		jack.signForm(SF66);
		SF66.execute(jack);
		// jack.executeForm(SF66);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
}
