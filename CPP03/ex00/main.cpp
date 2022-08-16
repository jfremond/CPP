/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:57:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/12 00:48:44 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clyde("Clyde");
	for (int i = 0; i < 6; i++)
	{
		clyde.takeDamage(3);
		clyde.beRepaired(4);
		clyde.attack("a common bot");
	}
	std::cout << std::endl;

	ClapTrap	carl("Carl");
	carl.takeDamage(10);
	carl.attack("a common bot");
	std::cout << std::endl;
	
	return (0);
}
