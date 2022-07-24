/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:31:53 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 21:37:25 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		/* data */
	public:
		DiamondTrap(void);
		~DiamondTrap(void);
};

DiamondTrap::DiamondTrap(void)
{
	std::cout << "ft_hit_pts: 100"
		<< "st_en_pts: 100"
		<< "ft_atk_pts: 30" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	return ;
}


#endif