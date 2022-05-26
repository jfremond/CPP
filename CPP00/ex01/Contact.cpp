/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:34:12 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 15:03:43 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->first_name = std::string();
		this->last_name = std::string();
		this->nickname = std::string();
		this->phone_number = std::string();
		this->darkest_secret = std::string();
	}
}

std::string	checkInfos(int index)
{
	std::string	str;
	std::string fields[5] =
	{
		"First name :",
		"Last name :",
		"Nickname :",
		"Phone number :",
		"Darkest secret :"	
	};
	std::cout << fields[index] << std::endl;
	getline(std::cin, str);
	size_t len = 0;
	len = str.length();
	if (len == 0)
		std::cout << "Empty contact not added" << std::endl;
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
	std::cout << "Contact added !" << std::endl;
	return (0);
}


Contact::~Contact(void)
{
}
