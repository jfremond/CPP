/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:57:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/12 05:19:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	fran("Francis");
	for (int i = 0; i < 51; i++)
	{
		fran.takeDamage(2);
		fran.beRepaired(2);
		fran.attack("a common bot");
	}
	fran.highFivesGuys();
	std::cout << std::endl;

	FragTrap	felix("Felix");
	felix.takeDamage(100);
	felix.beRepaired(2);
	felix.attack("a common bot");
	felix.highFivesGuys();
	std::cout << std::endl;

	FragTrap	finn("Finn");
	finn.highFivesGuys();
	finn.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}
