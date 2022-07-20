/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:21:27 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/19 04:02:11 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : nb_contact(0), oldest(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact(void)
{
	if (this->nb_contact == 8)
	{
		if (this->oldest == 8)
			this->oldest = 0;
		if (!this->array[this->oldest].createNewContact(this->oldest + 1))
			this->oldest++;
	}
	else
	{
		if (!this->array[this->nb_contact].createNewContact(this->nb_contact + 1))
		{
			this->nb_contact++;
			this->oldest++;
		}
	}
	return ;
}

int		PhoneBook::displayHeader(void)
{
	std::string	tab_fields[4] =
	{
		"Index",
		"First name",
		"Last name",
		"Nickname",
	};
	if (this->nb_contact == 0)
	{
		std::cout << RED << "Add a contact before searching for one !" << RESET << std::endl;
		return (1);
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << BLUE << std::setw(10) << tab_fields[0] << RESET << "|"
		<< BLUE << std::setw(10) << tab_fields[1] << RESET << "|"
		<< BLUE << std::setw(10) << tab_fields[2] << RESET << "|"
		<< BLUE << std::setw(10) << tab_fields[3] << RESET << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	return (0);
}

void	PhoneBook::displayContactInTab(void)
{
	for (int i = 0; i < this->nb_contact; i++)
	{
		std::cout << "|"
			<< std::setw(10) << std::right << i + 1
			<< "|";
		if (this->array[i].getFirstName().length() > 10)
			std::cout << this->array[i].getFirstName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->array[i].getFirstName() << "|";
		if (this->array[i].getLastName().length() > 10)
			std::cout << this->array[i].getLastName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->array[i].getLastName() << "|";
		if (this->array[i].getNickname().length() > 10)
			std::cout << this->array[i].getNickname().substr(0, 9) << "." << "|" << std::endl;
		else
			std::cout << std::setw(10) << this->array[i].getNickname() << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return ;
}

void	PhoneBook::displaySearchResult(void)
{
	std::string	input;
	int			index;

	std::cout << "Enter index : ";
	getline(std::cin, input);
	index = atoi(input.c_str());
	if (check_if_digit(input))
		std::cout << "Invalid index" << std::endl;
	else if (index < 1 || index > this->nb_contact)
		std::cout << "Index out of range" << std::endl;
	else
		this->array[index - 1].displayContact();
	return ;
}

void	PhoneBook::searchContact(void)
{
	if (!displayHeader())
	{
		displayContactInTab();
		displaySearchResult();
	}
	return ;
}
