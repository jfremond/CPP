/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:56:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/21 23:55:21 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << YELLOW << "========== GRADE TOO HIGH ==========" << RESET << std::endl;
	try
	{
		Bureaucrat	tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== GRADE TOO LOW ==========" << RESET << std::endl;
	try
	{
		Bureaucrat	tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== HIGHEST LIMIT ==========" << RESET << std::endl;
	try
	{
		Bureaucrat	highLimit("HighLimit", 1);
		
		std::cout << highLimit << std::endl;
		std::cout << ORANGE << "Incrementing the grade (GradeTooHighException thrown)" << RESET << std::endl;
		highLimit.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== LOWEST LIMIT ==========" << RESET << std::endl;
	try
	{
		Bureaucrat	lowLimit("LowLimit", 150);
		
		std::cout << lowLimit << std::endl;
		std::cout << ORANGE << "Decrementing the grade (GradeTooLowException thrown)" << RESET << std::endl;
		lowLimit.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== VALID BUREAUCRAT ==========" << RESET << std::endl;
	{
		Bureaucrat	valid("Valid", 75);
		
		std::cout << valid << std::endl;
		std::cout << ORANGE << "Decrementing the grade 3 times" << RESET << std::endl;
		valid.decrementGrade();
		valid.decrementGrade();
		valid.decrementGrade();
		std::cout << valid;
		std::cout << ORANGE << "Incrementing the grade 4 times" << RESET << std::endl;
		valid.incrementGrade();
		valid.incrementGrade();
		valid.incrementGrade();
		valid.incrementGrade();
		std::cout << valid;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== COPY CONSTRUCTOR ==========" << RESET << std::endl;
	{
		Bureaucrat	src("Jack", 12);
		Bureaucrat	cpy(src);
		
		std::cout << src << std::endl;
		std::cout << cpy << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "========== ASSIGNMENT OPERATOR OVERLOAD ==========" << RESET << std::endl;
	{
		Bureaucrat	src("Jack", 12);
		Bureaucrat	cpy;
		
		std::cout << src << std::endl;
		std::cout << cpy << std::endl;

		cpy = src;
		std::cout << src << std::endl;
		std::cout << cpy << std::endl;
	}
}
