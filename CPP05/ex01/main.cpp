/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:56:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/29 16:56:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW << "========== DEFAULT FORM ==========" << RESET << std::endl;
	{
		Form	defaultForm;
		std::cout << defaultForm << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too high) ==========" << RESET << std::endl;
	try
	{
		Form	F43("F43", 0, 43);
		std::cout << F43 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too high) ==========" << RESET << std::endl;
	try
	{
		Form	F43("F43", 43, 0);
		std::cout << F43 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too low) ==========" << RESET << std::endl;
	try
	{
		Form	F56("F56", 151, 56);
		std::cout << F56 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INVALID FORM (Grade too low) ==========" << RESET << std::endl;
	try
	{
		Form	F56("F56", 56, 151);
		std::cout << F56 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== VALID FORM THAT CAN'T BE SIGNED ==========" << RESET << std::endl;
	try
	{
		Bureaucrat	greg("Greg", 120);
		Form		F84("F84", 115, 125);
		greg.signForm(F84);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== VALID FORM THAT WILL BE SIGNED ==========" << RESET << std::endl;
	{
		Bureaucrat	rich("Richard", 115);
		Form		F55("F55", 115, 125);
		std::cout << rich << std::endl;
		std::cout << F55 << std::endl;
		rich.signForm(F55);
		std::cout << std::endl;
		std::cout << F55 << std::endl;
	}
}
