/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:25:17 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/16 01:03:53 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		static unsigned int	_fragHitPts;
		static unsigned int	_fragEnPts;
		static unsigned int _fragAtkDmg;
		FragTrap(void);
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		FragTrap	&operator=(FragTrap const &rhs);
		~FragTrap(void);
		void	highFivesGuys(void);
};

std::ostream	&operator<<(std::ostream &os, FragTrap const &obj);

#endif
