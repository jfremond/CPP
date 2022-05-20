/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/20 13:05:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	compare_with_keyword(std::string str)
{
	int res;
	res = -1;
	int	cmp = str.compare("ADD");
	if (cmp == 0)
	{
		std::string	test;
		std::cout << "Enter test" << std::endl;
		std::cin >> test;
		Contact	test2(test, test, test, test, test);
		std::cout << "Bye" << std::endl;
		res = 0;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	PhoneBook	test;
//	Contact		test2;
	while (1)
	{
		if (argc == 2)
		{
			
			if (compare_with_keyword(argv[1]))
				std::cout << "Wrong word entered" << std::endl;
			// else
			// 	Contact	test2(argv[1], argv[1], argv[1], argc, argv[1]);
			break ;
		}
		else
		{
			std::cout << "Wrong num of args entered" << std::endl;
			break ;
		}
			
	}
	return (0);
}