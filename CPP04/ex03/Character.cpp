/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:43:50 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/15 23:35:47 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unknown")
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_stuff[i] = NULL;
	this->_floor = NULL;
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(std::string const name) : _name(name)
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_stuff[i] = NULL;
	this->_floor = NULL;
	std::cout << "Character " << this->_name << " string constructor called" << std::endl;
	return ;
}

Character::Character(Character const &src)
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_stuff[i] = NULL;
	for (int i = 0; i < 4; i++)
		if (src._stuff[i])
			this->equip(src._stuff[i]->clone());
	this->_name = src._name;
	this->_index = src._index;
	this->_floor = src._floor;
	std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character	&Character::operator=(Character const &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_stuff[i]; 
		this->_stuff[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
		if (rhs._stuff[i])
			this->equip(rhs._stuff[i]->clone());
	this->_index = rhs._index;
	this->_name = rhs._name;
	this->_floor = rhs._floor;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_stuff[i])
			delete this->_stuff[i];
	}
	std::cout << "Character " << this->_name << " destructor called" << std::endl;
	return ;
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void				Character::equip(AMateria *m)
{
	if (this->_index < 4 && m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_stuff[i] == m)
			{
				std::cout << RED << "Something went wrong. Couldn't equip Materia." << RESET << std::endl;
				return ;
			}
		}
		this->_stuff[this->_index++] = m;
		std::cout << GREEN << "Materia equipped" << RESET << std::endl;
	}
	else
		std::cout << RED << "Something went wrong. Couldn't equip Materia." << RESET << std::endl;
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->_stuff[idx] != NULL)
	{
		this->_floor = this->_stuff[idx];
		this->_stuff[idx] = NULL;
		this->_index--;
		std::cout << GREEN << "Materia unequipped" << RESET << std::endl;
	}
	else
		std::cout << RED << "Something went wrong. Couldn't unequip Materia." << RESET << std::endl;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && this->_stuff[idx])
	{
		this->_stuff[idx]->use(target);
		std::cout << GREEN << "Attack used" << RESET << std::endl;
	}
	else
		std::cout << RED << "Something went wrong. Couldn't attack " << target.getName() << "." <<  RESET << std::endl;
}

void	Character::cleanFloor()
{
	if (this->_floor)
	{
		delete this->_floor;
		this->_floor = NULL;
	}
}
