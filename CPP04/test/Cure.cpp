/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:26:02 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 00:41:45 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	(*this) = src;
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure		&Cure::operator=(Cure const &rhs)
{
	(void)rhs;
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
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
