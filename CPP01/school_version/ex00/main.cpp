/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:22:07 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/23 22:06:34 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie brad;
	brad.setName("Brad");
	brad.announce();

	Zombie	*Chad;
	Chad = newZombie("Chad");
	Chad->announce();

	randomChump("Vlad");

	delete Chad;
	return (0);
}