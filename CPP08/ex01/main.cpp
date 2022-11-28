/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:20:33 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/28 19:25:51 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	srand(time(NULL));
	std::cout << ORANGE << "CREATE A VECTOR AND FILL IT USING ADDNUMBER" << RESET << std::endl;
	Span	vec1(12);
	for (unsigned int i = 0; i < 12; i++)
	{
		vec1.addNumber(i);
	}
	vec1.printVec();
	std::cout << std::endl;
	std::cout << ORANGE << "CREATE A VECTOR AND FILL IT USING FILLVEC" << RESET << std::endl;
	std::vector<int>	tmp_vec;
	for (unsigned int i = 0; i < 15000; i++)
	{
		int	val = rand() % 15000;
		tmp_vec.push_back(val);
	}
		
	Span	vec2(20000);
	vec2.fillVec< std::vector<int> >(tmp_vec.begin(), tmp_vec.end());
	vec2.printVec();
	std::cout << ORANGE << "FINDING SPANS OF BOTH VECTORS" << RESET << std::endl;
	std::cout << "Shortest span of vec1 is : " << vec1.shortestSpan() << std::endl;
	std::cout << "Longuest span of vec1 is : "  << vec1.longuestSpan() << std::endl;
	std::cout << "Shortest span of vec2 is : " << vec2.shortestSpan() << std::endl;
	std::cout << "Longuest span of vec2 is : "  << vec2.longuestSpan() << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	std::cout << ORANGE << "" << RESET << std::endl;
	return (0);
}