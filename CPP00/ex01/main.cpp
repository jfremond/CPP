/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/20 11:23:23 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	compare_with_keyword(std::string str)
{
	int res;
	res = -1;
	int	cmp = str.compare("EXIT");
	if (cmp == 0)
	{
		std::cout << "Bye" << std::endl;
		res = 0;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	PhoneBook	test;
	Contact		test2;
	while (1)
	{
		if (argc == 2)
		{
			
			if (compare_with_keyword(argv[1]))
				std::cout << "Wrong word entered" << std::endl;
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