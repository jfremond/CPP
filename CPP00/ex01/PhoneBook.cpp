/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 13:19:51 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

void PhoneBook::addContact(void)
{
	if (this->nb_contacts == 3)
	{
		this->contacts[this->oldest].setInfos(this->nb_contacts + 1);
		this->oldest++;
		if (this->oldest == 3)
			this->oldest = 0;
	}
	else
	{
		this->contacts[this->nb_contacts].setInfos(this->nb_contacts + 1);
		this->nb_contacts++;	
	}
}

void PhoneBook::showContacts(void)
{
	for (int i = 0; i < this->nb_contacts; i++)
		std::cout << "First name : " << this->contacts[i].getFirstName() << std::endl;
}

PhoneBook::~PhoneBook(void)
{
}
