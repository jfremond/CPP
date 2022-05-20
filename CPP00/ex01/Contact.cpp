/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:34:12 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/20 13:06:06 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) :
			first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret)
{
	this->first_name = first_name;
	std::cout << "First name : " <<  this->first_name << std::endl;
	this->last_name = last_name;
	std::cout << "Last name : " <<  this->last_name << std::endl;
	this->nickname = nickname;
	std::cout << "Nickname : " <<  this->nickname << std::endl;
	this->phone_number = phone_number;
	std::cout << "Phone number : " <<  this->phone_number << std::endl;
	this->darkest_secret = darkest_secret;
	std::cout << "Darkest secret: " <<  this->darkest_secret << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
}
