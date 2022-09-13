/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:06:30 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 01:00:28 by jfremond         ###   ########.fr       */
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
	(*this) = src;
	std::cout << "MateriaSource copy constructor called" << std::endl;
	return ;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < this->_index; i++)
		if (this->_stuff[i])
			delete this->_stuff[i];
	this->_index = rhs._index;
	for (int i = 0; i < 4; i++)
		this->_stuff[i] = rhs._stuff[i];
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
		std::cout << "Materia Learned" << std::endl;
	}
	else
		std::cout << "Something went wrong, couldn't learn Materia" << std::endl;
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->_index; i++)
	{
		if (this->_stuff[i]->getType() == type)
			return (this->_stuff[i]->clone());
	}
	return (NULL);	
}
