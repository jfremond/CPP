/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:42:07 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/20 18:35:33 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	{	
		std::cout << YELLOW << "TRYING WITH A LIST" << RESET << std::endl;
		std::list<int>	lst1;
		
		lst1.push_back(1);
		lst1.push_back(17);
		lst1.push_back(42);

		std::cout << "The container contains " << *easyfind(lst1, 17) << std::endl;
		try
		{
			std::cout << *easyfind(lst1, 28) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl << std::endl;
		}
	}

	{
		std::cout << YELLOW << "TRYING WITH A VECTOR" << RESET << std::endl;
		std::vector<int>	vec1;

		vec1.push_back(1);
		vec1.push_back(17);
		vec1.push_back(42);

		try
		{
			std::cout << *easyfind(vec1, 58) << std::endl;
		}
		catch (const std::exception	&e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "The container contains " << *easyfind(vec1, 42) << std::endl << std::endl;
	}

	{
		std::cout << YELLOW << "TRYING WITH A SET" << RESET << std::endl;
		std::set<int>	set1;
		
		set1.insert(1);
		set1.insert(17);
		set1.insert(42);
		
		try
		{
			std::cout << *easyfind(set1, 63) << std::endl;
		}
		catch (const std::exception	&e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "The container contains " << *easyfind(set1, 1) << std::endl << std::endl;
	}
	return (0);
}
