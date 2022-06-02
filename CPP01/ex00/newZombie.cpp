/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:38:50 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 16:45:25 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*ptrZombie;
	
	ptrZombie = new Zombie();
	ptrZombie->setName(name);
	return (ptrZombie);	
}