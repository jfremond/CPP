/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:43:52 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 18:39:46 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	private:
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		FragTrap &operator=(FragTrap const &rhs);
		~FragTrap(void);
		void	highFivesGuys(void);
};

#endif