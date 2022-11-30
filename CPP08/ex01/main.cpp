/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:20:33 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/30 03:55:50 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	std::cout << ORANGE << "CREATE A VECTOR AND FILL IT USING ADDNUMBER" << RESET << std::endl;
	Span	vec1(15);
	vec1.addNumber(-14);
	vec1.addNumber(-22);
	vec1.addNumber(74);
	vec1.addNumber(45);
	vec1.addNumber(88);
	vec1.addNumber(90);
	vec1.addNumber(-31);
	vec1.addNumber(-75);
	vec1.addNumber(-60);
	vec1.addNumber(39);
	vec1.addNumber(-84);
	vec1.addNumber(17);
	vec1.addNumber(69);
	vec1.addNumber(-25);
	vec1.addNumber(86);
	vec1.printVec();
	std::cout << std::endl;
	
	std::cout << ORANGE << "CREATE A VECTOR AND FILL IT USING FILLVEC" << RESET << std::endl;
	srand(time(NULL));
	std::vector<int>	tmp_vec;
	for (unsigned int i = 0; i < 15; i++)
	{
		int	val = rand() % 15 + 1;
		tmp_vec.push_back(val);
	}		
	Span	vec2(15);
	vec2.fillVec(tmp_vec.begin(), tmp_vec.end());
	vec2.printVec();
	std::cout << std::endl;
	
	std::cout << ORANGE << "FINDING SPANS OF BOTH VECTORS" << RESET << std::endl;
	std::cout << "Shortest span of vec1 is : " << vec1.shortestSpan() << std::endl;
	std::cout << "Longuest span of vec1 is : "  << vec1.longuestSpan() << std::endl;
	std::cout << "Shortest span of vec2 is : " << vec2.shortestSpan() << std::endl;
	std::cout << "Longuest span of vec2 is : "  << vec2.longuestSpan() << std::endl;
	std::cout << std::endl;
	
	std::cout << ORANGE << "CREATING EMPTY VECTOR AND TRYING TO FILL IT" << RESET << std::endl;
	Span	empty_vec;
	try
	{
		empty_vec.addNumber(-42);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << ORANGE << "TRYING TO FIND SPANS OF EMPTY VECTOR" << RESET << std::endl;
	try
	{
		std::cout << "Shortest span of empty_vec is : " << empty_vec.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::cout << "Longuest span of empty_vec is : " << empty_vec.longuestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	
	std::cout << ORANGE << "TESTING COPY CONSTRUCTION" << RESET << std::endl;
	Span	vec3(vec1);
	vec3.printVec();
	std::cout << std::endl;

	std::cout << ORANGE << "TESTING ASSIGNMENT OPERATOR" << RESET << std::endl;
	Span	vec4 = vec2;
	vec4.printVec();
	
	return (0);
}