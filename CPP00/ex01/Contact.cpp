/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:34:12 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/01 17:55:31 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : num_contact(0), first_name(std::string()), last_name(std::string()),
		nickname(std::string()), phone_number(std::string()), darkest_secret(std::string())
{
	return ;
}

Contact::~Contact(void)
{
}

// Getters
std::string Contact::getFirstName(void) const
{
	return (this->first_name);
}

std::string Contact::getLastName(void) const
{
	return (this->last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);	
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

std::string	checkInfos(int index)
{
	std::string	str;
	std::string fields[5] =
	{
		"First name : ",
		"Last name : ",
		"Nickname : ",
		"Phone number : ",
		"Darkest secret : "	
	};
	std::cout << fields[index];
	getline(std::cin, str);
	if (index == 3)
	{
		while (check_if_digit(str))
		{
			std::cout << "\033[36mPhone number is not well formatted...\033[m" << std::endl;
			std::cout << fields[index];
			getline(std::cin, str);
		}
	}	
	size_t len = str.length();
	if (len == 0 || std::cin.eof())
		std::cout << "\033[36mEmpty contact not added !\033[m" << std::endl;
	return (str);
}

int	Contact::setInfos(int num_contact)
{
	this->num_contact = num_contact;
	first_name = checkInfos(0);
	if (first_name.empty())
		return (1);
	last_name = checkInfos(1);
	if (last_name.empty())
		return (1);
	nickname = checkInfos(2);
	if (nickname.empty())
		return (1);
	phone_number = checkInfos(3);
	if (phone_number.empty())
		return (1);
	darkest_secret = checkInfos(4);
	if (darkest_secret.empty())
		return (1);
	std::cout << "\033[32mContact added !\033[0m" << std::endl << std::endl;
	return (0);
}

void	Contact::display() const
{
	std::cout << std::setw(27) << std::left << "\033[33mNumber : \033[0m" << this->num_contact << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mFirst name : \033[0m" << this->first_name << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mLast name : \033[0m" << this->last_name << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mNickname : \033[0m" << this->nickname << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mPhone number : \033[0m" << this->phone_number << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mDarkest secret : \033[0m" << this->darkest_secret << std::endl << std::endl;
	return ;
}

