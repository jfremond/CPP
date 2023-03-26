/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:40:27 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/26 13:34:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <set>
#include <map>
#include <vector>

int	main(int argc, char **argv)
{
	PmergeMe	test;
	std::vector<int>&	vec = test.getVec();
	if (argc <= 2)
	{
		std::cout << "Error: There's no sequence to sort" << std::endl;
		return (1);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string	str = argv[i];
			if (str.find_first_not_of("0123456789") != std::string::npos)
			{
				std::cout << "Error: Only positive values allowed" << std::endl;
				return (1);
			}
			else
				vec.push_back(test._stod(str));
		}
	}
	test.printVec();
	test.display1();
	//& Print sorted sequence
	//& Print time first container
	//& Print time second container
	return (0);
}