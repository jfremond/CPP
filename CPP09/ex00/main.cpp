/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:27:12 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/12 22:33:50 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw BitcoinExchange::CannotOpenFile();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	
	BitcoinExchange	btc;
	try
	{
		btc.parseFile(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
