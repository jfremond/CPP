/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:15:39 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/14 06:36:25 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

#include <iostream>
#include <cstdlib> //atof

int identify(std::string arg)
{
	if (arg.length() == 1)
		return (1);
	else
	{
		if (arg == "inf" || arg == "+inf" || arg == "-inf"  || arg == "nan")
			return (3);
		if (arg == "inff" || arg == "+inff" || arg == "-inff"  || arg == "nanf")
			return (4);
		else
			if (arg[arg.length() - 1] == 'f')
				return (4);
	}
	return (2);
}

void print_char(std::string arg)
{
	double value = atof(arg.c_str());
	char c = static_cast<char>(value);
	if (c < 0 || c > 127 || (arg.length() > 1 && !isdigit(arg[0])))
		std::cout << "char: Impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << RED << "Usage: ./Convert [argument]" << RESET << std::endl;
	else
	{
		int	type = -1;
		std::string arg = argv[1];
		type = identify(arg);
		std::cout << type << std::endl;
		print_char(arg);
	//	print conversions;
	}
}