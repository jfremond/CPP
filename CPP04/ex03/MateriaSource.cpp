/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:15:14 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/10 04:22:59 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
	std::cout << GREEN << "MateriaSource default destructor called" << RESET << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	(*this) = src;
	std::cout << GREEN << "MateriaSource copy constructor called" << RESET << std::endl;
	return ;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	this->_index = rhs._index;
	for (int i = 0; i < 4; i++)
		this->_array[i] = rhs._array[i];	
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_index; i++)
		delete this->_array[i];
	this->_index = 0;
	std::cout << RED << "MateriaSource destructor called" << RESET << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (this->_index == 3)
	{
		std::cout << "Array full" << std::endl;
		return ;
	}
	this->_array[this->_index++] = m;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->_index; i++)
	{
		if (this->_array[i]->getType() == type)
			return (this->_array[i]->clone());
	}
	return (NULL);	
}
