/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:07:44 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/25 12:57:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (!this->_weapon || !this->_weapon->getType().length())
		std::cout << this->_name << " doesn't have a weapon to attack with" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
