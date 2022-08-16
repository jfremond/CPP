/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:57:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/16 00:19:52 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diams("Diams");
	for (int i = 0; i < 25; i++)
	{
		diams.takeDamage(2);
		diams.beRepaired(2);
		diams.attack("a common bot");
	}
	diams.guardGate();
	diams.highFivesGuys();
	diams.whoAmI();
	std::cout << std::endl;

	DiamondTrap	david("David");
	david.takeDamage(100);
	david.attack("a common bot");
	david.guardGate();
	david.highFivesGuys();
	david.whoAmI();
	std::cout << std::endl;

	DiamondTrap delta("Delta");
	delta.guardGate();
	delta.guardGate();
	delta.highFivesGuys();
	delta.whoAmI();
	std::cout << std::endl;
	
	return (0);
}
