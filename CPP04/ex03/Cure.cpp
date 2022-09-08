/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:06:46 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/08 07:07:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	(*this) = src;
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure			&Cure::operator=(Cure const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

AMateria	*Cure::clone() const
{
	AMateria *newCure = new Cure;
	return (newCure);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds*" << std::endl;
}