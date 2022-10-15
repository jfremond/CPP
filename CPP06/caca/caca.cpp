/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caca.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:59:22 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/14 02:20:05 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caca.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw InvalidNumberOfArgsException();
		if (determineType(argv[1]) == -1)
			throw InvalidArgumentException();
		print_char(argv[1]);
		// print all
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}