/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:23:29 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/06 01:36:17 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW << "========== GRADE TO SIGN TOO HIGH ==========" << RESET << std::endl;
	try
	{
		Form	H34("H34", 0, 12);
		std::cout << H34;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== GRADE TO EXECUTE TOO HIGH ==========" << RESET << std::endl;
	try
	{
		Form	K42("K42", 12, -18);
		std::cout << K42;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== GRADE TO SIGN TOO LOW ==========" << RESET << std::endl;
	try
	{
		Form	S31("S31", 313, 53);
		std::cout << S31;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== GRADE TO EXECUTE TOO LOW ==========" << RESET << std::endl;
	try
	{
		Form	G02("G02", 53, 313);
		std::cout << G02;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== FORM VALID BUT CAN'T BE SIGNED ==========" << RESET << std::endl;
	try
	{
		Form		V01("V01", 130, 50);
		Bureaucrat	fred("Fred", 138);
		std::cout << V01;
		std::cout << fred;
		V01.beSigned(fred);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== INCREASING THE BUREACRAT VALUE TO SIGN THE FORM ==========" << RESET << std::endl;
	try
	{
		Form		V02("V02", 149, 50);
		Bureaucrat	bill("Bill", 150);
		std::cout << V02 << std::endl;
		std::cout << bill << std::endl;
		bill.incrementGrade();
		std::cout << bill << std::endl;
		V02.beSigned(bill);
		std::cout << V02 << std::endl;
		V02.beSigned(bill);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== DECREASING THE BUREACRAT VALUE TO NOT SIGN THE FORM ==========" << RESET << std::endl;
	try
	{
		Form		V03("V03", 130, 50);
		Form		V04("V04", 130, 50);
		Bureaucrat	emma("Emma", 130);
		std::cout << V03 << std::endl;
		std::cout << emma << std::endl;
		V03.beSigned(emma);
		emma.decrementGrade();
		std::cout << emma << std::endl;
		V04.beSigned(emma);		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;


	
	// std::cout << YELLOW << "========== GRADE TOO HIGH ==========" << RESET << std::endl;
	// try
	// {
	// 	Bureaucrat	tooHigh("TooHigh", 0);
	// 	std::cout << tooHigh << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;
	// std::cout << YELLOW << "========== GRADE TOO LOW ==========" << RESET << std::endl;
	// try
	// {
	// 	Bureaucrat	tooLow("TooLow", 151);
	// 	std::cout << tooLow << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;
	// std::cout << YELLOW << "========== HIGHEST LIMIT ==========" << RESET << std::endl;
	// try
	// {
	// 	Bureaucrat	highLimit("HighLimit", 1);
	// 	std::cout << highLimit << std::endl;
	// 	std::cout << ORANGE << "Incrementing the grade (GradeTooHighException thrown)" << RESET << std::endl;
	// 	highLimit.incrementGrade();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;
	// std::cout << YELLOW << "========== LOWEST LIMIT ==========" << RESET << std::endl;
	// try
	// {
	// 	Bureaucrat	lowLimit("LowLimit", 150);
	// 	std::cout << lowLimit << std::endl;
	// 	std::cout << ORANGE << "Decrementing the grade (GradeTooHLowException thrown)" << RESET << std::endl;
	// 	lowLimit.decrementGrade();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << YELLOW << "========== VALID BUREAUCRAT ==========" << RESET << std::endl;
	// try
	// {
	// 	Bureaucrat	valid("Valid", 75);
	// 	std::cout << valid << std::endl;
	// 	std::cout << ORANGE << "Decrementing the grade 3 times" << RESET << std::endl;
	// 	valid.decrementGrade();
	// 	valid.decrementGrade();
	// 	valid.decrementGrade();
	// 	std::cout << valid;
	// 	std::cout << ORANGE << "Incrementing the grade 4 times" << RESET << std::endl;
	// 	valid.incrementGrade();
	// 	valid.incrementGrade();
	// 	valid.incrementGrade();
	// 	valid.incrementGrade();
	// 	std::cout << valid;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}