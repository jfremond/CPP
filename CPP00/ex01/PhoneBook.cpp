/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 14:11:01 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

void PhoneBook::addContact(void)
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
}

void PhoneBook::showContacts(void)
{
	for (int i = 0; i < this->nb_contacts; i++)
	{
		std::cout << "Contact n°" << i + 1 << std::endl;
		std::cout << "First name : " << this->contacts[i].getFirstName() << std::endl;
		std::cout << "Last name : " << this->contacts[i].getLastName() << std::endl;
		std::cout << "Nickname : " << this->contacts[i].getNickname() << std::endl;
		std::cout << "Phone number : " << this->contacts[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret : " << this->contacts[i].getDarkestSecret() << std::endl;
	}
}

PhoneBook::~PhoneBook(void)
{
}
