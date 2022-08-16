/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:29:04 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/12 03:07:52 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int	ScavTrap::_scavHitPts = 100;
unsigned int	ScavTrap::_scavEnPts = 50;
unsigned int	ScavTrap::_scavAtkDmg = 20;

ScavTrap::ScavTrap(void) : _gatekeep(false)
{
	this->_hitPts = ScavTrap::_scavHitPts;
	this->_enPts = ScavTrap::_scavEnPts;
	this->_atkDmg = ScavTrap::_scavAtkDmg;
	std::cout << RED << "ScavTrap " << this->_name << RESET << " default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gatekeep(false)
{
	this->_hitPts = ScavTrap::_scavHitPts;
	this->_enPts = ScavTrap::_scavEnPts;
	this->_atkDmg = ScavTrap::_scavAtkDmg;
	std::cout << RED << "ScavTrap " << this->_name << RESET << " name constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	(*this) = src;
	std::cout << RED << "ScavTrap " << this->_name << RESET << " copy constructor called" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_enPts = rhs._enPts;
	this->_atkDmg = rhs._atkDmg;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap " << this->_name << RESET << " destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->_name.c_str())
		return ;
	if (this->_hitPts == 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET
			<< " is dead, therefore " << target << " wasn't attacked!" << std::endl;
		return ;
	}
	if (this->_enPts == 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET
			<< " has no energy left, therefore " << target << " wasn't attacked!" << std::endl;
		return ;
	}
	std::cout << RED << "ScavTrap " << this->_name << RESET
		<< " attacks " << target << ", causing " << this->_atkDmg << " points of damage!" << std::endl;
	this->_enPts--;
}

void	ScavTrap::guardGate(void)
{
	if (!this->_name.c_str())
		return ;
	if (this->_hitPts == 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET
			<< " is dead, therefore it can't enter gatekeeping mode!"  << std::endl;
		return ;
	}
	if (this->_enPts == 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET
			<< " has no energy left, therefore it can't enter gatekeeping mode!" << std::endl;
		return ;
	}
	if (this->_gatekeep == true)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET << " is already in gatekeeping mode!" << std::endl;
		return ;
	}
	std::cout << RED << "ScavTrap " << this->_name << RESET << " is entering gatekeeping mode!" << std::endl;
	this->_gatekeep = true;
}

bool	ScavTrap::getGatekeep(void) const
{
	return (this->_gatekeep);
}

std::ostream &operator<<(std::ostream &os, ScavTrap const &obj)
{
	os << "name: " << obj.getName() << std::endl;
	os << "hitPts: " << obj.getHitPts() << std::endl;
	os << "enPts: " << obj.getEnPts() << std::endl;
	os << "atkDmg: " << obj.getAtkDmg() << std::endl;
	os << "gatekeep: " << obj.getGatekeep();
	return (os);
}
