/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:26:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 18:36:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hit_pts;
		int			_en_pts;
		int			_atk_dmg;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=(ClapTrap const &rhs);
		~ClapTrap(void);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void) const;
		int			getHitPts(void) const;
		int			getEnergyPts(void) const;
		int			getAttackDmg(void) const;
};

#endif