/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:41 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/15 18:39:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (BitcoinExchange::print_error(ERR_ARG_NUM));
	try
	{
		BitcoinExchange	btc(argv[1]);
		std::cout << ORANGE << "----- DISPLAY CONTENTS OF DATABASE -----" << RESET << std::endl;
		int	elem_str = 0;
		int	elem_float = 0;
		for (std::list<std::string>::iterator it = btc._db_date.begin(); it != btc._db_date.end(); it++)
		{
			std::cout << *it << std::endl;
			elem_str++;
		}
		for (std::list<float>::iterator it = btc._db_price.begin(); it != btc._db_price.end(); it++)
		{
			std::cout << *it << std::endl;
			elem_float++;
		}
		std::cout << elem_str << " " << elem_float << std::endl;
	}
	catch(const std::exception& e)
	{
		return (BitcoinExchange::print_error(e.what()));
	}
	return (0);
}