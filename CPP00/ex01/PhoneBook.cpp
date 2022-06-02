/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 12:54:42 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nb_contacts(0), _oldest(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(void)
{
	if (this->_nb_contacts == 8)
	{
		if (!this->_contacts[this->_oldest].setInfos(this->_nb_contacts + 1))
			this->_oldest++;
		if (this->_oldest == 8)
			this->_oldest = 0;
	}
	else
	{
		if (!this->_contacts[this->_nb_contacts].setInfos(this->_nb_contacts + 1))
			this->_nb_contacts++;	
	}
	return ;
}

int	PhoneBook::_displayHeader(void) const
{
	std::string fields[4] = 
	{
		"\033[34mIndex\033[0m",
		"\033[34mFirst name\033[0m",
		"\033[34mLast name\033[0m",
		"\033[34mNickname\033[0m",
	};
	if (this->_nb_contacts == 0)
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

void PhoneBook::_displayContactsInTab(void) const
{
	for (int i = 0; i < this->_nb_contacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		if (this->_contacts[i].getFirstName().length() > 10)
			std::cout << this->_contacts[i].getFirstName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contacts[i].getFirstName();
		std::cout << "|";
		if (this->_contacts[i].getLastName().length() > 10)
			std::cout << this->_contacts[i].getLastName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contacts[i].getLastName();
		std::cout << "|";
		if (this->_contacts[i].getNickname().length() > 10)
			std::cout << this->_contacts[i].getNickname().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contacts[i].getNickname();
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return ;
}

void	PhoneBook::_displayContactByIndex(void) const
{
	int index = 0;
	std::string contact;
	std::cout << "Index search : ";
	getline(std::cin, contact);
	index = atoi(contact.c_str());
	if (contact.empty() || !isdigit(contact.at(0)))
		std::cout << "\033[31mIndex is not valid\033[0m" << std::endl << std::endl;
	else if (index <= 0 || index > this->_nb_contacts)
		std::cout << "\033[31mIndex out of range\033[0m" << std::endl << std::endl;
	else
		this->_contacts[index - 1].display();
	return ;
}

void PhoneBook::showContacts(void) const
{
	if (!_displayHeader())
	{	
		_displayContactsInTab();
		_displayContactByIndex();	
	}
	return ;
}

