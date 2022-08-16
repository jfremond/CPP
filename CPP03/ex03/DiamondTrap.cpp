/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 05:32:43 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/16 09:45:43 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_hitPts = FragTrap::_fragHitPts;
	this->_enPts = ScavTrap::_scavEnPts;
	this->_atkDmg = FragTrap::_fragAtkDmg;
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET
		<< " default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") // Utilse sinon appel des 3 autres constructeurs par défaut
{
	this->_name = name;
	this->_hitPts = FragTrap::_fragHitPts;
	this->_enPts = ScavTrap::_scavEnPts;
	this->_atkDmg = FragTrap::_fragAtkDmg;
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET
		<< " name constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	(*this) = src;
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET
		<< " copy constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET
		<< " destructor called" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_enPts = rhs._enPts;
	this->_atkDmg = rhs._atkDmg;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (!this->_name.c_str())
		return ;
	if (this->_hitPts == 0)
	{
		std::cout << YELLOW << "DiamondTrap " << this->_name << RESET
			<< " is dead, therefore it can't display its names!"  << std::endl;
		return ;
	}
	if (this->_enPts == 0)
	{
		std::cout << YELLOW << "DiamondTrap " << this->_name << RESET
			<< " has no energy left, therefore it can't display its names!" << std::endl;
		return ;
	}
	std::cout << "Hello ! My name is " << YELLOW << this->_name << RESET
		<< " and my clap name is " << YELLOW << ClapTrap::_name << RESET << std::endl;
	this->_enPts--;
}

std::ostream	&operator<<(std::ostream &os, DiamondTrap const &obj)
{
	os << "name: " << obj.getName() << std::endl;
	os << "hitPts: " << obj.getHitPts() << std::endl;
	os << "enPts: " << obj.getEnPts() << std::endl;
	os << "atkDmg: " << obj.getAtkDmg() << std::endl;
	return (os);
}
