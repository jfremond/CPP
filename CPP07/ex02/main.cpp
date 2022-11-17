/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:16:13 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/12 21:33:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	srand(time(NULL));
	std::cout << ORANGE << "CREATING AN EMPTY ARRAY" << RESET << std::endl;
	Array<int>	empty_arr;
	std::cout << std::endl;
	
	std::cout << ORANGE << "CREATING AN INVALID ARRAY" << RESET << std::endl;
	try
	{
		Array<int>	invalid_arr(-3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << ORANGE << "CREATING AN INT ARRAY" << RESET << std::endl;
	Array<int>	int_arr(10);
	for (int i = 0; i < int_arr.size(); i++)
	{
		int	val = rand() % int_arr.size();
		int_arr[i] = val;
		std::cout << "int_arr[" << i << "]: "<< int_arr[i] << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << ORANGE << "CREATING A STRING ARRAY" << RESET << std::endl;
	std::string str[5] = {"location", "goat", "fire", "borrow", "banana"};
	Array<std::string> str_arr(5);
	for (int i = 0; i < str_arr.size(); i++)
	{
		int	val = rand() % str_arr.size();
		str_arr[i] = str[val];
		std::cout << "str_arr[" << i << "]: "<< str_arr[i] << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << ORANGE << "TESTING COPY CONSTRUCTION" << RESET << std::endl;
	Array<int>	cpy_int_arr(int_arr);
	for (int i = 0; i < cpy_int_arr.size(); i++)
		std::cout << "cpy_int_arr[" << i << "]: "<< cpy_int_arr[i] << std::endl;
	std::cout << std::endl;
	
	std::cout << ORANGE << "TESTING ASSIGNATION OPERATOR" << RESET << std::endl;
	Array<std::string> cpy_str_arr = str_arr;
	for (int i = 0; i < cpy_str_arr.size(); i++)
		std::cout << "cpy_str_arr[" << i << "]: "<< cpy_str_arr[i] << std::endl;
	std::cout << std::endl;
	
	std::cout << ORANGE << "TESTING ACCESSING ELEMENTS" << RESET << std::endl;
	std::cout << "int_arr[4]: " << int_arr[4] << std::endl;
	std::cout << "str_arr[1]: " << str_arr[1] << std::endl;
	try
	{
		std::cout << "cpy_int_arr[10]: " << cpy_int_arr[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "cpy_str_arr[7]: " << cpy_str_arr[7] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}
