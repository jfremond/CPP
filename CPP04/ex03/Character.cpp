/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:47:34 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/10 04:44:01 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unknown")
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_floor[i] = NULL;
	std::cout << GREEN << "Character default constructor called" << RESET << std::endl;
	return ;
}

Character::Character(std::string const &name) : _name(name)
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_floor[i] = NULL;
	std::cout << GREEN << "Character string constructor called" << RESET << std::endl;
	return ;
}

Character::Character(Character const &src) : _name(src._name)
{
	(*this) = src;
	std::cout << GREEN << "Character copy constructor called" << RESET << std::endl;
	return ;
}

Character	&Character::operator=(Character const &rhs)
{
	this->_index = rhs._index;
	for (int i = 0; i < 4; i++)
		this->_array[i] = rhs._array[i];
	for (int i = 0; i < 4; i++)
		this->_array[i] = rhs._floor[i];
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_array[i])
			delete this->_array[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_floor[i])
			delete this->_floor[i];;
	}
	std::cout << RED << "Character " << this->_name << " destructor called" << RESET << std::endl;
	return ;
}

std::string const	&Character::getName() const
{
	return (this->_name);	
}

void				Character::equip(AMateria* m)
{
	if (this->_index == 4)
	{
		std::cout << "Array of Materia is full" << std::endl;
		return ;
	}
	std::cout << "Materia equipped" << std::endl;
	this->_array[this->_index++] = m;
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		this->_floor[idx] = this->_array[idx];
		this->_array[idx] = NULL;
		this->_index--;
	}
//	else
//		std::cout << "Materia doesn't exist" << std::endl;
}

void				Character::use(int idx, ICharacter& target)
{
	// Rajout de this->_array[idx]
	if (idx >= 0 && idx <= 3 && this->_array[idx])
	{
		this->_array[idx]->use(target);
	}
	else
		std::cout << "Materia doesn't exist therefore it can't be used" << std::endl;
}
