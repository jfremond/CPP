/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 11:53:05 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "PhoneBook constructor called" << std::endl;
}

void PhoneBook::addContact(void)
{
	if (this->nb_contacts == 8)
		this->contacts[0].setInfos(this->nb_contacts + 1);
	else
	{
		this->contacts[this->nb_contacts].setInfos(this->nb_contacts + 1);
		this->nb_contacts++;	
	}
	std::cout << this->nb_contacts << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called" << std::endl;
}
