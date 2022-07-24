/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:25:08 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/24 18:51:48 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Frank("Frank");
	for (int i = 0; i < 4; i++)
	{
		Frank.attack("a common bot");
		Frank.takeDamage(50);
		Frank.beRepaired(20);
	}
	Frank.highFivesGuys();
	return (0);
}