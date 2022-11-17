/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:16:49 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/17 06:38:56 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	{		
		std::cout << YELLOW << "SWAP THEN MIN/MAX WITH INT" << RESET << std::endl;
		int	a = 2;
		int b = 3;
	
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		::swap(a, b);
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		std::cout << ORANGE << "min(a, b) = " << RESET << ::min(a, b) << std::endl;
		std::cout << ORANGE << "max(a, b) = " << RESET << ::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	{		
		std::cout << YELLOW << "SWAP THEN MIN/MAX WITH FLOAT" << RESET << std::endl;
		float	a = 43.14f;
		float	b = 654.24f;
		
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		::swap(a, b);
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		std::cout << ORANGE << "min(a, b) = " << RESET << ::min(a, b) << std::endl;
		std::cout << ORANGE << "max(a, b) = " << RESET << ::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "SWAP THEN MIN/MAX W CHAR" << RESET << std::endl;
		char	a = 'a';
		char	b = 'b';
		
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		::swap(a, b);
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		std::cout << ORANGE << "min(a, b) = " << RESET << ::min(a, b) << std::endl;
		std::cout << ORANGE << "max(a, b) = " << RESET << ::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	{
	std::cout << YELLOW << "SWAP THEN MIN/MAX WITH STRING" << RESET << std::endl;
		std::string	a = "hello";
		std::string	b = "hi";
		
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		::swap(a, b);
		std::cout << ORANGE << "a: " << RESET << a << ORANGE << " b: " << RESET << b << std::endl;
		std::cout << ORANGE << "min(a, b) = " << RESET << ::min(a, b) << std::endl;
		std::cout << ORANGE << "max(a, b) = " << RESET << ::max(a, b) << std::endl;
	}
	return (0);
}
