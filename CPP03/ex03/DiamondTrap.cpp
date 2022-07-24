/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:34:07 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 23:10:06 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_name = ClapTrap::_name + "_clap_name";
	this->_hit_pts = getHitPts();
	this->_en_pts = getEnPts();
	this->_atk_dmg = getAtkDmg();
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET << " default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	this->_name = name + "_clap_name";
	this->_hit_pts = getHitPts();
	this->_en_pts = getEnPts();
	this->_atk_dmg = getAtkDmg();
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET << " name constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->_name = src._name;
	this->_hit_pts = src._hit_pts;
	this->_en_pts = src._en_pts;
	this->_atk_dmg = src._atk_dmg;
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_en_pts = rhs._en_pts;
	this->_atk_dmg = rhs._atk_dmg;
	return (*this);
}


DiamondTrap::~DiamondTrap(void)
{
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET << " destructor called" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << YELLOW << this->_name << RESET << std::endl;
	std::cout << "My ClapTrap name is " << BLUE << ClapTrap::_name << RESET << std::endl;
}