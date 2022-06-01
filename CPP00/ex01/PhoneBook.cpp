/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/01 17:55:25 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : nb_contacts(0), oldest(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(void)
{
	if (this->nb_contacts == 8)
	{
		if (!this->contacts[this->oldest].setInfos(this->nb_contacts + 1))
			this->oldest++;
		if (this->oldest == 8)
			this->oldest = 0;
	}
	else
	{
		if (!this->contacts[this->nb_contacts].setInfos(this->nb_contacts + 1))
			this->nb_contacts++;	
	}
	return ;
}

static int	check_if_digit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (1);
	}
	return (0);
}

int	PhoneBook::displayHeader(void) const
{
	std::string fields[4] = 
	{
		"\033[34mIndex\033[0m",
		"\033[34mFirst name\033[0m",
		"\033[34mLast name\033[0m",
		"\033[34mNickname\033[0m",
	};
	if (this->nb_contacts == 0)
	{
		std::cout << "\033[31mAdd a contact before searching for one !\033[0m" << std::endl;
		std::cout << std::endl;
		return (1);
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     " << fields[0] << "|" << fields[1] << "| " << fields[2] << "|  " << fields[3] << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	return (0);
}

void PhoneBook::displayContactsInTab(void) const
{
	for (int i = 0; i < this->nb_contacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		if (this->contacts[i].getFirstName().length() > 10)
			std::cout << this->contacts[i].getFirstName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->contacts[i].getFirstName();
		std::cout << "|";
		if (this->contacts[i].getLastName().length() > 10)
			std::cout << this->contacts[i].getLastName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->contacts[i].getLastName();
		std::cout << "|";
		if (this->contacts[i].getNickname().length() > 10)
			std::cout << this->contacts[i].getNickname().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->contacts[i].getNickname();
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return ;
}

void	PhoneBook::displayContactByIndex(void) const
{
	int index = 0;
	std::string contact;
	std::cout << "Index search : ";
	getline(std::cin, contact);
	if (!check_if_digit(contact))
	{		
		std::istringstream(contact) >> index;
		if (index <= 0 || index > this->nb_contacts)
			std::cout << "\033[31mIndex out of range\033[0m" << std::endl << std::endl;
		else
			this->contacts[index - 1].display();
	}
	else
		std::cout << "\033[31mIndex is not valid\033[0m" << std::endl << std::endl;
	return ;
}

void PhoneBook::showContacts(void) const
{
	if (!displayHeader())
	{	
		displayContactsInTab();
		displayContactByIndex();	
	}
	return ;
}

