/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/07 16:00:13 by jfremond         ###   ########.fr       */
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

void	goodbye_message()
{
	std::cout << "Thanks for using MyAwesomePhonebook !" << std::endl;
	std::cout << "See you around ! :)" << std::endl;
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
			book.addContact();
		if (input == "SEARCH")
			book.showContacts();
		if (std::cin.eof() || input == "EXIT")
		{
			goodbye_message();
			loop = 0;
		}
		else
		{
			if (!std::cin.eof() && input != "EXIT" && input != "SEARCH" && input != "ADD")
				std::cout << "\033[31mWrong command entered...\033[0m" << std::endl;
			input = get_input();
		}
	}
	return (0);
}