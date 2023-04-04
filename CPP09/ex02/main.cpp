/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:40:27 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/03 22:29:34 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <limits>

int	main(int argc, char **argv)
{
	PmergeMe	seq;
	std::vector<int>&	vec = seq.getVec();
	try
	{
		if (argc <= 2)
			throw PmergeMe::WrongUsage();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	
	try
	{
		std::string	str;
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			if (str.find_first_not_of("0123456789") != std::string::npos)
				throw PmergeMe::ForbiddenCharacters();
			else if (seq._stod(str) > std::numeric_limits<int>::max())
				throw PmergeMe::BiggerThanInt();
			else
			{
				try
				{
					vec.push_back(seq._stod(str));
				}
				catch(const std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	try
	{
		// seq.printVec();
		seq.display1();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}	
	//& Print sorted sequence
	//& Print time first container
	//& Print time second container
	return (0);
}