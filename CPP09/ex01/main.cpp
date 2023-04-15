/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 05:05:03 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/12 22:07:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			throw RPN::WrongUsage();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	RPN	rpn;
	try
	{
		rpn.checkStr(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		rpn.doOpe(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		rpn.printRes();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}
