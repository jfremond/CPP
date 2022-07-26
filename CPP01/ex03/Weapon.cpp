/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:15:25 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/25 12:54:33 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string	const &Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}