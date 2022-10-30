/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:25:09 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/17 07:32:52 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

int	test_convertor(Convertor convert, std::string arg)
{
	int type = convert.identify(arg);
	switch (type)
	{
		case 1:
			convert.convert_from_char(arg[0]);
			break;
		case 2:
			convert.convert_from_int(atoi(arg.c_str()));
			break;
		case 3:
			convert.convert_from_float(strtof(arg.c_str(), NULL));
			break;
		case 4:
			convert.convert_from_double(strtod(arg.c_str(), NULL));
			break;
		default:
			return (convert.print_impossible());
	}
	convert.print_char(arg);
	convert.print_int(arg);
	convert.print_float();
	convert.print_double();
	return (0);
}

int	main(void)
{
	Convertor convert;
	std::cout << YELLOW << "IMPOSSIBLE TEST" << RESET << std::endl;
	test_convertor(convert, "hello");
	std::cout << std::endl;
	std::cout << YELLOW << "CHAR TEST" << RESET << std::endl;
	test_convertor(convert, "a");
	std::cout << std::endl;
	std::cout << YELLOW << "INT TEST" << RESET << std::endl;
	test_convertor(convert, "3432");
	std::cout << std::endl;
	std::cout << YELLOW << "FLOAT TEST" << RESET << std::endl;
	test_convertor(convert, "546546343636.0544456f");
	std::cout << std::endl;
	std::cout << YELLOW << "DOUBLE TEST" << RESET << std::endl;
	test_convertor(convert, "1234.5678");
	std::cout << std::endl;
	std::cout << YELLOW << "INF TEST" << RESET << std::endl;
	test_convertor(convert, "-inf");
	std::cout << std::endl;
	test_convertor(convert, "+inff");
	std::cout << std::endl;
	std::cout << YELLOW << "NAN TEST" << RESET << std::endl;
	test_convertor(convert, "nan");
	std::cout << std::endl;
	test_convertor(convert, "nanf");
	std::cout << std::endl;
	return (0);
}