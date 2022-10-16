/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:43:24 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/16 06:07:59 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

struct	Data
{
	std::string	str;
	int			value;
};


uintptr_t	serialize(Data *ptr)
{
	uintptr_t	res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data	*deserialize(uintptr_t raw)
{
	Data	*res = reinterpret_cast<Data *>(raw);
	return res;
}

int	main(void)
{
	std::cout << YELLOW << "INITIALIZING A DATA STRUCT" << RESET << std::endl;
	Data	*src = new Data;
	src->str = "This is a string";
	src->value = 42;
	std::cout << ORANGE <<"src->str: " << RESET << src->str << std::endl;
	std::cout << ORANGE << "src->value: " << RESET << src->value << std::endl << std::endl;

	Data	*cpy;
	uintptr_t	raw;
	
	raw = serialize(src);
	cpy = deserialize(raw);
	
	std::cout << YELLOW << "DISPLAYING THE CONTENTS OF THE TWO DATA STRUCTURES" << RESET << std::endl;
	std::cout << YELLOW << "src structure" << RESET << std::endl;
	std::cout << ORANGE <<"src->str: " << RESET << src->str << std::endl;
	std::cout << ORANGE << "src->value: " << RESET << src->value << std::endl << std::endl;
	std::cout << YELLOW << "cpy structure" << RESET << std::endl;
	std::cout << ORANGE <<"cpy->str: " << RESET << cpy->str << std::endl;
	std::cout << ORANGE << "cpy->value: " << RESET << cpy->value << std::endl;
	delete src;
	return (0);
}