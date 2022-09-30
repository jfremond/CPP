/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:56:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/30 00:54:08 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << YELLOW << "========== CREATING THE WRONG KIND OF FORM ==========" << RESET << std::endl;
	try
	{
		Intern		intern;
		Form		*wrong;
		Bureaucrat	jeff("Jeff", 1);
		
		wrong = intern.makeForm("wrong", "Form01");
		jeff.signForm(*wrong);
		delete wrong;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== CREATING A SHRUBBERYFORM ==========" << RESET << std::endl;
	try
	{
		Intern		intern;
		Form		*scf;
		Bureaucrat	jeff("Jeff", 1);
		
		scf = intern.makeForm("shrubbery creation", "Form02");
		jeff.signForm(*scf);
		jeff.executeForm(*scf);
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== CREATING A ROBOTOMYFORM ==========" << RESET << std::endl;
	try
	{
		Intern		intern;
		Form		*rrf;
		Bureaucrat	jeff("Jeff", 1);
		
		rrf = intern.makeForm("robotomy request", "Form03");
		jeff.signForm(*rrf);
		jeff.executeForm(*rrf);
		jeff.executeForm(*rrf);
		jeff.executeForm(*rrf);
		jeff.executeForm(*rrf);
		jeff.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== CREATING A PRESIDENTIALFORM ==========" << RESET << std::endl;
	try
	{
		Intern		intern;
		Form		*ppf;
		Bureaucrat	jeff("Jeff", 1);
		
		ppf = intern.makeForm("presidential pardon", "Form04");
		jeff.signForm(*ppf);
		jeff.executeForm(*ppf);
		delete ppf;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
