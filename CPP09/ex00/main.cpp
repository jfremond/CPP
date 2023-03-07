/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:41 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/07 18:40:54 by jfremond         ###   ########.fr       */
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
	}
	catch(const std::exception& e)
	{
		return (BitcoinExchange::print_error(e.what()));
	}
	
	return (0);
}