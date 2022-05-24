/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/24 19:16:38 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact	store_new_contact(Contact contact)
{
	std::string add;
			
	getline(std::cin, add);
	contact.setFirstName(add);
	getline(std::cin, add);
	contact.setLastName(add);
	getline(std::cin, add);
	contact.setNickname(add);
	getline(std::cin, add);
	contact.setPhoneNumber(add);
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
	}
	return (0);
}