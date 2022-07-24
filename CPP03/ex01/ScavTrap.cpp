/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:39:52 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 21:28:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hit_pts = 100;
	this->_en_pts = 50;
	this->_atk_dmg = 20;
	this->_gatekeep = false;
	std::cout << RED << "ScavTrap " << this->_name << RESET << " default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hit_pts = 100;
	this->_en_pts = 50;
	this->_atk_dmg = 20;
	this->_gatekeep = false;
	std::cout << RED << "ScavTrap " << this->_name << RESET << " name constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << RED << "ScavTrap " << this->_name << RESET << " copy constructor called" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_en_pts = rhs._en_pts;
	this->_atk_dmg = rhs._atk_dmg;
	this->_gatekeep = rhs._gatekeep;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap " << this->_name << RESET << " destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_pts <= 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET << " couldn't attack because they're dead!" << std::endl;
		return ;
	}
	if (this->_en_pts <= 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET << " couldn't attack because they don't have enough energy!" << std::endl;
		return ;
	}
	std::cout << RED << "ScavTrap " << this->_name << RESET << " attacks "
		<< target << ", causing " << this->_atk_dmg << " points of damage!" << std::endl;
	this->_en_pts--;
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (this->_gatekeep == true)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET << " is already in gatekeeping mode!" << std::endl;
		return ;
	}
	this->_gatekeep = true;
	std::cout << RED << "ScavTrap " << this->_name << RESET << " enters gatekeeping mode!" << std::endl;
	return ;
}