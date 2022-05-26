/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 23:40:50 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	get_input()
{
	std::string	input;
	
	std::cout << "Type ADD to add a contact, SEARCH to search a contact, " << std::endl;
	std::cout << "and EXIT to exit the program" << std::endl;
	getline(std::cin, input);
	return (input);
}

int	main(void)
{
	PhoneBook	book;
	std::string input;
	int			loop = 1;
	
	std::cout << "Welcome to MyAwesomePhoneBook !" << std::endl;
	input = get_input();
	while (loop)
	{
		if (input == "ADD")
		{
			book.addContact();
			input = get_input();
		}
		if (input == "SEARCH")
		{
			book.showContacts();
			input = get_input();
		}
		if (!std::cin.eof() && input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			input = get_input();
		}
		if (std::cin.eof() || input == "EXIT")
		{
			std::cout << "Thanks for using MyAwesomePhonebook !" << std::endl;
			std::cout << "See you around ! :)" << std::endl;	
			loop = 0;
		}
	}
	return (0);
}