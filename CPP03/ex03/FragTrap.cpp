/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:34:57 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/12 05:16:58 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int	FragTrap::_fragHitPts = 100;
unsigned int	FragTrap::_fragEnPts = 100;
unsigned int	FragTrap::_fragAtkDmg = 30;

FragTrap::FragTrap(void)
{
	this->_hitPts = FragTrap::_fragHitPts;
	this->_enPts = FragTrap::_fragEnPts;
	this->_atkDmg = FragTrap::_fragAtkDmg;
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = FragTrap::_fragHitPts;
	this->_enPts = FragTrap::_fragEnPts;
	this->_atkDmg = FragTrap::_fragAtkDmg;
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " name constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src)
{
	(*this) = src;
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " copy constructor called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	this->_hitPts = rhs._hitPts;
	this->_enPts = rhs._enPts;
	this->_atkDmg = rhs._atkDmg;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	if (!this->_name.c_str())
		return ;
	if (this->_hitPts == 0)
	{
		std::cout << GREEN << "FragTrap " << this->_name << RESET
			<< " is dead, therefore it can't request a highfive!"  << std::endl;
		return ;
	}
	if (this->_enPts == 0)
	{
		std::cout << GREEN << "FragTrap " << this->_name << RESET
			<< " has no energy left, therefore it can't request a highfive!" << std::endl;
		return ;
	}
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " requests a highfive!" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, FragTrap const &obj)
{
	os << "name: " << obj.getName() << std::endl;
	os << "hitPts: " << obj.getHitPts() << std::endl;
	os << "enPts: " << obj.getEnPts() << std::endl;
	os << "atkDmg: " << obj.getAtkDmg() << std::endl;
	return (os);
}
