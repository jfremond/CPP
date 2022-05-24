/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:34:12 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/24 22:02:15 by jfremond         ###   ########.fr       */
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


Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
}
