/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:50:29 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 21:52:41 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hit_pts = 100;
	this->_en_pts = 100;
	this->_atk_dmg = 30;
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_pts = 100;
	this->_en_pts = 100;
	this->_atk_dmg = 30;
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " name constructor called" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " destructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " copy constructor called" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_en_pts = rhs._en_pts;
	this->_atk_dmg = rhs._atk_dmg;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GREEN << "FragTrap " << this->_name << RESET << " does a high five!" << std::endl;	
}