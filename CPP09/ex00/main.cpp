/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:27:12 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/28 05:18:12 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	BitcoinExchange	test(argv[1]);
	// test._printRes(getError());
	// test.printData();
	return (0);
}
