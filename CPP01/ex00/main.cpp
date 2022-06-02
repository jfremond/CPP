/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:13:48 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 16:41:57 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie;
	zombie.setName("Foo");
	zombie.announce();
	
	Zombie	*ptrZombie = newZombie("ptrZombie");
	ptrZombie->announce();
	
	randomChump("Random");
	
	delete ptrZombie;
	return (0);
}