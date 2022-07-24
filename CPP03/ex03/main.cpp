/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:25:08 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 23:10:28 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Diams("Diams");
	for (int i = 0; i < 4; i++)
	{
		Diams.attack("a common bot");
		Diams.takeDamage(50);
		Diams.beRepaired(20);
	}
	Diams.guardGate();
	Diams.highFivesGuys();
	Diams.whoAmI();
	return (0);
}