/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/24 19:29:07 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact	store_new_contact(Contact contact)
{
	std::string add;

	std::cout << "Enter first name : " << std::endl;
	getline(std::cin, add);
	contact.setFirstName(add);
	std::cout << "Enter last name : " << std::endl;
	getline(std::cin, add);
	contact.setLastName(add);
	std::cout << "Enter nickname : " << std::endl;
	getline(std::cin, add);
	contact.setNickname(add);
	std::cout << "Enter phone number : " << std::endl;
	getline(std::cin, add);
	contact.setPhoneNumber(add);
	std::cout << "Enter darkest secret : " << std::endl;
	getline(std::cin, add);
	contact.setDarkestSecret(add);
	return (contact);
}

int	main(void)
{
	PhoneBook	contacts[8];
	Contact	contact;
	std::string input;
	
	std::cout << "Welcome to MyAwesomePhoneBook !" << std::endl;
	std::cout << "Type ADD to add a contact, SEARCH to search a contact, " << std::endl;
	std::cout << "and EXIT to exit the program" << std::endl;
	while (1)
	{
		getline(std::cin, input);
		if (input == "ADD")
		{
			contact = store_new_contact(contact);
			contact.display();
		}
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
			input = "EXIT";
		if (input == "EXIT")
		{
			std::cout << "bye" << std::endl;	
			break;
		}
		std::cout << "Type ADD to add a contact, SEARCH to search a contact, " << std::endl;
		std::cout << "and EXIT to exit the program" << std::endl;
	}
	return (0);
}