/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:37:17 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/13 17:12:58 by jfremond         ###   ########.fr       */
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
		int			_atk_pts;
		bool		_gatekeep;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap &operator=(ScavTrap const &rhs);
		~ScavTrap(void);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		guardGate(void);
};

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

void	ScavTrap::guardGate(void)
{
	if (this->_gatekeep == true)
	{
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mis already gate keeping!" << std::endl;
		return ;
	}
	else
	{
		this->_gatekeep = true;
		std::cout << "\033[32mScavTrap " << this->_name << " \033[0mhas entered gate keeping mode!" << std::endl;
	}
	return ;
}

#endif