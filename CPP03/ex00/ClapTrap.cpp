/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:26:38 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/13 14:55:53 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("clap-clap"), _hit_pts(10), _en_pts(10), _atk_dmg(0)
{
	std::cout << this->_name << " constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _en_pts(10), _atk_dmg(0)
{
	std::cout << this->_name << " constructor called" << std::endl;
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
	std::cout << this->_name << " destructor called" << std::endl;
	return ;
}

void		ClapTrap::attack(const std::string &target)
{
	if (this->_en_pts == 0)
	{
		std::cout << this->_name << " couldn't attack " << target
			<< " because they do not have energy points!" << std::endl;
		return ;
	}
	if (this->_hit_pts == 0)
	{
		std::cout << this->_name << " couldn't attack " << target
			<< " because they're dead!" << std::endl;
		return ;
	}
	else
	{
		std::cout << this->_name << " attacks " << target << ", causing "
			<< this->_hit_pts << " points of damage!" << std::endl;
		this->_en_pts--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts < amount)
	{
		this->_hit_pts = 0;
		std::cout << this->_name << " is dead, beat it!" << std::endl;
		return ;
	}
	else
	{
		this->_hit_pts -= amount;
		std::cout << this->_name << " took some damage!" 
			<< " They lost " << amount << " hit points!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_en_pts == 0)
	{
		std::cout << this->_name
			<< " couldn't repair themselves because they do not have energy points!"
			<< std::endl;
			return ;
	}
	if (this->_hit_pts == 0)
	{
		std::cout << this->_name
			<< " couldn't repair themselves because they've passed away!"
			<< std::endl;
			return ;
	}
	if (this->_en_pts > 0)
	{
		this->_hit_pts += amount;
		std::cout << this->_name << " repaired themselves. "
			<< "They gained " << amount << " hit points! "
			<< "They now have " << this->_hit_pts << " hit points!" << std::endl;
 		this->_en_pts--;
	}
}
