/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:56:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/21 23:53:56 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW << "========== DEFAULT FORM ==========" << RESET << std::endl;
	try
	{
		Form	defaultForm;
		std::cout << defaultForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too high) ==========" << RESET << std::endl;
	try
	{
		Form	D43("D43", 0, 43);
		std::cout << D43 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too high) ==========" << RESET << std::endl;
	try
	{
		Form	D43("D43", 43, 0);
		std::cout << D43 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too low) ==========" << RESET << std::endl;
	try
	{
		Form	J56("J56", 151, 56);
		std::cout << J56 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too low) ==========" << RESET << std::endl;
	try
	{
		Form	J56("J56", 56, 151);
		std::cout << J56 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== VALID FORM THAT CAN'T BE SIGNED (beSigned) ==========" << RESET << std::endl;
	try
	{
		Bureaucrat	greg("Greg", 120);
		Form		F84("F84", 115, 125);
		F84.beSigned(greg);
		greg.signForm(F84);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== VALID FORM THAT CAN'T BE SIGNED (signForm) ==========" << RESET << std::endl;
	try
	{
		Bureaucrat	greg("Greg", 120);
		Form		F84("F84", 115, 125);
		greg.signForm(F84);
		F84.beSigned(greg);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== VALID FORM THAT WILL BE SIGNED ==========" << RESET << std::endl;
	{
		Bureaucrat	rich("Richard", 115);
		Form		G55("G55", 115, 125);
		std::cout << rich << std::endl;
		std::cout << G55 << std::endl;
		G55.beSigned(rich);
		rich.signForm(G55);
		std::cout << std::endl;
		std::cout << G55 << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== COPY CONSTRUCTOR ==========" << RESET << std::endl;
	{
		Form		src("src", 115, 125);
		Form		cpy(src);

		std::cout << src << std::endl;
		std::cout << cpy << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== ASSIGNMENT OPERATOR OVERLOAD ==========" << RESET << std::endl;
	{
		Bureaucrat	pete("Pete", 111);
		Form		src("src", 115, 125);
		Form		cpy("cpy", 143, 124);

		std::cout << src << std::endl;
		std::cout << cpy << std::endl;
		pete.signForm(src);
		cpy = src;
		std::cout << src << std::endl;
		std::cout << cpy << std::endl;
	}
}
