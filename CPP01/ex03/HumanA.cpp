/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:07:11 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/25 22:08:12 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack(void)
{
	if (!this->_weapon.getType().length())
		std::cout << this->_name << " doesn't have a weapon to attack with" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}
