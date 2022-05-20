/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/20 13:33:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	compare_with_keyword(std::string str)
{
	int res;
	
	res = -1;
	int	cmp = str.compare("ADD");
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	if (cmp == 0)
	{
		std::cout << "First name : " << std::endl;
		std::cin >> first_name;
		std::cout << "Last name : " << std::endl;
		std::cin >> last_name;
		std::cout << "Nickname : " << std::endl;
		std::cin >> nickname;
		std::cout << "Phone number : " << std::endl;
		std::cin >> phone_number;
		std::cout << "Darkest secret :" << std::endl;
		std::cin >> darkest_secret;
		Contact	test2(first_name, last_name, nickname, phone_number, darkest_secret);
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