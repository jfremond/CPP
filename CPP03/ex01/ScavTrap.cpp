/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:31:27 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/13 17:46:39 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _name(this->getName()), _hit_pts(this->getHitPts()),
		_en_pts(this->getEnergyPts()), _atk_pts(this->getAttackPts()), _gatekeep(false)
{
	std::cout << "\033[32mScavTrap " << this->_name << " \033[0mconstructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _name(this->getName()), _hit_pts(this->getHitPts()),
		_en_pts(this->getEnergyPts()), _atk_pts(this->getAttackPts()), _gatekeep(false)
{
	std::cout << "\033[32mScavTrap " << this->_name << " \033[0mconstructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "\033[32mScavTrap " << this->_name << " \033[0mcopy constructor called" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_en_pts = rhs._en_pts;
	this->_atk_pts = rhs._atk_pts;	
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[32mScavTrap " << this->_name << " \033[0mdestructor called" << std::endl;
	return ;
}

void		ScavTrap::attack(const std::string &target)
{
	if (this->_en_pts == 0)
	{
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mcouldn't attack " << target
			<< " because they do not have energy points!" << std::endl;
		return ;
	}
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mcouldn't attack " << target
			<< " because they're dead!" << std::endl;
		return ;
	}
	else
	{
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mattacks " << target << ", causing "
			<< this->_hit_pts << " points of damage!" << std::endl;
		this->_en_pts--;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mis dead, beat it!" << std::endl;
		return ;
	}
	else
	{
		this->_hit_pts -= amount;
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mtook some damage!" 
			<< " They lost " << amount << " hit points!" << std::endl;
		if (this->_hit_pts < 0)
			this->_hit_pts = 0;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_en_pts == 0)
	{
		std::cout << "\033[32mScavTrap " << this->_name
			<< " \033[0mcouldn't repair themselves because they do not have energy points!"
			<< std::endl;
			return ;
	}
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[32mScavTrap " << this->_name
			<< " \033[0mcouldn't repair themselves because they've passed away!"
			<< std::endl;
			return ;
	}
	if (this->_en_pts > 0)
	{
		this->_hit_pts += amount;
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mrepaired themselves. "
			<< "They gained " << amount << " hit points! "
			<< "They now have " << this->_hit_pts << " hit points!" << std::endl;
 		this->_en_pts--;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_gatekeep == true)
	{
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mis already in gate keeping mode!" << std::endl;
		return ;
	}
	else
	{
		this->_gatekeep = true;
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mhas entered gate keeping mode!" << std::endl;
	}
	return ;
}