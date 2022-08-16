/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:35:15 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/16 01:03:57 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
		bool				_gatekeep;
		static unsigned int	_scavHitPts;
		static unsigned int	_scavEnPts;
		static unsigned int _scavAtkDmg;
		ScavTrap(void);
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap	&operator=(ScavTrap const &rhs);
		~ScavTrap(void);
		void	attack(const std::string &target);
		void	guardGate(void);
		bool	getGatekeep(void) const;
};

std::ostream &operator<<(std::ostream &os, ScavTrap const &obj);

#endif
