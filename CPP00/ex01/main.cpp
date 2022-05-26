/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 16:08:31 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	book;
	Contact		contact;
	std::string input;
	int			loop = 1;
	
	std::cout << "Welcome to MyAwesomePhoneBook !" << std::endl;
	std::cout << "Type ADD to add a contact, SEARCH to search a contact, " << std::endl;
	std::cout << "and EXIT to exit the program" << std::endl;
	getline(std::cin, input);
	while (loop)
	{
		if (!std::cin.eof() && input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			std::cout << "Type ADD to add a contact, SEARCH to search a contact, " << std::endl;
			std::cout << "and EXIT to exit the program" << std::endl;
			getline(std::cin, input);
		}
		if (input == "ADD")
			book.addContact();
		if (input == "SEARCH")
			book.showContacts();
		if (std::cin.eof() || input == "EXIT")
		{
			std::cout << "Thanks for using MyAwesomePhonebook !" << std::endl;
			std::cout << "See you around ! :)" << std::endl;	
			loop = 0;
		}
	}
	return (0);
}