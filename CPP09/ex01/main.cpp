/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 05:05:03 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/03 15:12:03 by jfremond         ###   ########.fr       */
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
		rpn.check_str(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		rpn.do_ope(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		rpn.print_res();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}