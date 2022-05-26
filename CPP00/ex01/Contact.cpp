/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:34:12 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 12:59:26 by jfremond         ###   ########.fr       */
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
	// std::cout << "Contact constructor called" << std::endl;
}

int	Contact::setInfos(int num_contact)
{
	this->num_contact = num_contact;
	std::cout << "First name : " << std::endl;
	getline(std::cin, first_name);
	size_t len = 0;
	len = first_name.length();
	if (len == 0)
	{
		std::cout << "Empty contact not added" << std::endl;
		return (1);
	}
	std::cout << "First name added !" << std::endl;
	return (0);
}


Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
}
