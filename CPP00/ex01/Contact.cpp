/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:34:12 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/30 11:13:25 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->num_contact = 0;
	this->first_name = std::string();
	this->last_name = std::string();
	this->nickname = std::string();
	this->phone_number = std::string();
	this->darkest_secret = std::string();
	return ;
}

Contact::~Contact(void)
{
}

// Setters
void		Contact::setFirstName(std::string val)
{
	this->first_name = val;
}

void		Contact::setLastName(std::string val)
{
	this->last_name = val;
}

void		Contact::setNickname(std::string val)
{
	this->nickname = val;
}

void		Contact::setPhoneNumber(std::string val)
{
	this->phone_number = val;
}

void		Contact::setDarkestSecret(std::string val)
{
	this->darkest_secret = val;
}

// Getters
std::string Contact::getFirstName(void)
{
	return (this->first_name);
}

std::string Contact::getLastName(void)
{
	return (this->last_name);
}

std::string Contact::getNickname(void)
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->phone_number);
}

std::string Contact::getDarkestSecret(void)
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

void	Contact::display()
{
	std::cout << std::setw(27) << std::left << "\033[33mNumber : \033[0m" << this->num_contact << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mFirst name : \033[0m" << this->first_name << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mLast name : \033[0m" << this->last_name << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mNickname : \033[0m" << this->nickname << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mPhone number : \033[0m" << this->phone_number << std::endl;
	std::cout << std::setw(27) << std::left << "\033[33mDarkest secret : \033[0m" << this->darkest_secret << std::endl;
	return ;
}

