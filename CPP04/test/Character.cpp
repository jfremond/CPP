/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:43:50 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 00:40:53 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unknown")
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
	{
		this->_stuff[i] = NULL;
		this->_floor[i] = NULL;
	}
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(std::string const name) : _name(name)
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
	{
		this->_stuff[i] = NULL;
		this->_floor[i] = NULL;
	}
	std::cout << "Character " << this->_name << " string constructor called" << std::endl;
	return ;
}

Character::Character(Character const &src) : _name(src._name)
{
	(*this) = src;
	std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character	&Character::operator=(Character const &rhs)
{
	for (int i = 0; i < this->_index; i++)
	{
		if (this->_stuff[i])
			delete this->_stuff[i];
		if (this->_floor[i])
			delete this->_floor[i];
	}
	this->_index = rhs._index;
	for (int i = 0; i < this->_index; i++)
	{
		this->_stuff[i] = rhs._stuff[i];
		this->_floor[i] = rhs._floor[i];
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < this->_index; i++)
	{
		if (this->_stuff[i])
			delete this->_stuff[i];
		if (this->_floor[i])
			delete this->_floor[i];
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
		this->_stuff[this->_index++] = m;
		std::cout << "Materia equipped" << std::endl;
	}
	else
		std::cout << "Can't equip a Materia that doesn't exist" << std::endl;
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->_stuff[idx])
	{
		this->_floor[idx] = this->_stuff[idx];
		this->_stuff[idx] = NULL;
		this->_index--;
		std::cout << "Materia unequipped" << std::endl;
	}
	else
		std::cout << "Can't unequip a Materia that doesn't exist" << std::endl;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && this->_stuff[idx])
	{
		this->_stuff[idx]->use(target);
		std::cout << "Attack used" << std::endl;
	}
	else
		std::cout << "Something went wrong. Couldn't attack " << target.getName();
}