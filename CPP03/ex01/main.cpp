/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:57:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/16 09:27:12 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	// Main ClapTrap
	// ClapTrap	clyde("Clyde");
	// for (int i = 0; i < 6; i++)
	// {
	// 	clyde.takeDamage(3);
	// 	clyde.beRepaired(4);
	// 	clyde.attack("a common bot");
	// }
	// std::cout << std::endl;

	// ClapTrap	carl("Carl");
	// carl.takeDamage(10);
	// carl.attack("a common bot");
	// std::cout << std::endl;
	
	ScavTrap	sam("Sam");
	for (int i = 0; i < 26; i++)
	{
		sam.takeDamage(2);
		sam.beRepaired(2);
		sam.attack("a common bot");
	}
	sam.guardGate();
	std::cout << std::endl;
	
	ScavTrap	steve("Steve");
	steve.takeDamage(100);
	steve.attack("a common bot");
	steve.guardGate();
	std::cout << std::endl;
	
	ScavTrap	sylvester("Sylvester");
	sylvester.guardGate();
	sylvester.guardGate();
	std::cout << std::endl;
	
	return (0);
}
