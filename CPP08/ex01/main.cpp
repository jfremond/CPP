/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:20:33 by jfremond          #+#    #+#             */
/*   Updated: 2022/12/14 19:29:04 by jfremond         ###   ########.fr       */
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
	
	std::cout << ORANGE << "CREATE A VECTOR AND FILL IT USING FILLVEC (printed in file vec2)" << RESET << std::endl;
	Span	vec2(15000);
	std::list<int>	lst;
	
	srand(time(NULL));		
	for (unsigned int i = 0; i < 15000; i++)
	{
		int	val = rand() % 15000 + 1;
		lst.push_back(val);
	}	
	vec2.fillVec(lst.begin(), lst.end());
	vec2.printVecInFile("vec2");
	
	std::cout << ORANGE << "FINDING SPANS OF BOTH VECTORS" << RESET << std::endl;
	std::cout << "Shortest span of vec1 is : " << vec1.shortestSpan() << std::endl;
	std::cout << "Longest span of vec1 is : "  << vec1.longestSpan() << std::endl;
	std::cout << "Shortest span of vec2 is : " << vec2.shortestSpan() << std::endl;
	std::cout << "Longest span of vec2 is : "  << vec2.longestSpan() << std::endl;
	std::cout << std::endl;
	
	std::cout << ORANGE << "CREATING VECTOR TOO SMALL AND TRYING TO FILL IT" << RESET << std::endl;
	Span	vec_too_small(10);
	std::cout << ORANGE << "TRYING TO FIND SPANS OF VECTOR TOO SMALL" << RESET << std::endl;
	try
	{
		std::cout << "Shortest span of vec_too_small is : " << vec_too_small.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	vec_too_small.addNumber(-42);
	try
	{
		std::cout << "Longest span of vec_too_small is : " << vec_too_small.longestSpan() << std::endl;
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

	std::cout << ORANGE << "TESTING ASSIGNMENT OPERATOR (results printed in file vec4)" << RESET << std::endl;
	Span	vec4 = vec2;
	vec4.printVecInFile("vec4");
	
	return (0);
}