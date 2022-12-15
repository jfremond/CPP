/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:58:41 by jfremond          #+#    #+#             */
/*   Updated: 2022/12/14 19:28:50 by jfremond         ###   ########.fr       */
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

		std::cout << "The container contains " << easyfind(lst1, 17) << std::endl;
		try
		{
			std::cout << easyfind(lst1, 28) << std::endl;
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

		std::cout << "The container contains " << easyfind(vec1, 42) << std::endl;
		try
		{
			std::cout << easyfind(vec1, 58) << std::endl;
		}
		catch (const std::exception	&e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	return (0);
}
