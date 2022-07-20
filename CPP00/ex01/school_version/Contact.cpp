/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:25:30 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/19 04:01:31 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : contact_id(0), first_name(std::string()), last_name(std::string()),
		nickname(std::string()), phone_number(std::string()), darkest_secret(std::string())
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFirstName(void)
{
	return (this->first_name);
}

std::string	Contact::getLastName(void)
{
	return (this->last_name);
}

std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phone_number);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->darkest_secret);
}

int	check_if_digit(std::string str)
{
	for (size_t len = 0; len < str.length(); len++)
	{
		if (!isdigit(str[len]))
		return (1);
	}
	return (0);
}

void	Contact::displayContact(void)
{
	std::cout << YELLOW << std::setw(17) << std::left << "Contact id : " << RESET << this->contact_id << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "First name : " << RESET << this->first_name << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Last name : " << RESET << this->last_name << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Nickname : " << RESET << this->nickname << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Phone number : " << RESET << this->phone_number << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Darkest secret : " << RESET << this->darkest_secret << std::endl;
}

std::string	Contact::checkInfos(int index)
{
	std::string	field;
	std::string	fields[5] =
	{
		"First name : ",
		"Last name : ",
		"Nickname : ",
		"Phone number : ",
		"Darkest Secret : ",
	};
	std::cout << fields[index];
	getline(std::cin, field);
	if (index == 3)
	{
		while (!std::cin.eof() && (check_if_digit(field) || field.length() != 10))
		{
			std::cout << ORANGE << "Phone number not well formated..." << RESET << std::endl;
			std::cout << fields[index];
			getline(std::cin, field);
		}
	}
	size_t	len = field.length();
	if (len == 0)
		std::cout << RED << "Empty contact not added ! " << RESET <<std::endl;
	return (field);
}

int	Contact::createNewContact(int nb_contact)
{
	this->contact_id = nb_contact;
	this->first_name = checkInfos(0);
	if (this->first_name.empty())
		return (1);
	this->last_name = checkInfos(1);
	if (this->last_name.empty())
		return (1);
	this->nickname = checkInfos(2);
	if (this->nickname.empty())
		return (1);
	this->phone_number = checkInfos(3);
	if (this->phone_number.empty())
		return (1);
	this->darkest_secret = checkInfos(4);
	if (this->darkest_secret.empty())
		return (1);
	std::cout << GREEN << "New contact is now added ! " << RESET << std::endl;
	return (0);
}
