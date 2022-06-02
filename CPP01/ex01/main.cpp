/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:00:46 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 17:14:13 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		nb_zombies;
	
	nb_zombies = 10;
	horde = zombieHorde(nb_zombies, "zombieHorde");
	for (int i = 0; i < nb_zombies; i++)
		horde->announce();
	delete [] horde;
}