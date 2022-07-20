/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:18:48 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/19 00:28:30 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_commands(void)
{
	std::cout << "Possible commands are : "
		<< "[" << CYAN << "ADD" << RESET << "] "
		<< "[" << CYAN << "SEARCH" << RESET << "] "
		<< "[" << CYAN << "EXIT" << RESET << "]" << std::endl;
}

void	print_welcome(void)
{
	std::cout << "Hello and welcome to MyAwesomePhoneBook !" << std::endl;
	print_commands();
}

void	print_goodbye(void)
{
	std::cout << "Thanks for using MyAwesomePhoneBook ! See you around ! :)" << std::endl;
}

int	main(void)
{
	std::string	input;
	PhoneBook	book;
	print_welcome();
	getline(std::cin, input);
	while (!std::cin.eof() && input.compare("EXIT"))
	{
		if (!input.compare("ADD"))
			book.addContact();
		if (!input.compare("SEARCH"))
			book.searchContact();
		if (input.compare("ADD") && input.compare("SEARCH"))
			std::cout << RED << "You have entered a wrong command..." << RESET << std::endl;
		if (!std::cin.eof())
			print_commands();
		getline(std::cin, input);
	}
	print_goodbye();
}
