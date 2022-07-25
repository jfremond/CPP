/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:34:12 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/25 19:50:22 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _contact_id(0), _first_name(std::string()), _last_name(std::string()),
		_nickname(std::string()), _phone_number(std::string()), _darkest_secret(std::string())
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

// Getters
std::string Contact::getFirstName(void) const
{
	return (this->_first_name);
}

std::string Contact::getLastName(void) const
{
	return (this->_last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);	
}

void	Contact::displayContact() const
{
	std::cout << YELLOW << std::setw(17) << std::left << "Contact id : " << RESET << this->_contact_id << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "First name : " << RESET << this->_first_name << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Last name : " << RESET << this->_last_name << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Nickname : " << RESET << this->_nickname << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Phone number : " << RESET << this->_phone_number << std::endl;
	std::cout << YELLOW << std::setw(17) << std::left << "Darkest secret : " << RESET << this->_darkest_secret << std::endl;
	return ;
}

std::string	Contact::checkInfos(int index)
{
	std::string	field;
	std::string fields[5] =
	{
		"First name : ",
		"Last name : ",
		"Nickname : ",
		"Phone number : ",
		"Darkest secret : "	
	};
	std::cout << fields[index];
	getline(std::cin, field);
	if (index == 3)
	{
		while (!std::cin.eof() && (check_if_digit(field) || field.length() != 10))
		{
			std::cout << ORANGE << "Phone number not well formated... (only 10 numbers allowed)" << RESET << std::endl;
			std::cout << fields[index];
			getline(std::cin, field);
		}
	}	
	size_t len = field.length();
	if (len == 0)
		std::cout << RED << "Empty contact not added ! " << RESET <<std::endl;
	return (field);
}

int	Contact::createNewContact(int contact_id)
{
	this->_contact_id = contact_id;
	this->_first_name = checkInfos(0);
	if (this->_first_name.empty())
		return (1);
	this->_last_name = checkInfos(1);
	if (this->_last_name.empty())
		return (1);
	this->_nickname = checkInfos(2);
	if (this->_nickname.empty())
		return (1);
	this->_phone_number = checkInfos(3);
	if (this->_phone_number.empty())
		return (1);
	this->_darkest_secret = checkInfos(4);
	if (this->_darkest_secret.empty())
		return (1);
	std::cout << GREEN << "New contact is now added ! " << RESET << std::endl;
	return (0);
}

int	Contact::check_if_digit(std::string field)
{
	for (size_t i = 0; i < field.length(); i++)
	{
		if (!isdigit(field[i]))
			return (1);
	}
	return (0);
}

