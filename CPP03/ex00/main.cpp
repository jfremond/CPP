/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:25:08 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/13 15:18:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap 	clyde("Clyde");
	for (int i = 0; i < 4; i++)
	{
		clyde.attack("a random bot");
		clyde.takeDamage(5);
		clyde.beRepaired(2);
	}
	return (0);
}