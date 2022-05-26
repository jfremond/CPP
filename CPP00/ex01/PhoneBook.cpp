/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:36:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 11:35:22 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "PhoneBook constructor called" << std::endl;
}

void PhoneBook::addContact(void)
{
	this->contacts[this->nb_contacts].setInfos(this->nb_contacts + 1);
	this->nb_contacts++;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called" << std::endl;
}
