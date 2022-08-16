/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:57:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/12 00:48:39 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
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
