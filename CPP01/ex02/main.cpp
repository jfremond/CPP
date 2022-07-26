/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:17:59 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:23 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define ORANGE	"\033[38;2;255;165;0m"	/* Orange */
#define YELLOW  "\033[33m"				/* Yellow */
#define RESET   "\033[0m"

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << ORANGE <<  "Memory address of the string" << RESET << std::endl;
	std::cout << YELLOW << "str: " << RESET << &str << std::endl;
	std::cout << YELLOW << "stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << YELLOW << "stringREF: " << RESET << &stringREF << std::endl << std::endl;

	std::cout << ORANGE << "Value of the string" << RESET << std::endl;
	std::cout << YELLOW << "str: " << RESET << str << std::endl;
	std::cout << YELLOW << "stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << YELLOW << "stringREF: " << RESET<< stringREF << std::endl;
}
