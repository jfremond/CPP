/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:06:30 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/14 01:05:41 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _index(0)
{
	for (int i = 0; i < 4; i++)
		this->_stuff[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	for (int i = 0; i < src._index; i++)
		this->_stuff[i] = src._stuff[i]->clone();
	for (int i = src._index; i < 4; i++)
		this->_stuff[i] = NULL;
	this->_index = src._index;	
	// this->_index = src._index;
	// // for (int i = 0; i < 4; i++)
	// // 	if (this->_stuff[i])
	// // 		delete this->_stuff[i];
	// for (int i = 0; i < 4; i++)
	// 	this->_stuff[i] = NULL;
	std::cout << "MateriaSource copy constructor called" << std::endl;
	return ;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < this->_index; i++)
		delete this->_stuff[i];
	for (int i = 0; i < rhs._index; i++)
		this->_stuff[i] = rhs._stuff[i]->clone();
	for (int i = rhs._index; i < 4; i++)
		this->_stuff[i] = NULL;
	this->_index = rhs._index;	
	// for (int i = 0; i < 4; i++)
	// 	if (this->_stuff[i])
	// 		delete this->_stuff[i];
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (rhs._stuff[i])
	// 		this->learnMateria(rhs._stuff[i]->clone());
	// }
	// for (int i = 0; i < 4; i++)
	// 	this->_stuff[i] = NULL;
	// this->_index = rhs._index;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_index; i++)
	{
		if (this->_stuff[i])
			delete this->_stuff[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

void			MateriaSource::learnMateria(AMateria *m)
{
	if (this->_index < 4 && m)
	{
		this->_stuff[this->_index++] = m;
		std::cout << GREEN << "Materia learned" << RESET << std::endl;
	}
	else
	{
		if (m)
			delete m;
		std::cout << RED << "Something went wrong, couldn't learn Materia." << RESET <<  std::endl;
	}
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->_index; i++)
	{
		if (this->_stuff[i]->getType() == type && i < 4)
		{
			return (this->_stuff[i]->clone());
		}
	}
	std::cout << RED << "Something went wrong, couldn't create Materia." << RESET << std::endl;
	return (NULL);	
}
