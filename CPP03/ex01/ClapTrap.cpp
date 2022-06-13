/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:26:38 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/13 15:53:47 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hit_pts(100), _en_pts(50), _atk_dmg(20)
{
	std::cout << "\033[34mClapTrap " << this->_name << " \033[0mconstructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(100), _en_pts(50), _atk_dmg(20)
{
	std::cout << "\033[34mClapTrap " << this->_name << " \033[0mconstructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_en_pts = rhs._en_pts;
	this->_atk_dmg = rhs._atk_dmg;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "\033[34mClapTrap " << this->_name << " \033[0mdestructor called" << std::endl;
	return ;
}

void		ClapTrap::attack(const std::string &target)
{
	if (this->_en_pts == 0)
	{
		std::cout << "\033[34mClapTrap " << this->_name << " \033[0mcouldn't attack " << target
			<< " because they do not have energy points!" << std::endl;
		return ;
	}
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[34mClapTrap " << this->_name << " \033[0mcouldn't attack " << target
			<< " because they're dead!" << std::endl;
		return ;
	}
	else
	{
		std::cout << "\033[34mClapTrap " << this->_name << " \033[0mattacks " << target << ", causing "
			<< this->_hit_pts << " points of damage!" << std::endl;
		this->_en_pts--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[34mClapTrap " << this->_name << " \033[0mis dead, beat it!" << std::endl;
		return ;
	}
	else
	{
		this->_hit_pts -= amount;
		std::cout << "\033[34mClapTrap " << this->_name << " \033[0mtook some damage!" 
			<< " They lost " << amount << " hit points!" << std::endl;
		if (this->_hit_pts < 0)
			this->_hit_pts = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_en_pts == 0)
	{
		std::cout << "\033[34mClapTrap " << this->_name
			<< " \033[0mcouldn't repair themselves because they do not have energy points!"
			<< std::endl;
			return ;
	}
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[34mClapTrap " << this->_name
			<< " \033[0mcouldn't repair themselves because they've passed away!"
			<< std::endl;
			return ;
	}
	if (this->_en_pts > 0)
	{
		this->_hit_pts += amount;
		std::cout << "\033[34mClapTrap " << this->_name << " \033[0mrepaired themselves. "
			<< "They gained " << amount << " hit points! "
			<< "They now have " << this->_hit_pts << " hit points!" << std::endl;
 		this->_en_pts--;
	}
}

std::string const	ClapTrap::getName(void)
{
	return (this->_name);
}
int					ClapTrap::getHitPts(void)
{
	return (this->_hit_pts);
}
int					ClapTrap::getEnergyPts(void)
{
	return (this->_en_pts);
}
int					ClapTrap::getAttackPts(void)
{
	return (this->_atk_dmg);
}
