/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:47:34 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/09 00:53:54 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_name = "unknown";
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
	std::cout << "Character string constructor called" << std::endl;
	return ;
}

Character::Character(Character const &src)
{
	(*this) = src;
	std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character	&Character::operator=(Character const &rhs)
{
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
		this->_array[i] = rhs._array[i];
	return (*this);
}

Character::~Character()
{
	std::cout << "Character " << this->_name << " destructor called" << std::endl;
	return ;
}

std::string const	&Character::getName() const
{
	return (this->_name);	
}

void				Character::equip(AMateria* m)
{
	if (this->_index == 3)
	{
		std::cout << "Array of Materia is full" << std::endl;
		return ;
	}
	std::cout << m->getType() << " Materia equipped" << std::endl;
	this->_array[this->_index++] = m;
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		this->_array[idx] = NULL;
		this->_index--;
	}
	else
		std::cout << "Materia doesn't exist" << std::endl;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		this->_array[idx]->use(target);
	}
	else
		std::cout << "Materia doesn't exist therefor it can't be used" << std::endl;
}