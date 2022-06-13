/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:26:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/13 16:37:45 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
	private:
		std::string			_name;
		int					_hit_pts;
		int					_en_pts;
		int					_atk_dmg;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=(ClapTrap const &rhs);
		~ClapTrap(void);
		void				attack(const std::string &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		std::string const	getName(void);
		int					getHitPts(void);
		int					getEnergyPts(void);
		int					getAttackPts(void);
};

#endif