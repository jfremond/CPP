/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:38:50 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 16:28:29 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*ptrZombie = new Zombie();
	ptrZombie->setName(name);
	// std::cout << "name : " << ptrZombie->_name << std::endl;
	return (ptrZombie);	
}