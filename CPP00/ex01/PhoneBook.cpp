/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/20 18:34:24 by jfremond         ###   ########.fr       */
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
		if (this->_oldest == 8)
			this->_oldest = 0;
		if (!this->_contacts[this->_oldest].createNewContact(this->_oldest + 1))
			this->_oldest++;
	}
	else
	{
		if (!this->_contacts[this->_nb_contacts].createNewContact(this->_nb_contacts + 1))
			this->_nb_contacts++;
	}
	return ;
}

int	PhoneBook::_displayHeader(void) const
{
	std::string tab_fields[4] = 
	{
		"Index",
		"First name",
		"Last name",
		"Nickname",
	};
	if (this->_nb_contacts == 0)
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

void	PhoneBook::_displaySearchResult(void) const
{
	int 		index;
	std::string input;
	
	std::cout << "Index search : ";
	getline(std::cin, input);
	index = atoi(input.c_str());
	if (input.empty() || !isdigit(input.at(0)))
		std::cout << RED << "Index is not valid" << RESET << std::endl;
	else if (index <= 0 || index > this->_nb_contacts)
		std::cout << RED << "Index is out of range" << RESET << std::endl;
	else
		this->_contacts[index - 1].displayContact();
	return ;
}

void PhoneBook::searchContact(void) const
{
	if (!_displayHeader())
	{	
		_displayContactsInTab();
		_displaySearchResult();	
	}
	return ;
}

