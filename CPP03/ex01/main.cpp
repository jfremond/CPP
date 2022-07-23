/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:25:08 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/23 23:50:57 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	// ClapTrap 	clyde("Clyde");
	// for (int i = 0; i < 4; i++)
	// {
	// 	clyde.attack("a random bot");
	// 	clyde.takeDamage(5);
	// 	clyde.beRepaired(2);
	// }
	ScavTrap	scarlett("Scarlett");
	for (int i = 0; i < 4; i++)
	{
		scarlett.attack("a common bot");
		scarlett.takeDamage(50);
		scarlett.beRepaired(20);
	}
	scarlett.guardGate();
	scarlett.guardGate();
	return (0);
}