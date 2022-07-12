/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:43:07 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/14 12:17:19 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string	_name;
		int			_hit_pts;
		int			_en_pts;
		int			_atk_dmg;
		bool		_gatekeep;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap &operator=(ScavTrap const &rhs);
		~ScavTrap(void);
		void	attack(const std::string &target);
		void	guardGate(void);
};

ScavTrap::ScavTrap(void) : ClapTrap(), _name(this->getName()), _hit_pts(this->getHitPts()),
	_en_pts(this->getEnergyPts()), _atk_dmg(this->getAttackDmg()), _gatekeep(false)
{
	std::cout << RED << "ScavTrap " << this->_name << RESET << " default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _name(this->getName()), _hit_pts(this->getHitPts()),
	_en_pts(this->getEnergyPts()), _atk_dmg(this->getAttackDmg()), _gatekeep(false)
{
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
	// this->_hit_pts = getHitPts();
	if (this->_hit_pts == 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << RESET << " couldn't attack because they're dead!" << std::endl;
		return ;
	}
	if (this->_en_pts == 0)
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

#endif