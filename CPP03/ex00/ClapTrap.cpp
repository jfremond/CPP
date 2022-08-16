/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:58:47 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/10 00:23:59 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("CT"), _hitPts(10), _enPts(10), _atkDmg(0)
{
	std::cout << BLUE << "ClapTrap " << this->_name << RESET << " default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPts(10), _enPts(10), _atkDmg(0)
{
	std::cout << BLUE << "ClapTrap " << this->_name << RESET << " name constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	(*this) = src;
	std::cout << BLUE << "ClapTrap " << this->_name << RESET << " copy constructor called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name =  rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_enPts = rhs._enPts;
	this->_atkDmg = rhs._atkDmg;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE << "ClapTrap " << this->_name << RESET << " destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->_name.c_str())
		return ;
	if (this->_hitPts == 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name << RESET
			<< " is dead, therefore " << target << " wasn't attacked!" << std::endl;
		return ;
	}
	if (this->_enPts == 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name << RESET
			<< " has no energy left, therefore " << target << " wasn't attacked!" << std::endl;
		return ;
	}
	std::cout << BLUE << "ClapTrap " << this->_name << RESET
		<< " attacks " << target << ", causing " << this->_atkDmg << " points of damage!" << std::endl;
	this->_enPts--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_name.c_str())
		return ;
	if (this->_hitPts == 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name << RESET
			<< " is dead already, stop attacking it!" <<  std::endl;
		return ;
	}
	if (amount > this->_hitPts)
		this->_hitPts = 0;
	else
		this->_hitPts -= amount;
	std::cout << BLUE << "ClapTrap " << this->_name << RESET
		<< " took " << amount << " points of damage. "
		<< "It now has " << this->_hitPts << " hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_name.c_str())
		return ;
	if (this->_hitPts == 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name << RESET
			<< " is dead, therefore it can't repair itself!" <<  std::endl;
		return ;
	}
	if (this->_enPts == 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name << RESET
			<< " has no energy left, therefore it can't repair itself!" << std::endl;
		return ;
	}
	this->_hitPts += amount;
	std::cout << BLUE << "ClapTrap " << this->_name << RESET
		<< " gained " << amount << " hit points, "
		<< "it now has " << this->_hitPts << " hit points!" << std::endl;
	this->_enPts--;
}
