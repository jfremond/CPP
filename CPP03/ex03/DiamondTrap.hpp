/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:27:24 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 18:55:28 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		/* data */
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
};

DiamondTrap::DiamondTrap(void)
{
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name + "_clap_name";
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET << " name constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET << " destructor called" << std::endl;
	return ;
}


#endif